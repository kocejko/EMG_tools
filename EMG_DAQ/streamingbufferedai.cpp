#include "streamingbufferedai.h"
#include <QMessageBox>
#include <QPalette>
#include <QListWidgetItem>
#include <qmath.h>
#include <QColor>
#include <QColorDialog>

AI_StreamingBufferedAi::AI_StreamingBufferedAi(QWidget *parent, Qt::WindowFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	//Set the minimum and close button of the main frame.
    this->setWindowFlags(Qt::WindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint));

	//Set the background image for the main frame.
	this->setAutoFillBackground(true);
	QPixmap pixMap(":/AI_StreamingBufferedAi/Resources/Background.png");
	QPalette backPalette;
	backPalette.setBrush(this->backgroundRole(), QBrush(pixMap));
	this->setPalette(backPalette);

	graph = new SimpleGraph(ui.graphFrame);
	graph->setFixedSize(ui.graphFrame->size());

	timeUnit = Millisecond;
	sectionLengthPerChan = 0;
	rawDataBufferLength = 0;
	scaledData = NULL;

	dataReadyHandler.owner = this;
	overrunHandler.owner = this;
	cacheOverflowHandler.owner = this;
	stoppedHander.owner = this;

	bufferedAiCtrl = AdxBufferedAiCtrlCreate();
	bufferedAiCtrl->addDataReadyListener(dataReadyHandler);
	bufferedAiCtrl->addOverrunListener(overrunHandler);
	bufferedAiCtrl->addCacheOverflowListener(cacheOverflowHandler);
	bufferedAiCtrl->addStoppedListener(stoppedHander);

	connect(ui.btnConfigure, SIGNAL(clicked()), this, SLOT(ButtonConfigureClicked()));
	connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(ButtonStartClicked()));
	connect(ui.btnPause, SIGNAL(clicked()), this, SLOT(ButtonPauseClicked()));
	connect(ui.btnStop, SIGNAL(clicked()), this, SLOT(ButtonStopClicked()));
    connect(ui.sldDiv, SIGNAL(valueChanged(int)), this, SLOT(DivValueChanged(int)));

    timer = new QTimer(this);
    rest_timer = new QTimer(this);
    t_sec = 0;

    connect(timer, SIGNAL(timeout()), this, SLOT(ontick()));
    connect(rest_timer, SIGNAL(timeout()), this, SLOT(onRestTimerTick()));
    //timer->start(1000);
    zapis = false;
}

AI_StreamingBufferedAi::~AI_StreamingBufferedAi()
{
	if (bufferedAiCtrl != NULL)
	{
		bufferedAiCtrl->Dispose();
		bufferedAiCtrl = NULL;
	}

	if (scaledData != NULL)
	{
		delete []scaledData;
		scaledData = NULL;
	}
}

void AI_StreamingBufferedAi::Initialize()
{
	setWindowTitle(tr("Streaming AI - Run(") + configure.deviceName + tr(")"));

	ConfigureDevice();
	ConfigureGraph();
	InitializeList();

	ui.btnConfigure->setEnabled(true);
	ui.btnStart->setEnabled(true);
	ui.btnPause->setEnabled(false);
	ui.btnStop->setEnabled(false);
	ui.sldDiv->setEnabled(true);
}

void AI_StreamingBufferedAi::ConfigureDevice()
{
	ErrorCode errorCode = Success;
	if (scaledData != NULL)
	{
		delete []scaledData;
		scaledData = NULL;
	}

	/**
	* in order to keep drawing 'sectionsCount' times in a second, we set 'sampleRatePerChan'
	* value to buffer length for each channel and divide buffer for each channel by 'sectionsCount'. 
	* users can set 'SectionCount' according to demand.
	*/
	sectionLengthPerChan = configure.clockRatePerChan / sectionCount;
	rawDataBufferLength = sectionLengthPerChan * configure.channelCount * sectionCount;

	scaledData = new double[rawDataBufferLength];
	if (scaledData == NULL)
	{
		QMessageBox::information(this, tr("Warning Information"), 
			tr("Sorry! Error in allocating memory...."));
		return;
	}

	// Select a device with AccessWrite/AccessWriteWithReset mode with device number 
	// or device description.
	std::wstring description = configure.deviceName.toStdWString();
	DeviceInformation selected(description.c_str());

	errorCode = bufferedAiCtrl->setSelectedDevice(selected);
	CheckError(errorCode);

	//Set the streaming mode.
	errorCode = bufferedAiCtrl->setStreaming(true);
	CheckError(errorCode);
	
	errorCode = bufferedAiCtrl->getScanChannel()->setChannelCount(configure.channelCount);
	CheckError(errorCode);

	errorCode = bufferedAiCtrl->getScanChannel()->setChannelStart(configure.channelStart);
	CheckError(errorCode);

	errorCode = bufferedAiCtrl->getScanChannel()->setSamples(configure.clockRatePerChan);
	CheckError(errorCode);
	
	errorCode = bufferedAiCtrl->getScanChannel()->setIntervalCount(sectionLengthPerChan);
	CheckError(errorCode);

	errorCode = bufferedAiCtrl->getConvertClock()->setRate(
		configure.clockRatePerChan);
	CheckError(errorCode);

	for (int i = 0; i < bufferedAiCtrl->getChannels()->getCount(); i++)
	{
		errorCode = bufferedAiCtrl->getChannels()->getItem(i).setValueRange(configure.valueRange);
		CheckError(errorCode);
	}

	errorCode = bufferedAiCtrl->Prepare();
	CheckError(errorCode);
}

void AI_StreamingBufferedAi::ConfigureGraph()
{
	double clockRate = bufferedAiCtrl->getConvertClock()->getRate();
	timeUnit = Millisecond;
	ui.sldDiv->setMaximum(100000000);
	ui.sldDiv->setMinimum(0);
	int divValue = (int)(1.0 * 100 * graph->rect().width() / clockRate);

	if (clockRate >= 10 * 1000) //us
	{
		divValue = (int)(1.0 * 100 * graph->rect().width() / (clockRate / 1000));
		timeUnit = Microsecond;
	}
   if (clockRate >= 10 * 1000 * 1000) //ns
   {
      divValue = (int)(1.0 * 100 * graph->rect().width() / (clockRate / 1000000));
      timeUnit = Nanosecond;
   }
	ui.sldDiv->setMaximum(4 * divValue);
	int divMin = divValue / 10;
	if (divMin == 0)
	{
		divMin = 1;
	}
	ui.sldDiv->setMinimum(divMin);
	ui.sldDiv->setValue(divValue);

	graph->m_xCordTimeDiv = divValue;
	
	SetXCord();

	ValueUnit unit;
	MathInterval rangeY;
	QString yRanges[3] = {tr("")};
	ErrorCode errorCode = AdxGetValueRangeInformation(configure.valueRange, 0, NULL, 
		&rangeY, &unit);
	CheckError(errorCode);
	
	graph->GetYCordRange(yRanges, rangeY.Max, rangeY.Min, unit);
	ui.lblYCoordinateMax->setText(yRanges[0]);
	ui.lblYCoordinateMin->setText(yRanges[1]);
	ui.lblYCoordinateMid->setText(yRanges[2]);
	if (Milliampere == unit || Millivolt == unit)
	{
		rangeY.Max /= 1000;
		rangeY.Min /= 1000;
	}

	graph->m_yCordRangeMax = rangeY.Max;
	graph->m_yCordRangeMin = rangeY.Min;
	graph->Clear();
}

void AI_StreamingBufferedAi::InitializeList()
{
	ui.listWidget->clear();
	QListWidgetItem *item = NULL;
    int stch = configure.channelStart;
    for (int i = stch; i < configure.channelCount; i++)
	{
		item = new QListWidgetItem(tr(""), ui.listWidget);
		item->setBackgroundColor(SimpleGraph::lineColor[i]);
		item->setSizeHint(QSize(54, 21));
	}
}

void AI_StreamingBufferedAi::CheckError(ErrorCode errorCode)
{
	if (errorCode != Success)
	{
		QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
			QString::number(errorCode, 16).right(8);
		QMessageBox::information(this, "Warning Information", message);

		ButtonConfigureClicked();
	}
}

void AI_StreamingBufferedAi::SetXCord()
{
	graph->m_xCordTimeDiv = (double)ui.sldDiv->value();
	QString xRanges[2] = {tr("")};

	double shiftMaxValue = qRound(graph->m_xCordTimeDiv * 10 + graph->m_xCordTimeOffset);
	graph->GetXCordRange(xRanges, shiftMaxValue, graph->m_xCordTimeOffset, timeUnit);
	ui.lblXCoordinateStart->setText(xRanges[1]);
	ui.lblXCoordinateEnd->setText(xRanges[0]);
}

void AI_StreamingBufferedAi::DataHandler(void *sender, BfdAiEventArgs *args)
{
    ((BufferedAiCtrl*)sender)->GetData(args->Count, scaledData);

    //tu zapis do pliku
    if(zapis)
    {
        QString ecg = ui.lineEdit->text()+".txt";
        QString cnap = ui.lineEdit->text()+"_cnap.txt";

        //rawDataBufferLength = sectionLengthPerChan * configure.channelCount * sectionCount;

        if(configure.channelCount == 2)
        {
            QString dane_ecg;
            QString dane_cnap;
            QString dane_all;

            for(int i=0;i<sectionLengthPerChan*configure.channelCount;i+=2)
            {
                if(ui.checkBox->isChecked())
                {
                    dane_ecg.append(QString::number(scaledData[i])+"\r\n");
                    dane_cnap.append(QString::number(scaledData[i+1])+"\r\n");
                }
                else
                {
                    dane_ecg.append(QString::number(scaledData[i])+";");
                    dane_cnap.append(QString::number(scaledData[i+1])+";");
                }
            }

            saveDataToFile(ecg,dane_ecg,true);
            saveDataToFile(cnap,dane_cnap,true);
        }
        else
        {

            QString dane;
            for(int i=0;i<sectionLengthPerChan*configure.channelCount;i++)
            {
                if(ui.checkBox->isChecked())
                {                    
                    if (i%configure.channelCount==0)
                    {
                        dane.append("\n");
                    }
                    dane.append(QString::number(scaledData[i])+";");
                }
                else
                {
                    if (i%configure.channelCount==0)
                    {
                        dane.append("\n");
                    }
                    dane.append(QString::number(scaledData[i])+";");
                }
            }
            saveDataToFile(ecg,dane,true);


/*
            for(int j=0;j<sectionLengthPerChan;j++)
            {
                QString dane;
                for(int i=0;i<configure.channelCount;i++)
                {
                    if(ui.checkBox->isChecked())
                    {
                        dane.append(QString::number(scaledData[i])+":");
                    }
                    else
                    {
                        dane.append(QString::number(scaledData[i])+";");
                    }
                }
                dane.append("\n");
                saveDataToFile(ecg,dane,true);
            }
            //saveDataToFile(ecg,dane,true);
*/

        }
        //qDebug()<<sectionLengthPerChan;
        //qDebug()<<configure.channelCount<<";"<<configure.channelStart;


    }

//    qDebug()<<"Start";

//    qDebug()<<configure.channelCount;
//    int k = 1;
//    int roznica = configure.channelCount-configure.channelStart;
//    for(int i=0;i<sectionLengthPerChan*configure.channelCount;i+=roznica)
//    {

////        scaledDataPrint[k] = scaledData[i];

////        k++;
//        //qDebug()<<k;
//        for(int j = configure.channelStart;j<configure.channelCount; j++)
//        {
//            scaledDataPrint[k] = scaledData[i+j];
//            k++;
//        }
//    }

//    qDebug()<<"koniec";
//
    //qDebug()<<args->Count;
    graph->Chart(scaledData, configure.channelCount, args->Count /
        configure.channelCount, 1.0 / configure.clockRatePerChan);
//    graph->Chart(scaledDataPrint, configure.channelCount-configure.channelStart, args->Count /
    //        configure.channelCount, 1.0 / configure.clockRatePerChan);
}

void AI_StreamingBufferedAi::ontick()
{
    t_sec+=100;
    ui.label_2->setText(QString::number(ui.spinBox->value()-t_sec));
    //ui.progressBar->setValue(t_sec);

    int value = this->ui.progressBar->value();
    ui.progressBar->setValue(value+10);

    if(t_sec == ui.spinBox->value())
    {
        on_pushButton_clicked();
    }
    //qDebug()<<t_sec;
}

void AI_StreamingBufferedAi::onRestTimerTick()
{
    if(ui.spinBox_2->value()>0)
    {
        r_sec+=1;
//    if(r_sec%2 == 0)
//    {
        if(ui.checkBox_2->isChecked())
        {
            on_pushButton_clicked();
            //QString qss = QString("background-color: %1").arg(col.name());
            ui.pushButton_2->setStyleSheet("background-color: green");
        }
    }
//    }
}

void AI_StreamingBufferedAi::DivValueChanged(int value)
{
	graph->Div(value);

	SetXCord();
}


void AI_StreamingBufferedAi::ButtonConfigureClicked()
{
	int resultDialog = configureDialog->exec();
	if (resultDialog == QDialog::Accepted)
	{
		configure = configureDialog->GetConfigureParameter();
		Initialize();
	}
}

void AI_StreamingBufferedAi::ButtonStartClicked()
{
	ui.btnConfigure->setEnabled(false);
	ui.btnStart->setEnabled(false);
	ui.btnPause->setEnabled(true);
	ui.btnStop->setEnabled(true);

	ErrorCode errorCode = bufferedAiCtrl->Start();
	CheckError(errorCode);
}

void AI_StreamingBufferedAi::ButtonPauseClicked()
{
	ErrorCode errorCode = bufferedAiCtrl->Stop();
    CheckError(errorCode);

	ui.btnStart->setEnabled(true);
	ui.btnPause->setEnabled(false);
	ui.btnStop->setEnabled(true);
}

void AI_StreamingBufferedAi::ButtonStopClicked()
{
	ErrorCode errorCode = bufferedAiCtrl->Stop();
    CheckError(errorCode);

	graph->Clear();

	ui.btnConfigure->setEnabled(true);
	ui.btnStart->setEnabled(true);
	ui.btnPause->setEnabled(false);
	ui.btnStop->setEnabled(false);
}
void AI_StreamingBufferedAi::saveDataToFile(QString fname, QString data, bool append)
{
    //const unsigned long size = data.size();
    FILE *pFile;
    if(append)
    {
        pFile = fopen(fname.toLocal8Bit().constData(), "ab");
    }
    else
    {
        pFile = fopen(fname.toLocal8Bit().constData(), "wb");
    }
    fwrite (data.toLocal8Bit().constData() , sizeof(char), data.size()*sizeof(char), pFile);
    fclose (pFile);
}

void AI_StreamingBufferedAi::on_pushButton_clicked()
{
    ui.progressBar->setMaximum(ui.spinBox->value()/10);
    zapis =!zapis;
    qDebug()<<"zapis = "<<zapis;
    if(zapis)
    {
        rest_timer->stop();
        QString ecg = ui.lineEdit->text()+".txt";
        saveDataToFile(ecg,"\n",true);
        saveDataToFile(ecg,"#",true);

        ui.checkBox->setDisabled(true);
        ui.spinBox->setDisabled(true);
        ui.pushButton->setText("Saving...");
        qDebug()<<"zapisuje...";
        timer->start(100);
        ui.progressBar->setValue(0);
        if(ui.spinBox_2->value()>=0)
        {
            ui.spinBox_2->setValue(ui.spinBox_2->value()-1);
        }

    }
    if(!zapis)
    {
        if(ui.checkBox_2->isChecked())
        {
            rest_timer->start(1000*ui.spinBox_3->value());
            ui.pushButton_2->setStyleSheet("background-color: red");
        }
        ui.checkBox->setEnabled(true);
        ui.spinBox->setEnabled(true);
        ui.pushButton->setText("Save");
        qDebug()<<"nie zapisuje...";
        timer->stop();
        t_sec = 0;
    }
}
