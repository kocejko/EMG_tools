#include "configuredialog.h"
#include <QMessageBox>

ConfigureDialog::ConfigureDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//Set the minimum and close button of the main frame.
    this->setWindowFlags(Qt::WindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint));

	connect(ui.cmbDevice, SIGNAL(currentIndexChanged(int)), this, SLOT(DeviceChanged(int)));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(ButtonOKClicked()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(ButtonCancelClicked()));

	//Set the maximum value of clock rate per channel 500MHz = 500000000.
	ui.edtClockRatePerChan->setValidator(new QDoubleValidator(1, 500000000, 2, this));

	Initailization();
}

ConfigureDialog::~ConfigureDialog()
{

}

void ConfigureDialog::Initailization()
{
	BufferedAiCtrl *bufferedAiCtrl = AdxBufferedAiCtrlCreate();
	ICollection<DeviceTreeNode> *supportedDevice = bufferedAiCtrl->getSupportedDevices();

	if (supportedDevice->getCount() == 0)
	{
		QMessageBox::information(this, tr("Warning Information"), 
			tr("No device to support the currently demonstrated function!"));
		QCoreApplication::quit();
	}
	else
	{
		for (int i = 0; i < supportedDevice->getCount(); i++)
		{
			DeviceTreeNode const &node = supportedDevice->getItem(i);
			qDebug("%d, ls%\n", node.DeviceNumber, node.Description);
			ui.cmbDevice->addItem(QString::fromWCharArray(node.Description));
		}
		ui.cmbDevice->setCurrentIndex(0);
	}

	bufferedAiCtrl->Dispose();
	supportedDevice->Dispose();
}

void ConfigureDialog::CheckError(ErrorCode errorCode)
{
	if (errorCode >= 0xE0000000 && errorCode != Success)
	{
		QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
			QString::number(errorCode, 16).right(8).toUpper();
		QMessageBox::information(this, "Warning Information", message);
	}
}

void ConfigureDialog::DeviceChanged(int index)
{
	ui.cmbChannelCount->clear();
	ui.cmbChannelStart->clear();
	ui.cmbValueRange->clear();

	std::wstring description = ui.cmbDevice->currentText().toStdWString();
	DeviceInformation selected(description.c_str());
	BufferedAiCtrl *bufferedAiCtrl = AdxBufferedAiCtrlCreate();

	ErrorCode errorCode = bufferedAiCtrl->setSelectedDevice(selected);
	ui.btnOK->setEnabled(true);
	if (errorCode != 0){
		QString str;
		QString des = QString::fromStdWString(description);
		str.sprintf("Error:the error code is 0x%x\n\
The %s is busy or not exit in computer now.\n\
Select other device please!", errorCode, des.toUtf8().data());
		QMessageBox::information(this, "Warning Information", str);
		ui.btnOK->setEnabled(false);
		return;
	}

	int channelCount = (bufferedAiCtrl->getChannelCount() < 16) ? 
		bufferedAiCtrl->getChannelCount() : 16;
	int logicChannelCount = bufferedAiCtrl->getChannelCount();

	for (int i = 0; i < logicChannelCount; i++)
	{
		ui.cmbChannelStart->addItem(QString("%1").arg(i));
	}

	for (int i = 0; i < channelCount; i++)
	{
		ui.cmbChannelCount->addItem(QString("%1").arg(i + 1));
	}

	ICollection<ValueRange> *ValueRanges = bufferedAiCtrl->getFeatures()->getValueRanges();
	wchar_t			vrgDescription[128];
	MathInterval	ranges[128];
	ValueUnit		valueUnit;
	for(int i = 0; i < ValueRanges->getCount(); i++)
	{
		errorCode = AdxGetValueRangeInformation(ValueRanges->getItem(i), 
			sizeof(vrgDescription), vrgDescription, &ranges[i], &valueUnit);
		CheckError(errorCode);

		//we filter the Celsius degree for the buffered AI can not support this function.
		if (valueUnit == CelsiusUnit)
		{
			continue;
		}

		QString str = QString::fromWCharArray(vrgDescription);
		ui.cmbValueRange->addItem(str);
	}

	bufferedAiCtrl->Dispose();

	//Set the default value.
	ui.cmbChannelStart->setCurrentIndex(0);
	ui.cmbChannelCount->setCurrentIndex(2);
	ui.cmbValueRange->setCurrentIndex(0);
}

void ConfigureDialog::ButtonOKClicked()
{
	if (ui.cmbDevice->count() == 0)
	{
		QCoreApplication::quit();
	}

	double clockRate = ui.edtClockRatePerChan->text().toDouble();
	if (clockRate < 1)
	{
		QMessageBox::information(this, tr("Warning Information"), 
			tr("Sorry, the clock rate per channel is invalid"));
		return;
	}

	std::wstring description = ui.cmbDevice->currentText().toStdWString();
	DeviceInformation selected(description.c_str());
	BufferedAiCtrl *bufferedAiCtrl = AdxBufferedAiCtrlCreate();

	ErrorCode errorCode = bufferedAiCtrl->setSelectedDevice(selected);
	CheckError(errorCode);

	ICollection<ValueRange> *ValueRanges = bufferedAiCtrl->getFeatures()->getValueRanges();

	configure.deviceName = ui.cmbDevice->currentText();
	configure.channelCount = ui.cmbChannelCount->currentText().toInt();
	configure.channelStart = ui.cmbChannelStart->currentText().toInt();
	configure.valueRange = ValueRanges->getItem(ui.cmbValueRange->currentIndex());
	configure.clockRatePerChan = ui.edtClockRatePerChan->text().toDouble();

	bufferedAiCtrl->Dispose();
	this->accept();
}

void ConfigureDialog::ButtonCancelClicked()
{
	this->reject();
}
