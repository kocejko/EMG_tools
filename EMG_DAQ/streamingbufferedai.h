#ifndef STREAMINGBUFFEREDAI_H
#define STREAMINGBUFFEREDAI_H

#include <QDialog>
#include <QMessageBox>
#include "ui_streamingbufferedai.h"
#include "common/simplegraph.h"
#include "configuredialog.h"

#include <QDebug>
#include <QTimer>



class AI_StreamingBufferedAi : public QDialog
{
	Q_OBJECT

	class DataReadyHandler : public BfdAiEventListener
	{
	public:
		AI_StreamingBufferedAi * owner;
		virtual void BDAQCALL BfdAiEvent(void * sender, BfdAiEventArgs * args)
		{
			owner->DataHandler(sender, args);
		}
	};

	class OverrunHandler : public BfdAiEventListener
	{
	public:
		AI_StreamingBufferedAi * owner;
		virtual void BDAQCALL BfdAiEvent(void * sender, BfdAiEventArgs * args)
		{
			//QString message = tr("The event over run has happened!");
			//QMessageBox::information(this, "Warning Information", message);
		}
	};

	class CacheOverflowHandler : public BfdAiEventListener
	{
	public:
		AI_StreamingBufferedAi * owner;
		virtual void BDAQCALL BfdAiEvent(void * sender, BfdAiEventArgs * args)
		{
			//QString message = tr("The event cache over flow has happened!");
			//QMessageBox::information(this, "Warning Information", message);
		}
	};

	class StoppedHandler : public BfdAiEventListener
	{
	public:
		AI_StreamingBufferedAi * owner;
		virtual void BDAQCALL BfdAiEvent(void * sender, BfdAiEventArgs * args)
		{
			//QString message = tr("The event stopped has happened!");
			//QMessageBox::information(this, "Warning Information", message);
		}
	};

public:
    AI_StreamingBufferedAi(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~AI_StreamingBufferedAi();
	void Initialize();

	void SetConfigureDialog(ConfigureDialog * dialog){configureDialog = dialog;}
	void SetConfigureParameter(ConfigureParameter value){configure = value;}

	void ConfigureDevice();
	void ConfigureGraph();
	void InitializeList();
	void SetXCord();
	void CheckError(ErrorCode errorCode);
	void DataHandler(void *sender, BfdAiEventArgs *args);

    QTimer *timer;
    QTimer *rest_timer;
    int t_sec;
    int r_sec = 0;
public slots:
    void ontick();
    void onRestTimerTick();

private:
	Ui::AI_StreamingBufferedAiClass ui;
	SimpleGraph *graph;
	ConfigureDialog *configureDialog;
	ConfigureParameter configure;
	BufferedAiCtrl *bufferedAiCtrl;
	double *scaledData;
    double *scaledDataPrint;

	//decide how many sections in the raw data buffer. 
	static const int sectionCount = 4;
	//decide how many samples in a section each channel
	int sectionLengthPerChan;
	int rawDataBufferLength;
	TimeUnit timeUnit;

	DataReadyHandler dataReadyHandler;
	OverrunHandler overrunHandler;
	CacheOverflowHandler cacheOverflowHandler;
	StoppedHandler stoppedHander;

    void saveDataToFile(QString fname, QString data, bool append);
    bool zapis;
	
	private slots:
		void DivValueChanged(int value);
		void ButtonConfigureClicked();
		void ButtonStartClicked();
		void ButtonPauseClicked();
		void ButtonStopClicked();
        void on_pushButton_clicked();
};

#endif // STREAMINGBUFFEREDAI_H
