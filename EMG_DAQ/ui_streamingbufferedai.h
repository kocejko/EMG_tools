/********************************************************************************
** Form generated from reading UI file 'streamingbufferedai.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREAMINGBUFFEREDAI_H
#define UI_STREAMINGBUFFEREDAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AI_StreamingBufferedAiClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lblYCoordinateMax;
    QSpacerItem *verticalSpacer_2;
    QLabel *lblYCoordinateMid;
    QSpacerItem *verticalSpacer;
    QLabel *lblYCoordinateMin;
    QFrame *graphFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblXCoordinateStart;
    QSpacerItem *horizontalSpacer;
    QLabel *lblXCoordinateEnd;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblColor;
    QListWidget *listWidget;
    QLabel *lblDiv;
    QSlider *sldDiv;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnConfigure;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QSpinBox *spinBox;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QSpinBox *spinBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;

    void setupUi(QDialog *AI_StreamingBufferedAiClass)
    {
        if (AI_StreamingBufferedAiClass->objectName().isEmpty())
            AI_StreamingBufferedAiClass->setObjectName(QStringLiteral("AI_StreamingBufferedAiClass"));
        AI_StreamingBufferedAiClass->resize(809, 614);
        AI_StreamingBufferedAiClass->setMinimumSize(QSize(762, 515));
        AI_StreamingBufferedAiClass->setMaximumSize(QSize(10000000, 10000000));
        verticalLayout_2 = new QVBoxLayout(AI_StreamingBufferedAiClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblYCoordinateMax = new QLabel(AI_StreamingBufferedAiClass);
        lblYCoordinateMax->setObjectName(QStringLiteral("lblYCoordinateMax"));
        lblYCoordinateMax->setMaximumSize(QSize(40, 40));
        lblYCoordinateMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lblYCoordinateMax);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        lblYCoordinateMid = new QLabel(AI_StreamingBufferedAiClass);
        lblYCoordinateMid->setObjectName(QStringLiteral("lblYCoordinateMid"));
        lblYCoordinateMid->setMaximumSize(QSize(40, 40));
        lblYCoordinateMid->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lblYCoordinateMid);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lblYCoordinateMin = new QLabel(AI_StreamingBufferedAiClass);
        lblYCoordinateMin->setObjectName(QStringLiteral("lblYCoordinateMin"));
        lblYCoordinateMin->setMaximumSize(QSize(40, 40));
        lblYCoordinateMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lblYCoordinateMin);


        horizontalLayout->addLayout(verticalLayout);

        graphFrame = new QFrame(AI_StreamingBufferedAiClass);
        graphFrame->setObjectName(QStringLiteral("graphFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphFrame->sizePolicy().hasHeightForWidth());
        graphFrame->setSizePolicy(sizePolicy);
        graphFrame->setMinimumSize(QSize(700, 350));
        graphFrame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        graphFrame->setFrameShape(QFrame::StyledPanel);
        graphFrame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(graphFrame);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblXCoordinateStart = new QLabel(AI_StreamingBufferedAiClass);
        lblXCoordinateStart->setObjectName(QStringLiteral("lblXCoordinateStart"));
        lblXCoordinateStart->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblXCoordinateStart);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lblXCoordinateEnd = new QLabel(AI_StreamingBufferedAiClass);
        lblXCoordinateEnd->setObjectName(QStringLiteral("lblXCoordinateEnd"));
        lblXCoordinateEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblXCoordinateEnd);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lblColor = new QLabel(AI_StreamingBufferedAiClass);
        lblColor->setObjectName(QStringLiteral("lblColor"));
        lblColor->setMinimumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(lblColor);

        listWidget = new QListWidget(AI_StreamingBufferedAiClass);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setProperty("isWrapping", QVariant(true));

        horizontalLayout_3->addWidget(listWidget);

        lblDiv = new QLabel(AI_StreamingBufferedAiClass);
        lblDiv->setObjectName(QStringLiteral("lblDiv"));
        lblDiv->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lblDiv);

        sldDiv = new QSlider(AI_StreamingBufferedAiClass);
        sldDiv->setObjectName(QStringLiteral("sldDiv"));
        sldDiv->setEnabled(false);
        sldDiv->setMinimum(10);
        sldDiv->setMaximum(1000);
        sldDiv->setSingleStep(10);
        sldDiv->setValue(200);
        sldDiv->setOrientation(Qt::Horizontal);
        sldDiv->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(sldDiv);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnConfigure = new QPushButton(AI_StreamingBufferedAiClass);
        btnConfigure->setObjectName(QStringLiteral("btnConfigure"));
        btnConfigure->setEnabled(true);
        btnConfigure->setAutoDefault(false);

        horizontalLayout_4->addWidget(btnConfigure);

        btnStart = new QPushButton(AI_StreamingBufferedAiClass);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setAutoDefault(true);

        horizontalLayout_4->addWidget(btnStart);

        btnPause = new QPushButton(AI_StreamingBufferedAiClass);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setEnabled(false);
        btnPause->setAutoDefault(false);

        horizontalLayout_4->addWidget(btnPause);

        btnStop = new QPushButton(AI_StreamingBufferedAiClass);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setEnabled(false);
        btnStop->setAutoDefault(false);

        horizontalLayout_4->addWidget(btnStop);

        spinBox = new QSpinBox(AI_StreamingBufferedAiClass);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(2000);
        spinBox->setSingleStep(100);
        spinBox->setValue(1000);

        horizontalLayout_4->addWidget(spinBox);

        label_2 = new QLabel(AI_StreamingBufferedAiClass);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        pushButton_2 = new QPushButton(AI_StreamingBufferedAiClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        progressBar = new QProgressBar(AI_StreamingBufferedAiClass);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(AI_StreamingBufferedAiClass);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        lineEdit = new QLineEdit(AI_StreamingBufferedAiClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        spinBox_2 = new QSpinBox(AI_StreamingBufferedAiClass);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(1000);
        spinBox_2->setValue(100);

        horizontalLayout_5->addWidget(spinBox_2);

        label_3 = new QLabel(AI_StreamingBufferedAiClass);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        pushButton = new QPushButton(AI_StreamingBufferedAiClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        spinBox_3 = new QSpinBox(AI_StreamingBufferedAiClass);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(5);
        spinBox_3->setValue(1);

        horizontalLayout_5->addWidget(spinBox_3);

        checkBox_2 = new QCheckBox(AI_StreamingBufferedAiClass);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_5->addWidget(checkBox_2);

        checkBox = new QCheckBox(AI_StreamingBufferedAiClass);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_5->addWidget(checkBox);


        verticalLayout_2->addLayout(horizontalLayout_5);

        QWidget::setTabOrder(btnConfigure, btnStart);
        QWidget::setTabOrder(btnStart, btnPause);
        QWidget::setTabOrder(btnPause, btnStop);
        QWidget::setTabOrder(btnStop, sldDiv);
        QWidget::setTabOrder(sldDiv, listWidget);

        retranslateUi(AI_StreamingBufferedAiClass);

        QMetaObject::connectSlotsByName(AI_StreamingBufferedAiClass);
    } // setupUi

    void retranslateUi(QDialog *AI_StreamingBufferedAiClass)
    {
        AI_StreamingBufferedAiClass->setWindowTitle(QApplication::translate("AI_StreamingBufferedAiClass", "AI_StreamingAI", 0));
        lblYCoordinateMax->setText(QApplication::translate("AI_StreamingBufferedAiClass", "10.0V", 0));
        lblYCoordinateMid->setText(QApplication::translate("AI_StreamingBufferedAiClass", "0", 0));
        lblYCoordinateMin->setText(QApplication::translate("AI_StreamingBufferedAiClass", "-10.0V", 0));
        lblXCoordinateStart->setText(QApplication::translate("AI_StreamingBufferedAiClass", "0Sec", 0));
        lblXCoordinateEnd->setText(QApplication::translate("AI_StreamingBufferedAiClass", "10Sec", 0));
        lblColor->setText(QApplication::translate("AI_StreamingBufferedAiClass", "Color of\n"
"channel:", 0));
        lblDiv->setText(QApplication::translate("AI_StreamingBufferedAiClass", "Div:", 0));
        btnConfigure->setText(QApplication::translate("AI_StreamingBufferedAiClass", "Configure", 0));
        btnStart->setText(QApplication::translate("AI_StreamingBufferedAiClass", "Start", 0));
        btnPause->setText(QApplication::translate("AI_StreamingBufferedAiClass", "Pause", 0));
        btnStop->setText(QApplication::translate("AI_StreamingBufferedAiClass", "Stop", 0));
        label_2->setText(QApplication::translate("AI_StreamingBufferedAiClass", "0", 0));
        pushButton_2->setText(QApplication::translate("AI_StreamingBufferedAiClass", "GO", 0));
        label->setText(QApplication::translate("AI_StreamingBufferedAiClass", "file name", 0));
        label_3->setText(QApplication::translate("AI_StreamingBufferedAiClass", "to go:", 0));
        pushButton->setText(QApplication::translate("AI_StreamingBufferedAiClass", "Save", 0));
        checkBox_2->setText(QApplication::translate("AI_StreamingBufferedAiClass", "Auto", 0));
        checkBox->setText(QApplication::translate("AI_StreamingBufferedAiClass", "zapis kolumny", 0));
    } // retranslateUi

};

namespace Ui {
    class AI_StreamingBufferedAiClass: public Ui_AI_StreamingBufferedAiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAMINGBUFFEREDAI_H
