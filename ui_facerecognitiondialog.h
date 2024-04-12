/********************************************************************************
** Form generated from reading UI file 'facerecognitiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACERECOGNITIONDIALOG_H
#define UI_FACERECOGNITIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceRecognitionDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label_2;
    QComboBox *distanceCalculationComboBox;
    QTableWidget *resultsTableWidget;
    QLabel *label;
    QGroupBox *groupBox_2;
    QPushButton *selectFolderButton;
    QLineEdit *folderDisplayLineEdit;
    QCheckBox *saveToTextCheckBox;
    QCheckBox *deleteDuplicateCheckBox;
    QProgressBar *progressBar;
    QDialogButtonBox *buttonBox;
    QToolButton *stopButton;

    void setupUi(QDialog *FaceRecognitionDialog)
    {
        if (FaceRecognitionDialog->objectName().isEmpty())
            FaceRecognitionDialog->setObjectName("FaceRecognitionDialog");
        FaceRecognitionDialog->resize(743, 391);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/argus/res/app_icons/recognition.png"), QSize(), QIcon::Normal, QIcon::Off);
        FaceRecognitionDialog->setWindowIcon(icon);
        tabWidget = new QTabWidget(FaceRecognitionDialog);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 461, 151));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 441, 101));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 141, 16));
        distanceCalculationComboBox = new QComboBox(groupBox);
        distanceCalculationComboBox->setObjectName("distanceCalculationComboBox");
        distanceCalculationComboBox->setGeometry(QRect(150, 29, 121, 22));
        tabWidget->addTab(tab, QString());
        resultsTableWidget = new QTableWidget(FaceRecognitionDialog);
        resultsTableWidget->setObjectName("resultsTableWidget");
        resultsTableWidget->setGeometry(QRect(480, 40, 241, 301));
        label = new QLabel(FaceRecognitionDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(480, 10, 231, 20));
        QFont font;
        font.setBold(false);
        font.setItalic(true);
        label->setFont(font);
        groupBox_2 = new QGroupBox(FaceRecognitionDialog);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 170, 461, 171));
        selectFolderButton = new QPushButton(groupBox_2);
        selectFolderButton->setObjectName("selectFolderButton");
        selectFolderButton->setGeometry(QRect(10, 30, 111, 24));
        folderDisplayLineEdit = new QLineEdit(groupBox_2);
        folderDisplayLineEdit->setObjectName("folderDisplayLineEdit");
        folderDisplayLineEdit->setGeometry(QRect(130, 30, 321, 23));
        saveToTextCheckBox = new QCheckBox(groupBox_2);
        saveToTextCheckBox->setObjectName("saveToTextCheckBox");
        saveToTextCheckBox->setGeometry(QRect(13, 70, 271, 20));
        deleteDuplicateCheckBox = new QCheckBox(groupBox_2);
        deleteDuplicateCheckBox->setObjectName("deleteDuplicateCheckBox");
        deleteDuplicateCheckBox->setGeometry(QRect(13, 100, 411, 20));
        progressBar = new QProgressBar(FaceRecognitionDialog);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(40, 350, 431, 21));
        progressBar->setValue(24);
        buttonBox = new QDialogButtonBox(FaceRecognitionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(565, 350, 156, 24));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stopButton = new QToolButton(FaceRecognitionDialog);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(9, 347, 25, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/argus/res/app_icons/x.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);

        retranslateUi(FaceRecognitionDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FaceRecognitionDialog);
    } // setupUi

    void retranslateUi(QDialog *FaceRecognitionDialog)
    {
        FaceRecognitionDialog->setWindowTitle(QCoreApplication::translate("FaceRecognitionDialog", "\316\221\316\275\316\261\316\263\316\275\317\216\317\201\316\271\317\203\316\267 \316\240\317\201\316\277\317\203\317\216\317\200\317\211\316\275", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FaceRecognitionDialog", "\316\240\316\261\317\201\316\254\316\274\316\265\317\204\317\201\316\277\316\271", nullptr));
        label_2->setText(QCoreApplication::translate("FaceRecognitionDialog", "\316\221\316\273\316\263\317\214\317\201\316\271\316\270\316\274\316\277\317\202 \316\221\317\200\317\214\317\203\317\204\316\261\317\203\316\267\317\202:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FaceRecognitionDialog", "SFace", nullptr));
        label->setText(QCoreApplication::translate("FaceRecognitionDialog", "\316\225\317\200\316\271\317\204\317\205\317\207\316\267\316\274\316\255\316\275\316\261 \316\247\317\204\317\205\317\200\316\256\316\274\316\261\317\204\316\261", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FaceRecognitionDialog", "\316\223\316\265\316\275\316\271\316\272\316\255\317\202 \316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202", nullptr));
        selectFolderButton->setText(QCoreApplication::translate("FaceRecognitionDialog", "\316\225\317\200\316\271\316\273\316\277\316\263\316\256 \316\246\316\261\316\272\316\255\316\273\316\277\317\205", nullptr));
        saveToTextCheckBox->setText(QCoreApplication::translate("FaceRecognitionDialog", "\316\225\316\276\316\261\316\263\317\211\316\263\316\256 \316\261\317\200\316\277\317\204\316\265\316\273\316\265\317\203\316\274\316\254\317\204\317\211\316\275 \317\203\316\265 \316\261\317\201\317\207\316\265\316\257\316\277 \316\272\316\265\316\271\316\274\316\255\316\275\316\277\317\205.", nullptr));
        deleteDuplicateCheckBox->setText(QCoreApplication::translate("FaceRecognitionDialog", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256 \316\264\316\271\317\200\316\273\317\214\317\204\317\205\317\200\317\211\316\275 \316\265\316\271\316\272\317\214\316\275\317\211\316\275 \317\203\316\265 \317\200\316\265\317\201\316\257\317\200\317\204\317\211\317\203\316\267 \316\265\317\200\316\271\317\204\317\205\317\207\316\277\317\215\317\202 \316\261\316\275\316\261\316\263\316\275\317\216\317\201\316\271\317\203\316\267\317\202.", nullptr));
        stopButton->setText(QCoreApplication::translate("FaceRecognitionDialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceRecognitionDialog: public Ui_FaceRecognitionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACERECOGNITIONDIALOG_H
