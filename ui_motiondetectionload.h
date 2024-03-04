/********************************************************************************
** Form generated from reading UI file 'motiondetectionload.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTIONDETECTIONLOAD_H
#define UI_MOTIONDETECTIONLOAD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotionDetectionLoad
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *cancelButton;
    QProgressBar *progressBar;
    QLabel *statusLabel;

    void setupUi(QDialog *MotionDetectionLoad)
    {
        if (MotionDetectionLoad->objectName().isEmpty())
            MotionDetectionLoad->setObjectName("MotionDetectionLoad");
        MotionDetectionLoad->setWindowModality(Qt::NonModal);
        MotionDetectionLoad->resize(388, 113);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/app_icons/motion_detection.png"), QSize(), QIcon::Normal, QIcon::Off);
        MotionDetectionLoad->setWindowIcon(icon);
        layoutWidget = new QWidget(MotionDetectionLoad);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 70, 351, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName("hboxLayout");
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName("cancelButton");

        hboxLayout->addWidget(cancelButton);

        progressBar = new QProgressBar(MotionDetectionLoad);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(20, 30, 351, 23));
        progressBar->setValue(24);
        statusLabel = new QLabel(MotionDetectionLoad);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(20, 10, 351, 16));

        retranslateUi(MotionDetectionLoad);

        QMetaObject::connectSlotsByName(MotionDetectionLoad);
    } // setupUi

    void retranslateUi(QDialog *MotionDetectionLoad)
    {
        MotionDetectionLoad->setWindowTitle(QCoreApplication::translate("MotionDetectionLoad", "\316\225\316\275\317\204\316\277\317\200\316\271\317\203\316\274\317\214\317\202 \316\232\316\257\316\275\316\267\317\203\316\267\317\202...", nullptr));
        cancelButton->setText(QCoreApplication::translate("MotionDetectionLoad", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", nullptr));
        statusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MotionDetectionLoad: public Ui_MotionDetectionLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTIONDETECTIONLOAD_H
