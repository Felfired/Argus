/********************************************************************************
** Form generated from reading UI file 'facedetectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEDETECTIONDIALOG_H
#define UI_FACEDETECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceDetectionDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *startButton;
    QPushButton *closeButton;
    QGroupBox *groupBox;
    QCheckBox *saveToVideoCheckBox;
    QCheckBox *saveToImageCheckBox;
    QPushButton *selectFolderButton;
    QLineEdit *saveFolderDisplay;

    void setupUi(QDialog *FaceDetectionDialog)
    {
        if (FaceDetectionDialog->objectName().isEmpty())
            FaceDetectionDialog->setObjectName("FaceDetectionDialog");
        FaceDetectionDialog->resize(480, 330);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/argus/res/app_icons/detection.png"), QSize(), QIcon::Normal, QIcon::Off);
        FaceDetectionDialog->setWindowIcon(icon);
        layoutWidget = new QWidget(FaceDetectionDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 290, 461, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName("hboxLayout");
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName("startButton");

        hboxLayout->addWidget(startButton);

        closeButton = new QPushButton(layoutWidget);
        closeButton->setObjectName("closeButton");

        hboxLayout->addWidget(closeButton);

        groupBox = new QGroupBox(FaceDetectionDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 461, 121));
        saveToVideoCheckBox = new QCheckBox(groupBox);
        saveToVideoCheckBox->setObjectName("saveToVideoCheckBox");
        saveToVideoCheckBox->setGeometry(QRect(10, 30, 431, 20));
        saveToImageCheckBox = new QCheckBox(groupBox);
        saveToImageCheckBox->setObjectName("saveToImageCheckBox");
        saveToImageCheckBox->setGeometry(QRect(10, 60, 431, 20));
        selectFolderButton = new QPushButton(groupBox);
        selectFolderButton->setObjectName("selectFolderButton");
        selectFolderButton->setGeometry(QRect(10, 90, 111, 24));
        saveFolderDisplay = new QLineEdit(groupBox);
        saveFolderDisplay->setObjectName("saveFolderDisplay");
        saveFolderDisplay->setGeometry(QRect(130, 90, 321, 21));

        retranslateUi(FaceDetectionDialog);
        QObject::connect(startButton, &QPushButton::clicked, FaceDetectionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(closeButton, &QPushButton::clicked, FaceDetectionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(FaceDetectionDialog);
    } // setupUi

    void retranslateUi(QDialog *FaceDetectionDialog)
    {
        FaceDetectionDialog->setWindowTitle(QCoreApplication::translate("FaceDetectionDialog", "\316\240\316\261\317\201\316\261\316\274\316\265\317\204\317\201\316\277\317\200\316\277\316\257\316\267\317\203\316\267 \316\225\316\275\317\204\316\277\317\200\316\271\317\203\316\274\316\277\317\215 \316\240\317\201\316\277\317\203\317\216\317\200\317\211\316\275", nullptr));
        startButton->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\225\316\272\316\272\316\257\316\275\316\267\317\203\316\267", nullptr));
        closeButton->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\232\316\273\316\265\316\257\317\203\316\271\316\274\316\277", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FaceDetectionDialog", "\316\225\317\200\316\271\316\273\316\277\316\263\316\255\317\202 \316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267\317\202", nullptr));
        saveToVideoCheckBox->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267 \317\203\317\204\316\271\316\263\316\274\316\271\317\214\317\204\317\205\317\200\317\211\316\275 \317\214\317\200\316\277\317\205 \316\265\316\275\317\204\316\277\317\200\316\257\317\203\317\204\316\267\316\272\316\261\316\275 \317\200\317\201\317\214\317\203\317\211\317\200\316\261 \317\203\316\265 \316\262\316\257\316\275\317\204\316\265\316\277.", nullptr));
        saveToImageCheckBox->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\225\316\276\316\261\316\263\317\211\316\263\316\256 \316\265\316\271\316\272\317\214\316\275\317\211\316\275 \316\261\317\200\316\277 \317\204\316\261 \317\200\317\201\317\214\317\203\317\211\317\200\316\261 \317\200\316\277\317\205 \316\265\316\275\317\204\316\277\317\200\316\257\317\203\317\204\316\267\316\272\316\261\316\275.", nullptr));
        selectFolderButton->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\225\317\200\316\271\316\273\316\277\316\263\316\256 \316\246\316\261\316\272\316\255\316\273\316\277\317\205...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceDetectionDialog: public Ui_FaceDetectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEDETECTIONDIALOG_H