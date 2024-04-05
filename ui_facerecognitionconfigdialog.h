/********************************************************************************
** Form generated from reading UI file 'facerecognitionconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACERECOGNITIONCONFIGDIALOG_H
#define UI_FACERECOGNITIONCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceRecognitionConfigDialog
{
public:
    QPushButton *saveButton;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QPushButton *openSfaceFileButton;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *sfaceFPLineEdit;
    QLabel *label_8;
    QPushButton *closeButton;

    void setupUi(QDialog *FaceRecognitionConfigDialog)
    {
        if (FaceRecognitionConfigDialog->objectName().isEmpty())
            FaceRecognitionConfigDialog->setObjectName("FaceRecognitionConfigDialog");
        FaceRecognitionConfigDialog->resize(417, 401);
        saveButton = new QPushButton(FaceRecognitionConfigDialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(240, 370, 81, 24));
        tabWidget = new QTabWidget(FaceRecognitionConfigDialog);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 401, 351));
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 60, 371, 121));
        openSfaceFileButton = new QPushButton(groupBox_3);
        openSfaceFileButton->setObjectName("openSfaceFileButton");
        openSfaceFileButton->setGeometry(QRect(10, 80, 75, 24));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 30, 32, 32));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/app_icons/view_image.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 20, 311, 41));
        label_6->setWordWrap(true);
        sfaceFPLineEdit = new QLineEdit(groupBox_3);
        sfaceFPLineEdit->setObjectName("sfaceFPLineEdit");
        sfaceFPLineEdit->setGeometry(QRect(100, 80, 261, 21));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 10, 371, 31));
        label_8->setWordWrap(true);
        tabWidget->addTab(tab_2, QString());
        closeButton = new QPushButton(FaceRecognitionConfigDialog);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(330, 370, 75, 24));

        retranslateUi(FaceRecognitionConfigDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FaceRecognitionConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *FaceRecognitionConfigDialog)
    {
        FaceRecognitionConfigDialog->setWindowTitle(QCoreApplication::translate("FaceRecognitionConfigDialog", "Dialog", nullptr));
        saveButton->setText(QCoreApplication::translate("FaceRecognitionConfigDialog", "\316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FaceRecognitionConfigDialog", "\316\221\317\201\317\207\316\265\316\257\316\277 \316\234\316\277\316\275\317\204\316\255\316\273\316\277\317\205", nullptr));
        openSfaceFileButton->setText(QCoreApplication::translate("FaceRecognitionConfigDialog", "\316\206\316\275\316\277\316\271\316\263\316\274\316\261...", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("FaceRecognitionConfigDialog", "\316\225\316\264\317\216 \316\265\316\271\317\203\316\254\316\263\316\265\317\204\316\265 \317\204\316\277 \316\261\317\201\317\207\316\265\316\257\316\277 \317\204\316\277\317\205 \316\265\316\272\317\200\316\261\316\271\316\264\316\265\317\205\316\274\316\255\316\275\316\277\317\205 \316\274\316\277\316\275\317\204\316\255\316\273\316\277\317\205 \316\261\316\275\316\261\316\263\316\275\317\216\317\201\316\271\317\203\316\267\317\202 \317\200\317\201\316\277\317\203\317\216\317\200\317\211\316\275.", nullptr));
        label_8->setText(QCoreApplication::translate("FaceRecognitionConfigDialog", "\316\243\317\204\316\267 \317\203\317\205\316\263\316\272\316\265\316\272\317\201\316\271\316\274\316\255\316\275\316\267 \317\203\316\265\316\273\316\257\316\264\316\261 \316\274\317\200\316\277\317\201\316\265\316\257\317\204\316\265 \316\275\316\261 \316\265\316\271\317\203\316\254\316\263\316\265\317\204\316\265 \317\204\316\261 \316\261\317\200\316\261\317\201\316\261\316\257\317\204\316\267\317\204\316\261 \316\261\317\201\317\207\316\265\316\257\316\261 \316\263\316\271\316\261 \317\204\316\277 \316\274\316\277\316\275\317\204\316\255\316\273\316\277 \"SFace\".", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FaceRecognitionConfigDialog", "\316\221\317\201\317\207\316\265\316\257\316\261 \316\234\316\277\316\275\317\204\316\255\316\273\316\277\317\205 (SFace)", nullptr));
        closeButton->setText(QCoreApplication::translate("FaceRecognitionConfigDialog", "\316\232\316\273\316\265\316\257\317\203\316\271\316\274\316\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceRecognitionConfigDialog: public Ui_FaceRecognitionConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACERECOGNITIONCONFIGDIALOG_H
