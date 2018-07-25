/********************************************************************************
** Form generated from reading UI file 'configuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREDIALOG_H
#define UI_CONFIGUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConfigureDialog
{
public:
    QComboBox *cmbDevice;
    QGroupBox *groupBox;
    QLabel *lblChannelCount;
    QLineEdit *edtClockRatePerChan;
    QComboBox *cmbValueRange;
    QLabel *lblValueRange;
    QLabel *lblClockRate;
    QComboBox *cmbChannelStart;
    QLabel *lblChannelStart;
    QLabel *lblRateUnit;
    QComboBox *cmbChannelCount;
    QPushButton *btnCancel;
    QLabel *lblDevice;
    QPushButton *btnOK;

    void setupUi(QDialog *ConfigureDialog)
    {
        if (ConfigureDialog->objectName().isEmpty())
            ConfigureDialog->setObjectName(QStringLiteral("ConfigureDialog"));
        ConfigureDialog->resize(377, 260);
        ConfigureDialog->setMinimumSize(QSize(377, 260));
        ConfigureDialog->setMaximumSize(QSize(377, 260));
        cmbDevice = new QComboBox(ConfigureDialog);
        cmbDevice->setObjectName(QStringLiteral("cmbDevice"));
        cmbDevice->setGeometry(QRect(90, 20, 241, 20));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbDevice->sizePolicy().hasHeightForWidth());
        cmbDevice->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(ConfigureDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 341, 151));
        lblChannelCount = new QLabel(groupBox);
        lblChannelCount->setObjectName(QStringLiteral("lblChannelCount"));
        lblChannelCount->setGeometry(QRect(17, 56, 91, 22));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblChannelCount->sizePolicy().hasHeightForWidth());
        lblChannelCount->setSizePolicy(sizePolicy1);
        lblChannelCount->setMinimumSize(QSize(91, 22));
        lblChannelCount->setMaximumSize(QSize(91, 22));
        edtClockRatePerChan = new QLineEdit(groupBox);
        edtClockRatePerChan->setObjectName(QStringLiteral("edtClockRatePerChan"));
        edtClockRatePerChan->setGeometry(QRect(107, 120, 201, 20));
        edtClockRatePerChan->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cmbValueRange = new QComboBox(groupBox);
        cmbValueRange->setObjectName(QStringLiteral("cmbValueRange"));
        cmbValueRange->setGeometry(QRect(108, 88, 201, 20));
        sizePolicy.setHeightForWidth(cmbValueRange->sizePolicy().hasHeightForWidth());
        cmbValueRange->setSizePolicy(sizePolicy);
        lblValueRange = new QLabel(groupBox);
        lblValueRange->setObjectName(QStringLiteral("lblValueRange"));
        lblValueRange->setGeometry(QRect(17, 88, 91, 22));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblValueRange->sizePolicy().hasHeightForWidth());
        lblValueRange->setSizePolicy(sizePolicy2);
        lblValueRange->setMinimumSize(QSize(91, 22));
        lblValueRange->setMaximumSize(QSize(91, 22));
        lblClockRate = new QLabel(groupBox);
        lblClockRate->setObjectName(QStringLiteral("lblClockRate"));
        lblClockRate->setGeometry(QRect(17, 120, 81, 22));
        sizePolicy2.setHeightForWidth(lblClockRate->sizePolicy().hasHeightForWidth());
        lblClockRate->setSizePolicy(sizePolicy2);
        cmbChannelStart = new QComboBox(groupBox);
        cmbChannelStart->setObjectName(QStringLiteral("cmbChannelStart"));
        cmbChannelStart->setGeometry(QRect(108, 24, 201, 20));
        sizePolicy.setHeightForWidth(cmbChannelStart->sizePolicy().hasHeightForWidth());
        cmbChannelStart->setSizePolicy(sizePolicy);
        lblChannelStart = new QLabel(groupBox);
        lblChannelStart->setObjectName(QStringLiteral("lblChannelStart"));
        lblChannelStart->setGeometry(QRect(17, 24, 91, 22));
        lblChannelStart->setMinimumSize(QSize(91, 22));
        lblChannelStart->setMaximumSize(QSize(91, 22));
        lblRateUnit = new QLabel(groupBox);
        lblRateUnit->setObjectName(QStringLiteral("lblRateUnit"));
        lblRateUnit->setGeometry(QRect(310, 120, 21, 22));
        sizePolicy2.setHeightForWidth(lblRateUnit->sizePolicy().hasHeightForWidth());
        lblRateUnit->setSizePolicy(sizePolicy2);
        cmbChannelCount = new QComboBox(groupBox);
        cmbChannelCount->setObjectName(QStringLiteral("cmbChannelCount"));
        cmbChannelCount->setGeometry(QRect(108, 56, 201, 20));
        sizePolicy.setHeightForWidth(cmbChannelCount->sizePolicy().hasHeightForWidth());
        cmbChannelCount->setSizePolicy(sizePolicy);
        btnCancel = new QPushButton(ConfigureDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(250, 220, 75, 23));
        btnCancel->setAutoDefault(false);
        lblDevice = new QLabel(ConfigureDialog);
        lblDevice->setObjectName(QStringLiteral("lblDevice"));
        lblDevice->setGeometry(QRect(39, 20, 51, 22));
        sizePolicy2.setHeightForWidth(lblDevice->sizePolicy().hasHeightForWidth());
        lblDevice->setSizePolicy(sizePolicy2);
        btnOK = new QPushButton(ConfigureDialog);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(160, 220, 75, 23));
#ifndef QT_NO_SHORTCUT
        lblChannelCount->setBuddy(cmbChannelCount);
        lblValueRange->setBuddy(cmbValueRange);
        lblClockRate->setBuddy(cmbValueRange);
        lblChannelStart->setBuddy(cmbChannelStart);
        lblRateUnit->setBuddy(cmbValueRange);
        lblDevice->setBuddy(cmbDevice);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(cmbDevice, cmbChannelStart);
        QWidget::setTabOrder(cmbChannelStart, cmbChannelCount);
        QWidget::setTabOrder(cmbChannelCount, cmbValueRange);
        QWidget::setTabOrder(cmbValueRange, edtClockRatePerChan);
        QWidget::setTabOrder(edtClockRatePerChan, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);

        retranslateUi(ConfigureDialog);

        QMetaObject::connectSlotsByName(ConfigureDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigureDialog)
    {
        ConfigureDialog->setWindowTitle(QApplication::translate("ConfigureDialog", "Streaming AI - Configuration", 0));
        groupBox->setTitle(QApplication::translate("ConfigureDialog", "Streaming AI settings", 0));
        lblChannelCount->setText(QApplication::translate("ConfigureDialog", "Channel count:", 0));
        edtClockRatePerChan->setText(QApplication::translate("ConfigureDialog", "1000", 0));
        lblValueRange->setText(QApplication::translate("ConfigureDialog", "Value range:", 0));
        lblClockRate->setText(QApplication::translate("ConfigureDialog", "Clock rate:", 0));
        lblChannelStart->setText(QApplication::translate("ConfigureDialog", "Channel start:", 0));
        lblRateUnit->setText(QApplication::translate("ConfigureDialog", "Hz", 0));
        btnCancel->setText(QApplication::translate("ConfigureDialog", "Cancel", 0));
        lblDevice->setText(QApplication::translate("ConfigureDialog", "Device:", 0));
        btnOK->setText(QApplication::translate("ConfigureDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigureDialog: public Ui_ConfigureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREDIALOG_H
