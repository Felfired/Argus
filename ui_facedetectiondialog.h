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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
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
    QTabWidget *modelSelectionTabWidget;
    QWidget *caffeTab;
    QGroupBox *groupBox_2;
    QLabel *label;
    QDoubleSpinBox *scaleFactorSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *confidenceThresholdSpinBox;
    QWidget *yunetTab;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QDoubleSpinBox *yConfidenceThresholdSpinBox;
    QLabel *nmsThresholdLabel;
    QDoubleSpinBox *nmsThresholdSpinBox;
    QLabel *label_6;
    QSpinBox *detectionCountSpinBox;
    QGroupBox *groupBox_4;
    QLabel *label_3;
    QSpinBox *frameskipSpinBox;
    QCheckBox *applyToImageCheckBox;
    QCheckBox *applyToVideoCheckBox;
    QPushButton *frameskipHelpButton;

    void setupUi(QDialog *FaceDetectionDialog)
    {
        if (FaceDetectionDialog->objectName().isEmpty())
            FaceDetectionDialog->setObjectName("FaceDetectionDialog");
        FaceDetectionDialog->resize(480, 516);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/argus/res/app_icons/detection.png"), QSize(), QIcon::Normal, QIcon::Off);
        FaceDetectionDialog->setWindowIcon(icon);
        layoutWidget = new QWidget(FaceDetectionDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 470, 461, 33));
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
        groupBox->setGeometry(QRect(10, 310, 461, 151));
        saveToVideoCheckBox = new QCheckBox(groupBox);
        saveToVideoCheckBox->setObjectName("saveToVideoCheckBox");
        saveToVideoCheckBox->setGeometry(QRect(10, 30, 441, 20));
        saveToImageCheckBox = new QCheckBox(groupBox);
        saveToImageCheckBox->setObjectName("saveToImageCheckBox");
        saveToImageCheckBox->setGeometry(QRect(10, 60, 441, 20));
        selectFolderButton = new QPushButton(groupBox);
        selectFolderButton->setObjectName("selectFolderButton");
        selectFolderButton->setGeometry(QRect(10, 120, 111, 24));
        saveFolderDisplay = new QLineEdit(groupBox);
        saveFolderDisplay->setObjectName("saveFolderDisplay");
        saveFolderDisplay->setGeometry(QRect(130, 120, 321, 21));
        modelSelectionTabWidget = new QTabWidget(FaceDetectionDialog);
        modelSelectionTabWidget->setObjectName("modelSelectionTabWidget");
        modelSelectionTabWidget->setGeometry(QRect(10, 10, 461, 181));
        caffeTab = new QWidget();
        caffeTab->setObjectName("caffeTab");
        groupBox_2 = new QGroupBox(caffeTab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 10, 431, 171));
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 191, 16));
        scaleFactorSpinBox = new QDoubleSpinBox(groupBox_2);
        scaleFactorSpinBox->setObjectName("scaleFactorSpinBox");
        scaleFactorSpinBox->setGeometry(QRect(360, 26, 51, 22));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 141, 16));
        confidenceThresholdSpinBox = new QDoubleSpinBox(groupBox_2);
        confidenceThresholdSpinBox->setObjectName("confidenceThresholdSpinBox");
        confidenceThresholdSpinBox->setGeometry(QRect(360, 56, 51, 22));
        modelSelectionTabWidget->addTab(caffeTab, QString());
        yunetTab = new QWidget();
        yunetTab->setObjectName("yunetTab");
        groupBox_3 = new QGroupBox(yunetTab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 10, 441, 131));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 30, 141, 16));
        yConfidenceThresholdSpinBox = new QDoubleSpinBox(groupBox_3);
        yConfidenceThresholdSpinBox->setObjectName("yConfidenceThresholdSpinBox");
        yConfidenceThresholdSpinBox->setGeometry(QRect(360, 25, 51, 22));
        nmsThresholdLabel = new QLabel(groupBox_3);
        nmsThresholdLabel->setObjectName("nmsThresholdLabel");
        nmsThresholdLabel->setGeometry(QRect(10, 60, 311, 16));
        nmsThresholdSpinBox = new QDoubleSpinBox(groupBox_3);
        nmsThresholdSpinBox->setObjectName("nmsThresholdSpinBox");
        nmsThresholdSpinBox->setGeometry(QRect(360, 55, 51, 22));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 90, 321, 16));
        detectionCountSpinBox = new QSpinBox(groupBox_3);
        detectionCountSpinBox->setObjectName("detectionCountSpinBox");
        detectionCountSpinBox->setGeometry(QRect(360, 85, 51, 22));
        modelSelectionTabWidget->addTab(yunetTab, QString());
        groupBox_4 = new QGroupBox(FaceDetectionDialog);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 200, 461, 101));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 30, 181, 16));
        frameskipSpinBox = new QSpinBox(groupBox_4);
        frameskipSpinBox->setObjectName("frameskipSpinBox");
        frameskipSpinBox->setGeometry(QRect(372, 25, 51, 22));
        applyToImageCheckBox = new QCheckBox(groupBox_4);
        applyToImageCheckBox->setObjectName("applyToImageCheckBox");
        applyToImageCheckBox->setGeometry(QRect(40, 50, 151, 20));
        applyToVideoCheckBox = new QCheckBox(groupBox_4);
        applyToVideoCheckBox->setObjectName("applyToVideoCheckBox");
        applyToVideoCheckBox->setGeometry(QRect(40, 70, 171, 20));
        frameskipHelpButton = new QPushButton(groupBox_4);
        frameskipHelpButton->setObjectName("frameskipHelpButton");
        frameskipHelpButton->setGeometry(QRect(187, 20, 16, 16));
        QFont font;
        font.setUnderline(true);
        font.setKerning(true);
        frameskipHelpButton->setFont(font);
        frameskipHelpButton->setCursor(QCursor(Qt::WhatsThisCursor));
        frameskipHelpButton->setFlat(true);

        retranslateUi(FaceDetectionDialog);
        QObject::connect(startButton, &QPushButton::clicked, FaceDetectionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(closeButton, &QPushButton::clicked, FaceDetectionDialog, qOverload<>(&QDialog::reject));

        modelSelectionTabWidget->setCurrentIndex(1);


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
        groupBox_2->setTitle(QCoreApplication::translate("FaceDetectionDialog", "\316\240\316\261\317\201\316\254\316\274\316\265\317\204\317\201\316\277\316\271", nullptr));
        label->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\243\317\205\316\275\317\204\316\265\316\273\316\265\317\203\317\204\316\256\317\202 \316\232\316\273\316\257\316\274\316\261\316\272\316\261\317\202 (0.1 - 2.0):", nullptr));
        label_2->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\225\317\205\316\261\316\271\317\203\316\270\316\267\317\203\316\257\316\261 (0.01 - 0.99):", nullptr));
        modelSelectionTabWidget->setTabText(modelSelectionTabWidget->indexOf(caffeTab), QCoreApplication::translate("FaceDetectionDialog", "Caffe", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FaceDetectionDialog", "\316\240\316\261\317\201\316\254\316\274\316\265\317\204\317\201\316\277\316\271", nullptr));
        label_4->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\225\317\205\316\261\316\271\317\203\316\270\316\267\317\203\316\257\316\261 (0.01 - 0.99):", nullptr));
        nmsThresholdLabel->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\243\317\205\316\275\317\204\316\265\316\273\316\265\317\203\317\204\316\256\317\202 \316\243\316\257\316\263\316\261\317\203\316\267\317\202 \316\230\316\265\317\204\316\271\316\272\317\216\316\275 \316\221\317\200\316\277\317\204\316\265\316\273\316\265\317\203\316\274\316\254\317\204\317\211\316\275 (0.1 - 0.8):", nullptr));
        label_6->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\234\316\255\316\263\316\271\317\203\317\204\316\277 \316\214\317\201\316\271\316\277 \316\230\316\265\317\204\316\271\316\272\317\216\316\275 \316\221\317\200\316\277\317\204\316\265\316\273\316\265\317\203\316\274\316\254\317\204\317\211\316\275:", nullptr));
        modelSelectionTabWidget->setTabText(modelSelectionTabWidget->indexOf(yunetTab), QCoreApplication::translate("FaceDetectionDialog", "YuNet", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("FaceDetectionDialog", "\316\223\316\265\316\275\316\271\316\272\316\255\317\202 \316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202", nullptr));
        label_3->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\221\317\201\316\271\316\270\316\274\317\214\317\202 \316\240\316\261\317\201\316\254\316\273\316\265\316\271\317\210\316\267\317\202 \316\232\316\261\317\201\316\255 (0-10):", nullptr));
        applyToImageCheckBox->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\223\316\271\316\261 \316\265\316\276\316\261\316\263\317\211\316\263\316\256 \316\265\316\271\316\272\317\214\316\275\317\211\316\275.", nullptr));
        applyToVideoCheckBox->setText(QCoreApplication::translate("FaceDetectionDialog", "\316\223\316\271\316\261 \316\265\316\275\317\204\316\277\317\200\316\271\317\203\316\274\317\214 \317\200\317\201\316\277\317\203\317\216\317\200\317\211\316\275.", nullptr));
        frameskipHelpButton->setText(QCoreApplication::translate("FaceDetectionDialog", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceDetectionDialog: public Ui_FaceDetectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEDETECTIONDIALOG_H
