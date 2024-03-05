/********************************************************************************
** Form generated from reading UI file 'saveconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVECONFIGDIALOG_H
#define UI_SAVECONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveConfigDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *applyButton;
    QPushButton *cancelButton;
    QTabWidget *tabWidget;
    QWidget *tabGeneral;
    QGroupBox *groupBox;
    QLineEdit *catalogFolderDisplay;
    QPushButton *catalogFolderSelect;
    QLabel *catalogDescLabel;
    QLabel *catalogImageLabel;
    QGroupBox *groupBox_2;
    QLineEdit *resultsFolderDisplay;
    QPushButton *resultsFolderSelect;
    QLabel *resultsDescLabel;
    QLabel *resultsImageLabel;

    void setupUi(QDialog *SaveConfigDialog)
    {
        if (SaveConfigDialog->objectName().isEmpty())
            SaveConfigDialog->setObjectName("SaveConfigDialog");
        SaveConfigDialog->setWindowModality(Qt::ApplicationModal);
        SaveConfigDialog->resize(440, 407);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/app_icons/diskette.png"), QSize(), QIcon::Normal, QIcon::Off);
        SaveConfigDialog->setWindowIcon(icon);
        layoutWidget = new QWidget(SaveConfigDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 360, 421, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName("hboxLayout");
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        applyButton = new QPushButton(layoutWidget);
        applyButton->setObjectName("applyButton");

        hboxLayout->addWidget(applyButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName("cancelButton");

        hboxLayout->addWidget(cancelButton);

        tabWidget = new QTabWidget(SaveConfigDialog);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 421, 331));
        tabGeneral = new QWidget();
        tabGeneral->setObjectName("tabGeneral");
        groupBox = new QGroupBox(tabGeneral);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 401, 121));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        catalogFolderDisplay = new QLineEdit(groupBox);
        catalogFolderDisplay->setObjectName("catalogFolderDisplay");
        catalogFolderDisplay->setGeometry(QRect(150, 80, 231, 22));
        catalogFolderSelect = new QPushButton(groupBox);
        catalogFolderSelect->setObjectName("catalogFolderSelect");
        catalogFolderSelect->setGeometry(QRect(20, 80, 121, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("res/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        catalogFolderSelect->setIcon(icon1);
        catalogDescLabel = new QLabel(groupBox);
        catalogDescLabel->setObjectName("catalogDescLabel");
        catalogDescLabel->setGeometry(QRect(70, 30, 271, 32));
        catalogDescLabel->setFrameShape(QFrame::NoFrame);
        catalogDescLabel->setFrameShadow(QFrame::Plain);
        catalogDescLabel->setWordWrap(true);
        catalogDescLabel->setMargin(0);
        catalogDescLabel->setIndent(-1);
        catalogImageLabel = new QLabel(groupBox);
        catalogImageLabel->setObjectName("catalogImageLabel");
        catalogImageLabel->setGeometry(QRect(20, 30, 32, 32));
        catalogImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/app_icons/save_folder.png")));
        catalogImageLabel->setScaledContents(true);
        groupBox_2 = new QGroupBox(tabGeneral);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 150, 401, 141));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        resultsFolderDisplay = new QLineEdit(groupBox_2);
        resultsFolderDisplay->setObjectName("resultsFolderDisplay");
        resultsFolderDisplay->setGeometry(QRect(150, 100, 231, 22));
        resultsFolderSelect = new QPushButton(groupBox_2);
        resultsFolderSelect->setObjectName("resultsFolderSelect");
        resultsFolderSelect->setGeometry(QRect(20, 100, 121, 24));
        resultsFolderSelect->setIcon(icon1);
        resultsDescLabel = new QLabel(groupBox_2);
        resultsDescLabel->setObjectName("resultsDescLabel");
        resultsDescLabel->setGeometry(QRect(70, 30, 271, 51));
        resultsDescLabel->setFrameShape(QFrame::NoFrame);
        resultsDescLabel->setFrameShadow(QFrame::Plain);
        resultsDescLabel->setWordWrap(true);
        resultsDescLabel->setMargin(0);
        resultsDescLabel->setIndent(-1);
        resultsImageLabel = new QLabel(groupBox_2);
        resultsImageLabel->setObjectName("resultsImageLabel");
        resultsImageLabel->setGeometry(QRect(20, 30, 32, 32));
        resultsImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/app_icons/results_folder.png")));
        resultsImageLabel->setScaledContents(true);
        tabWidget->addTab(tabGeneral, QString());

        retranslateUi(SaveConfigDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SaveConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveConfigDialog)
    {
        SaveConfigDialog->setWindowTitle(QCoreApplication::translate("SaveConfigDialog", "\316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202 \316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267\317\202", nullptr));
        applyButton->setText(QCoreApplication::translate("SaveConfigDialog", "\316\225\317\206\316\261\317\201\316\274\316\277\316\263\316\256", nullptr));
        cancelButton->setText(QCoreApplication::translate("SaveConfigDialog", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SaveConfigDialog", "\316\244\316\277\317\200\316\277\316\270\316\265\317\203\316\257\316\261 \316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267\317\202 \316\232\316\261\317\204\316\261\316\273\317\214\316\263\316\277\317\205", nullptr));
        catalogFolderSelect->setText(QCoreApplication::translate("SaveConfigDialog", "\316\225\317\200\316\271\316\273\316\277\316\263\316\256 \316\246\316\261\316\272\316\255\316\273\316\277\317\205...", nullptr));
        catalogDescLabel->setText(QCoreApplication::translate("SaveConfigDialog", "\316\225\316\264\317\216 \316\274\317\200\316\277\317\201\316\265\316\257\317\204\316\265 \316\275\316\261 \316\277\317\201\316\257\317\203\316\265\317\204\316\265 \317\204\316\267\316\275 \317\204\316\277\317\200\316\277\316\270\316\265\317\203\316\257\316\261 \317\214\317\200\316\277\317\205 \316\270\316\261 \316\261\317\200\316\277\316\270\316\267\316\272\316\265\317\215\316\277\316\275\317\204\316\261\316\271 \317\204\316\261 \316\264\316\265\316\264\316\277\316\274\316\255\316\275\316\261 \317\204\317\211\316\275 \316\261\317\204\317\214\316\274\317\211\316\275.", nullptr));
        catalogImageLabel->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("SaveConfigDialog", "\316\244\316\277\317\200\316\277\316\270\316\265\317\203\316\257\316\261 \316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267\317\202 \316\221\317\200\316\277\317\204\316\265\316\273\316\265\317\203\316\274\316\254\317\204\317\211\316\275", nullptr));
        resultsFolderSelect->setText(QCoreApplication::translate("SaveConfigDialog", "\316\225\317\200\316\271\316\273\316\277\316\263\316\256 \316\246\316\261\316\272\316\255\316\273\316\277\317\205...", nullptr));
        resultsDescLabel->setText(QCoreApplication::translate("SaveConfigDialog", "\316\225\316\264\317\216 \316\274\317\200\316\277\317\201\316\265\316\257\317\204\316\265 \316\275\316\261 \316\277\317\201\316\257\317\203\316\265\317\204\316\265 \317\204\316\267\316\275 \317\204\316\277\317\200\316\277\316\270\316\265\317\203\316\257\316\261 \317\214\317\200\316\277\317\205 \316\270\316\261 \316\261\317\200\316\277\316\270\316\267\316\272\316\265\317\215\316\277\316\275\317\204\316\261\316\271 \317\204\316\261 \316\261\317\200\316\277\317\204\316\265\316\273\316\255\317\203\316\274\316\261\317\204\316\261 \316\261\317\200\316\277 \317\204\316\267\316\275 \316\261\316\275\316\257\317\207\316\275\316\265\317\205\317\203\316\267 \316\272\316\257\316\275\316\267\317\203\316\267\317\202.", nullptr));
        resultsImageLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabGeneral), QCoreApplication::translate("SaveConfigDialog", "\316\223\316\265\316\275\316\271\316\272\316\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveConfigDialog: public Ui_SaveConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVECONFIGDIALOG_H
