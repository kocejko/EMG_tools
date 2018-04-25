#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MYDEVICE_ADD "00:12:6F:26:42:F8"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    localDevice = new QBluetoothLocalDevice(this);
    // Check if Bluetooth is available on this device
        if (!localDevice->isValid()) {
                    QMessageBox::critical(this, "Erreur fatale","Bluetooth local inactif!");
                    return;
                    }

        //if(localDevice->)
        // Turn Bluetooth on
        localDevice->powerOn();

        // Read local device name
        localDeviceName = localDevice->name();

        // Make it visible to others
        //localDevice->setHostMode(QBluetoothLocalDevice::HostDiscoverable);

        // Create a discovery agent and connect to its signals


    m_deviceAgent = new QBluetoothDeviceDiscoveryAgent();
    connect(m_deviceAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    connect(m_deviceAgent, SIGNAL(finished()), this, SLOT(scanFinished()));


    //m_deviceAgent->start();
    //ui->pushButton_4->setDisabled(true);

    /*
    bsocket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    connect(bsocket, SIGNAL(error(QBluetoothSocket::SocketError)), this, SLOT(socketError(QBluetoothSocket::SocketError)));
    connect(bsocket, SIGNAL(connected()), this, SLOT(socketConnected()));
    connect(bsocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(bsocket, SIGNAL(readyRead()), this, SLOT(socketRead()));
    */

    newFrame = false;
    newECGdata = false;

    ui->widget->addGraph();

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTIck()));

    //timer->start(1000);
}
void MainWindow::pairingDone(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing)
{
    //QList<QListWidgetItem *> items = ui->list->findItems(address.toString(), Qt::MatchContains);

    if (pairing == QBluetoothLocalDevice::Paired || pairing == QBluetoothLocalDevice::AuthorizedPaired ) {
        qDebug()<<address.toString()<<" is paired";
    } else {
        qDebug()<<address.toString()<<" is NOT paired";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_deviceAgent;
}
QBluetoothServiceInfo MainWindow::service() const
{

}
void MainWindow::startDiscovery(const QBluetoothUuid &uuid)
{

}
void MainWindow::stopDiscovery()
{

}
void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qDebug()<<"Discovering...";
    qDebug()<<device.name();
    ui->comboBox->addItem(device.name());
    devName.append(device.name());
    devAddress.append(device.address().toString());
    qDebug()<<device.address();
/*
    //ANDROID
    if (localDevice.pairingStatus(device.address())== QBluetoothLocalDevice::Paired) qDebug()<<"paired";

    // we proceed only our remote device (Arduino/HC05 address), nothing for others...
    if (device.address().toString()!= MYDEVICE_ADD) return;

    // this is my Arduino device
    bsocket->connectToService(device.address(), 1);      //   works under Android but not on Desktop
    // here is a misterious ????
    // socket->connectToService(device.address(),QBluetoothUuid(QBluetoothUuid::SerialPort));      // only on Desktop

    bsocket->open(QIODevice::ReadWrite);
    if (bsocket->isOpen()){          // write on interface
                    ui->textEdit->append("open "+device.address().toString());
                    }
*/

    //QString devAdd = "00:12:6F:26:42:28";

    //connect(socket, SIGNAL(stateChanged(QBluetoothSocket::SocketState)), this, SLOT(socketStateChanged()));
}
void MainWindow::socketConnected()
{
    qDebug() << "Socket connected";
    qDebug() << "Local: "
             << bsocket->localName()
             << bsocket->localAddress().toString()
             << bsocket->localPort();
    qDebug() << "Peer: "
             << bsocket->peerName()
             << bsocket->peerAddress().toString()
             << bsocket->peerPort();
    ui->textEdit->append("Socket connected");
    ui->textEdit->append("Local: "+ bsocket->localName()+" "+bsocket->localAddress().toString()+" "+bsocket->localPort());
    ui->textEdit->append("Peer: "+ bsocket->peerName()+" "+bsocket->peerAddress().toString()+" "+bsocket->peerPort());

    //dla processdata
    blockSize = 0;
    datastart = 0;
}

void MainWindow::socketDisconnected()
{
    qDebug() << "Socket disconnected";
    bsocket->deleteLater();
}

void MainWindow::socketError(QBluetoothSocket::SocketError error)
{
    ui->pushButton->setEnabled(true);
    qDebug()<<"TO JEST ERROR...";
    qDebug() << "Socket error: " << error;
}

void MainWindow::scanFinished()
{
    ui->pushButton_4->setEnabled(true);
}
void MainWindow::processdata(QByteArray dane)
{

    //QList<QByteArray> z = dane.split('<');
    //QVector<double> x(1024), y(1024); // initialize with entries 0..100
    //char strtmp[500];
    int m;
    //QTextStream out(&filename);

    //for (int k=0;k<z.count();k++)
    //{
        //QByteArray d = z.at(k);
        QByteArray d = dane;
        if (d.contains('E'))
        {
            int eid = d.indexOf('E');
            d.remove(0, eid+2);
            if(d[0]==';')
            {
                d.remove(0,1);
            }
            qDebug()<<"NEW";
            qDebug()<<d;
            qDebug()<<"END";
            QList<QByteArray> l = d.split(';');

             for( m=0;m<l.count()-1;m++)
             {
                 int py;
                 bool stat = false;
                 py = l.at(m).toUInt(&stat,16);


                 x.push_back(datastart);
                 datastart+=1;
                 //x[m+datastart] = (m+datastart)*1.0; // x goes from -1 to 1
                 if(stat)
                 {
                     y.push_back(py);
                     //y[m+datastart] = py*1.0;  // let's plot a quadratic function
                 }
                 else
                 {
                     y.push_back(0);
                     //y[m+datastart] = 0;
                 }


//                 if (filecreated & ui->recordcheckBox->isChecked())
//                 {
//                     out << py <<"\n";
//                     qDebug("zapis");
//                 }
             }

             //rysowanie

             qDebug()<<x.size()<<" --- "<<y.size() <<" --- "<<l.count();
             ui->widget->graph(0)->setData(x,y);
             ui->widget->graph(0)->rescaleAxes();
             ui->widget->replot();

             if(x.size()>3*l.count())
             {
                 for(int i=0;i<l.count();i++)
                 {
                    x.pop_front();
                    y.pop_front();
                 }
             }
             //x.clear();
             //y.clear();

             //graph
//             ui->widget->graph(0)->addData(x,y);

//             ui->widget->replot();
//             //   qDebug("graphisc update should go there");
             //datastart += l.count();

//             if(datastart > (1024-128)) {
//                 datastart = 0;
//                 ui->widget->graph(0)->clearData();
//             }
        }
}

void MainWindow::onTimerTIck()
{
    if(licznik < 20)
    {

        int value = this->ui->progressBar->value();
        ui->progressBar->setValue(value+10);
//        qDebug()<<liczPakiety;
//        emgGesture.clear();
//        liczPakiety = 0;
//        //increaseBuf = false;
//        licznik = 0;
    }
    else
    {
        timer->stop();
        licznik = -1;
    }
    licznik+=1;
    //qDebug()<<licznik;
}

void MainWindow::socketRead()
{
    //qDebug()<<"Getting data..";

    QByteArray dane;
    //int dataSize;
if (bsocket && bsocket->state() == QBluetoothSocket::ConnectedState)
{
    //qDebug()<<"cos";
    ui->pushButton->setDisabled(true);
    dane = bsocket->readAll();
    //qDebug()<<dane;

    if(startGesture)
    {

    if(dane.contains('M'))
    {
        increaseBuf = true;
//        if(!timer->isActive())
//            timer->start(2000);
    }
    if(increaseBuf)
    {
        emgBuf.append(dane);
    }

    if(dane.contains('K') && increaseBuf == true)
    {
        increaseBuf = false;
        //zapis do pliku TO DO
        //ui->textEdit->append(emgBuf);

        int t1 = emgBuf.indexOf('M');
        emgBuf.remove(t1,1);
        int t2 = emgBuf.indexOf('K');
        emgBuf.chop(emgBuf.size()-t2);

        emgGesture.append(emgBuf);

        ui->textEdit->append(emgBuf);

        liczPakiety+=1;
        emgBuf.clear();
    }

    if(liczPakiety == 100)
    {
        emgGesture.chop(1);
        emgGesture.append("\n");
        saveDataToFile(ui->lineEdit->text()+".txt", (QString)emgGesture, 1);

        QList<QByteArray> list = emgGesture.split(',');
        qDebug()<<"list size: "<<list.size();
        emgGesture.clear();

        on_pushButton_5_clicked();
        liczPakiety = 0;
    }
    }
    //ui->textEdit->append((QString::number(newECGdata)) + "---status");
//    if(dane.contains("<"))
//    {
//       newFrame = true;
//    }
//    if(newFrame)
//    {
//        if(dane.contains("E"))
//        {
//            newECGdata = true;
//        }
//    }
//    if(newECGdata)
//    {
//        if(!dane.contains(">"))
//        {
//            //ui->textEdit->append(dane);
//            //ui->textEdit->append("NEW ECG DATA...");
//            //if(dane.at(0) == "<")
//            //    dane.remove(0,1);
//            ECGbuffer.append(dane);
//        }
//        if(dane.contains(">"))
//        {
//            newFrame = false;
//            newECGdata = false;

//            int eid = dane.indexOf(">");
//            for(int i=0;i<eid;i++)
//            {
//                QString d = (QString)dane.at(i);
//                //ui->textEdit->append(d);
//                ECGbuffer.append(d);
//            }
//            processdata(ECGbuffer);
//            //ui->textEdit->append("END NEW ECG DATA...");
//            ui->textEdit->append(ECGbuffer);
//            ECGbuffer.clear();
//        }
//    }
}
//    if(dane.contains("<")&&!dane.contains(">"))
//    {
//        readPacket = true;
//        //qDebug()<<dane.indexOf("<");
//        for(int i=dane.indexOf("<"); i<dane.size();i++)
//        {
//            qDebug()<<"d11";
//            ECGbuffer.append((QString)dane.at(i));
//        }
//    }
//    if(!dane.contains("<") && !dane.contains(">"))
//    {
//        if(readPacket)
//        {
//            ECGbuffer.append(dane);
//        }
//    }
//    if(dane.contains(">")&&!dane.contains("<"))
//    {
//        readPacket = false;
//        //qDebug()<<dane.indexOf(">");
//        for(int i=0; i<dane.indexOf(">");i++)
//        {
//            ECGbuffer.append((QString)dane.at(i));
//        }
//        if(ECGbuffer.contains('E'))
//        {
//            processdata(ECGbuffer);
//            //ui->textEdit->append(dane2);
//        }

//        //processdata(dane2);
//        //ui->textEdit->append(dane2);
//        ECGbuffer.clear();
//    }
//    if(dane.contains("<")&&dane.contains(">"))
//    {
//        //readPacket = false;
//        //qDebug()<<dane.indexOf(">");
//        for(int i=0; i<dane.indexOf(">");i++)
//        {
//            ECGbuffer.append((QString)dane.at(i));
//        }


//        //dekodowanie danych z dane2
//        if(ECGbuffer.contains('E'))
//        {
//            processdata(ECGbuffer);
//            //ui->textEdit->append(dane2);
//        }
//        //processdata(dane2);

//        ECGbuffer.clear();
//        readPacket = true;
//        //qDebug()<<dane.indexOf("<");

//        for(int i=dane.indexOf("<");i<dane.size();i++)
//        {
//            ECGbuffer.append(dane.at(i));
//        }
//    }
//}
}
void MainWindow::saveDataToFile(QString fname, QString data, bool append)
{
    const unsigned long size = data.size();
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
void MainWindow::serviceDiscovered(const QBluetoothServiceInfo &serviceInfo)
{

}
void MainWindow::on_pushButton_clicked()
{

    //to dla testu...

    qDebug()<<"Connecting...";

    //int add_id = ui->comboBox->currentIndex();
    devAdd = devAddress[ui->comboBox->currentIndex()];

    QBluetoothAddress address (devAdd);

    QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(address);

    if(pairingStatus == QBluetoothLocalDevice::Unpaired)
    {
        localDevice->requestPairing(address, QBluetoothLocalDevice::Paired);
        qDebug()<<"pairing requested";
    }

    qDebug()<<devAdd;

    //bsocket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);
    bsocket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    connect(bsocket, SIGNAL(error(QBluetoothSocket::SocketError)), this, SLOT(socketError(QBluetoothSocket::SocketError)));
    connect(bsocket, SIGNAL(connected()), this, SLOT(socketConnected()));
    connect(bsocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(bsocket, SIGNAL(readyRead()), this, SLOT(socketRead()));


    static const QString serviceUuid(QStringLiteral("00030000-0000-1000-8000-00805F9B34FB"));
    //Android
    #if defined(Q_OS_ANDROID)
    qDebug()<<"Adnro, Andro...";
        bsocket->connectToService(QBluetoothAddress(devAdd), QBluetoothUuid(QBluetoothUuid::Rfcomm), QIODevice::ReadWrite);
        ui->textEdit->hide();
    //bsocket->connectToService(QBluetoothAddress(devAdd), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);
    #else
    qDebug()<<"deskto, deskto...";
    //Desktop
    bsocket->connectToService(QBluetoothAddress(devAdd), 1);
    #endif
    ui->pushButton->setDisabled(true);
    ui->textEdit->append(devAdd);

    qDebug()<<bsocket->isOpen();
    qDebug()<<bsocket->isReadable();
}

void MainWindow::on_pushButton_2_clicked()
{
        bsocket->close();
        ui->pushButton->setDisabled(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    //bsocket->writeData("start");
    QByteArray info = ui->lineEdit->text().toLocal8Bit()+"\n";

    bsocket->write(info);
    qDebug()<<bsocket->state();
    qDebug()<<"read all"<<bsocket->readAll();

    //EKG
    //bsocket->write("SADD\r\n");
}

void MainWindow::on_pushButton_4_clicked()
{
    //m_deviceAgent->deleteLater();
    //m_deviceAgent = new QBluetoothDeviceDiscoveryAgent(this);
    //connect(m_deviceAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));


    qDebug()<<"key pressed";
    devAddress.clear();
    devName.clear();
    ui->comboBox->clear();
    m_deviceAgent->stop();
    m_deviceAgent->start();
    ui->pushButton_4->setDisabled(true);
}

void MainWindow::on_pushButton_5_clicked()
{
    startGesture = !startGesture;
    if(startGesture == true)
    {
        if(!timer->isActive())
            timer->start(100);
        ui->progressBar->setValue(0);
        ui->pushButton_5->setEnabled(false);
        licznikGestow +=1;
        ui->pushButton_6->setText(QString::number(licznikGestow));
    }
    if(startGesture == false)
    {
        ui->pushButton_5->setEnabled(true);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    licznikGestow = 0;
    ui->pushButton_6->setText(QString::number(licznikGestow));
}
