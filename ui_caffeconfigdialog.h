/********************************************************************************
** Form generated from reading UI file 'caffeconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAFFECONFIGDIALOG_H
#define UI_CAFFECONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaffeConfigDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QPushButton *openModelFileButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *modelFPLineEdit;
    QGroupBox *groupBox_2;
    QLineEdit *configFPLineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *openConfigFileButton;
    QLabel *label_7;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QPushButton *openYunetFileButton;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *yunetFPLineEdit;
    QLabel *label_8;
    QPushButton *closeButton;
    QPushButton *saveButton;

    void setupUi(QDialog *CaffeConfigDialog)
    {
        if (CaffeConfigDialog->objectName().isEmpty())
            CaffeConfigDialog->setObjectName("CaffeConfigDialog");
        CaffeConfigDialog->resize(440, 407);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/argus/res/app_icons/caffe_settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        CaffeConfigDialog->setWindowIcon(icon);
        tabWidget = new QTabWidget(CaffeConfigDialog);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 10, 401, 351));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 60, 371, 121));
        openModelFileButton = new QPushButton(groupBox);
        openModelFileButton->setObjectName("openModelFileButton");
        openModelFileButton->setGeometry(QRect(10, 80, 75, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 32, 32));
        label->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/app_icons/caffe_dialog.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 20, 311, 41));
        label_2->setWordWrap(true);
        modelFPLineEdit = new QLineEdit(groupBox);
        modelFPLineEdit->setObjectName("modelFPLineEdit");
        modelFPLineEdit->setGeometry(QRect(100, 80, 261, 21));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 190, 371, 121));
        configFPLineEdit = new QLineEdit(groupBox_2);
        configFPLineEdit->setObjectName("configFPLineEdit");
        configFPLineEdit->setGeometry(QRect(100, 80, 261, 21));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 30, 32, 32));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/app_icons/caffe_dialog_config.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 20, 311, 41));
        label_4->setWordWrap(true);
        openConfigFileButton = new QPushButton(groupBox_2);
        openConfigFileButton->setObjectName("openConfigFileButton");
        openConfigFileButton->setGeometry(QRect(10, 80, 75, 24));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 10, 371, 31));
        label_7->setWordWrap(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 60, 371, 121));
        openYunetFileButton = new QPushButton(groupBox_3);
        openYunetFileButton->setObjectName("openYunetFileButton");
        openYunetFileButton->setGeometry(QRect(10, 80, 75, 24));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 30, 32, 32));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/app_icons/caffe_dialog.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 20, 311, 41));
        label_6->setWordWrap(true);
        yunetFPLineEdit = new QLineEdit(groupBox_3);
        yunetFPLineEdit->setObjectName("yunetFPLineEdit");
        yunetFPLineEdit->setGeometry(QRect(100, 80, 261, 21));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 10, 371, 31));
        label_8->setWordWrap(true);
        tabWidget->addTab(tab_2, QString());
        closeButton = new QPushButton(CaffeConfigDialog);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(350, 370, 75, 24));
        saveButton = new QPushButton(CaffeConfigDialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(264, 370, 81, 24));

        retranslateUi(CaffeConfigDialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CaffeConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *CaffeConfigDialog)
    {
        CaffeConfigDialog->setWindowTitle(QCoreApplication::translate("CaffeConfigDialog", "\316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202 \316\234\316\277\316\275\317\204\316\255\316\273\316\277\317\205 \316\225\316\275\317\204\316\277\317\200\316\271\317\203\316\274\316\277\317\215 \316\240\317\201\316\277\317\203\317\216\317\200\317\211\316\275", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CaffeConfigDialog", "\316\221\317\201\317\207\316\265\316\257\316\277 \316\234\316\277\316\275\317\204\316\255\316\273\316\277\317\205", nullptr));
        openModelFileButton->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\206\316\275\316\277\316\271\316\263\316\274\316\261...", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\225\316\264\317\216 \316\265\316\271\317\203\316\254\316\263\316\265\317\204\316\265 \317\204\316\277 \316\261\317\201\317\207\316\265\316\257\316\277 \317\204\316\277\317\205 \316\265\316\272\317\200\316\261\316\271\316\264\316\265\317\205\316\274\316\255\316\275\316\277\317\205 \316\274\316\277\316\275\317\204\316\255\316\273\316\277\317\205 \316\265\316\275\317\204\316\277\317\200\316\271\317\203\316\274\316\277\317\215 \317\200\317\201\316\277\317\203\317\216\317\200\317\211\316\275.", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CaffeConfigDialog", "\316\221\317\201\317\207\316\265\316\257\316\277 \316\240\316\261\317\201\316\261\316\274\316\265\317\204\317\201\316\277\317\200\316\277\316\271\316\256\317\203\316\265\317\211\316\275", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\225\316\264\317\216 \316\265\316\271\317\203\316\254\316\263\316\265\317\204\316\265 \317\204\316\277 \316\261\317\201\317\207\316\265\316\257\316\277 \317\200\316\261\317\201\316\261\316\274\316\265\317\204\317\201\316\277\317\200\316\277\316\271\316\256\317\203\316\265\317\211\316\275 \317\204\316\277\317\205 \316\274\316\277\316\275\317\204\316\255\316\273\316\277\317\205 \316\265\316\275\317\204\316\277\317\200\316\271\317\203\316\274\316\277\317\215 \317\200\317\201\316\277\317\203\317\216\317\200\317\211\316\275.", nullptr));
        openConfigFileButton->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\206\316\275\316\277\316\271\316\263\316\274\316\261...", nullptr));
        label_7->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\243\317\204\316\267 \317\203\317\205\316\263\316\272\316\265\316\272\317\201\316\271\316\274\316\255\316\275\316\267 \317\203\316\265\316\273\316\257\316\264\316\261 \316\274\317\200\316\277\317\201\316\265\316\257\317\204\316\265 \316\275\316\261 \316\265\316\271\317\203\316\254\316\263\316\265\317\204\316\265 \317\204\316\261 \316\261\317\200\316\261\317\201\316\261\316\257\317\204\316\267\317\204\316\261 \316\261\317\201\317\207\316\265\316\257\316\261 \316\263\316\271\316\261 \317\204\316\277 \316\274\316\277\316\275\317\204\316\255\316\273\316\277 \"Caffe\".", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CaffeConfigDialog", "\316\221\317\201\317\207\316\265\316\257\316\261 \316\234\316\277\316\275\317\204\316\255\316\273\316\277\317\205 (Caffe)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("CaffeConfigDialog", "\316\221\317\201\317\207\316\265\316\257\316\277 \316\234\316\277\316\275\317\204\316\255\316\273\316\277\317\205", nullptr));
        openYunetFileButton->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\206\316\275\316\277\316\271\316\263\316\274\316\261...", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\225\316\264\317\216 \316\265\316\271\317\203\316\254\316\263\316\265\317\204\316\265 \317\204\316\277 \316\261\317\201\317\207\316\265\316\257\316\277 \317\204\316\277\317\205 \316\265\316\272\317\200\316\261\316\271\316\264\316\265\317\205\316\274\316\255\316\275\316\277\317\205 \316\274\316\277\316\275\317\204\316\255\316\273\316\277\317\205 \316\265\316\275\317\204\316\277\317\200\316\271\317\203\316\274\316\277\317\215 \317\200\317\201\316\277\317\203\317\216\317\200\317\211\316\275.", nullptr));
        label_8->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\243\317\204\316\267 \317\203\317\205\316\263\316\272\316\265\316\272\317\201\316\271\316\274\316\255\316\275\316\267 \317\203\316\265\316\273\316\257\316\264\316\261 \316\274\317\200\316\277\317\201\316\265\316\257\317\204\316\265 \316\275\316\261 \316\265\316\271\317\203\316\254\316\263\316\265\317\204\316\265 \317\204\316\261 \316\261\317\200\316\261\317\201\316\261\316\257\317\204\316\267\317\204\316\261 \316\261\317\201\317\207\316\265\316\257\316\261 \316\263\316\271\316\261 \317\204\316\277 \316\274\316\277\316\275\317\204\316\255\316\273\316\277 \"YuNet\".", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CaffeConfigDialog", "\316\221\317\201\317\207\316\265\316\257\316\261 \316\234\316\277\316\275\317\204\316\255\316\273\316\277\317\205 (YuNet)", nullptr));
        closeButton->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\232\316\273\316\265\316\257\317\203\316\271\316\274\316\277", nullptr));
        saveButton->setText(QCoreApplication::translate("CaffeConfigDialog", "\316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CaffeConfigDialog: public Ui_CaffeConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAFFECONFIGDIALOG_H
