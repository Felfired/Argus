/********************************************************************************
** Form generated from reading UI file 'configfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGFILEDIALOG_H
#define UI_CONFIGFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigFileDialog
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar;
    QPushButton *openButton;
    QLineEdit *filepathLineEdit;
    QPushButton *applyButton;
    QPushButton *cancelButton;
    QLabel *filenameLabel;
    QLabel *fileLabel;
    QLabel *filesizeLabel;
    QGroupBox *descriptionGroupBox;
    QLabel *descriptionLabel;
    QLabel *sizeLabel;

    void setupUi(QDialog *ConfigFileDialog)
    {
        if (ConfigFileDialog->objectName().isEmpty())
            ConfigFileDialog->setObjectName("ConfigFileDialog");
        ConfigFileDialog->resize(562, 356);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigFileDialog->setWindowIcon(icon);
        ConfigFileDialog->setAutoFillBackground(false);
        scrollArea = new QScrollArea(ConfigFileDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(310, 20, 241, 281));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 239, 279));
        textBrowser = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 0, 241, 281));
        scrollArea->setWidget(scrollAreaWidgetContents);
        progressBar = new QProgressBar(ConfigFileDialog);
        progressBar->setObjectName("progressBar");
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(10, 300, 271, 21));
        progressBar->setValue(24);
        progressBar->setInvertedAppearance(false);
        openButton = new QPushButton(ConfigFileDialog);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(10, 20, 25, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("res/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon1);
        filepathLineEdit = new QLineEdit(ConfigFileDialog);
        filepathLineEdit->setObjectName("filepathLineEdit");
        filepathLineEdit->setGeometry(QRect(40, 20, 231, 25));
        applyButton = new QPushButton(ConfigFileDialog);
        applyButton->setObjectName("applyButton");
        applyButton->setGeometry(QRect(380, 320, 81, 24));
        cancelButton = new QPushButton(ConfigFileDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(470, 320, 81, 24));
        filenameLabel = new QLabel(ConfigFileDialog);
        filenameLabel->setObjectName("filenameLabel");
        filenameLabel->setGeometry(QRect(10, 60, 91, 16));
        QFont font;
        font.setBold(true);
        filenameLabel->setFont(font);
        fileLabel = new QLabel(ConfigFileDialog);
        fileLabel->setObjectName("fileLabel");
        fileLabel->setGeometry(QRect(10, 80, 251, 16));
        filesizeLabel = new QLabel(ConfigFileDialog);
        filesizeLabel->setObjectName("filesizeLabel");
        filesizeLabel->setGeometry(QRect(10, 110, 91, 16));
        filesizeLabel->setFont(font);
        descriptionGroupBox = new QGroupBox(ConfigFileDialog);
        descriptionGroupBox->setObjectName("descriptionGroupBox");
        descriptionGroupBox->setGeometry(QRect(10, 170, 261, 101));
        QFont font1;
        font1.setBold(false);
        descriptionGroupBox->setFont(font1);
        descriptionGroupBox->setFlat(false);
        descriptionLabel = new QLabel(descriptionGroupBox);
        descriptionLabel->setObjectName("descriptionLabel");
        descriptionLabel->setGeometry(QRect(10, 20, 251, 71));
        descriptionLabel->setTextFormat(Qt::PlainText);
        descriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        descriptionLabel->setWordWrap(true);
        sizeLabel = new QLabel(ConfigFileDialog);
        sizeLabel->setObjectName("sizeLabel");
        sizeLabel->setGeometry(QRect(10, 130, 251, 16));

        retranslateUi(ConfigFileDialog);

        QMetaObject::connectSlotsByName(ConfigFileDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigFileDialog)
    {
        ConfigFileDialog->setWindowTitle(QCoreApplication::translate("ConfigFileDialog", "\316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202 \316\221\317\201\317\207\316\265\316\257\316\277\317\205 \316\240\316\261\317\201\316\261\316\274\316\265\317\204\317\201\316\277\317\200\316\277\316\271\316\256\317\203\316\265\317\211\316\275", nullptr));
        openButton->setText(QString());
        applyButton->setText(QCoreApplication::translate("ConfigFileDialog", "\316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267", nullptr));
        cancelButton->setText(QCoreApplication::translate("ConfigFileDialog", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", nullptr));
        filenameLabel->setText(QCoreApplication::translate("ConfigFileDialog", "\316\214\316\275\316\277\316\274\316\261 \316\221\317\201\317\207\316\265\316\257\316\277\317\205:", nullptr));
        fileLabel->setText(QString());
        filesizeLabel->setText(QCoreApplication::translate("ConfigFileDialog", "\316\234\316\255\316\263\316\265\316\270\316\277\317\202:", nullptr));
        descriptionGroupBox->setTitle(QCoreApplication::translate("ConfigFileDialog", "\316\240\316\265\317\201\316\271\316\263\317\201\316\261\317\206\316\256", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("ConfigFileDialog", "\316\244\316\277 \316\261\317\201\317\207\316\265\316\257\316\277 \317\200\316\261\317\201\316\261\316\274\316\265\317\204\317\201\316\277\317\200\316\277\316\271\316\256\317\203\316\265\317\211\316\275 \317\200\316\265\317\201\316\271\316\273\316\261\316\274\316\262\316\254\316\275\316\265\316\271 \317\214\316\273\316\265\317\202 \317\204\316\271\317\202 \317\203\317\207\316\265\317\204\316\271\316\272\316\255\317\202 \317\201\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202 \317\200\316\277\317\205 \317\207\317\201\316\265\316\271\316\254\316\266\316\265\317\204\316\261\316\271 \317\204\316\277 \316\275\316\265\317\205\317\201\317\211\316\275\316\271\316\272\317\214 \316\264\316\257\316\272\317\204\317\205\316\277 \316\263\316\271\316\261 \317\204\316\267\316\275 \316\273\316\265\316\271\317\204\316\277\317\205\317\201\316\263\316\257\316\261 \317\204\316\277\317\205.", nullptr));
        sizeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ConfigFileDialog: public Ui_ConfigFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGFILEDIALOG_H
