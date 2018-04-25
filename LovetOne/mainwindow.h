#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBluetoothAddress>
#include <QBluetoothLocalDevice>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QBluetoothServiceInfo>
#include <QBluetoothServiceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QBluetoothUuid>
#include <QListWidgetItem>
#include <QStringList>
#include <QDebug>

#include <qbluetoothuuid.h>
#include <qbluetoothserviceinfo.h>
#include <qbluetoothservicediscoveryagent.h>
#include <qcustomplot.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void startDiscovery(const QBluetoothUuid &uuid);
    void stopDiscovery();
    QBluetoothServiceInfo service() const;

    QBluetoothServiceDiscoveryAgent *m_discoveryAgent;
    QBluetoothServiceInfo m_service;
    QBluetoothDeviceDiscoveryAgent *m_deviceAgent;
    QMap<QListWidgetItem *, QBluetoothServiceInfo> m_discoveredServices;
    QBluetoothSocket *bsocket;
    QString devAdd;
    void processdata(QByteArray);
    bool newFrame;
    bool newECGdata;
    QByteArray ECGbuffer;
    bool increaseBuf = false;
    QByteArray emgBuf;
    QByteArray emgGesture;
    QStringList devName;
    QStringList devAddress;

    //dla processdata
    int datastart;
    QVector<double> x;
    QVector<double> y;
    int blockSize;
    QFile filename;
    bool filecreated;
    bool readPacket;
public:
    QBluetoothLocalDevice *localDevice;
    QString localDeviceName;
    QTimer *timer;
    int licznik = 0;
    int licznikGestow = 0;
    int liczPakiety = 0;

    bool startGesture = false;

    void saveDataToFile(QString fname, QString data, bool append);


public slots:
    void onTimerTIck();

private slots:
    void pairingDone(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing);
    void serviceDiscovered(const QBluetoothServiceInfo &serviceInfo);
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void socketRead();
    void socketDisconnected();
    void socketConnected();
    void socketError(QBluetoothSocket::SocketError error);

    //void startScan();
    void scanFinished();

    //void discoveryFinished();
    //void on_remoteDevices_itemActivated(QListWidgetItem *item);
    //void on_cancelButton_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};

#endif // MAINWINDOW_H
