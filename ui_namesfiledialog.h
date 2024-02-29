/********************************************************************************
** Form generated from reading UI file 'namesfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMESFILEDIALOG_H
#define UI_NAMESFILEDIALOG_H

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

class Ui_NamesFileDialog
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

    void setupUi(QDialog *NamesFileDialog)
    {
        if (NamesFileDialog->objectName().isEmpty())
            NamesFileDialog->setObjectName("NamesFileDialog");
        NamesFileDialog->resize(572, 356);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/icons/object-alignment.png"), QSize(), QIcon::Normal, QIcon::Off);
        NamesFileDialog->setWindowIcon(icon);
        NamesFileDialog->setAutoFillBackground(false);
        scrollArea = new QScrollArea(NamesFileDialog);
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
        progressBar = new QProgressBar(NamesFileDialog);
        progressBar->setObjectName("progressBar");
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(10, 300, 271, 21));
        progressBar->setValue(24);
        progressBar->setInvertedAppearance(false);
        openButton = new QPushButton(NamesFileDialog);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(10, 20, 25, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("res/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon1);
        filepathLineEdit = new QLineEdit(NamesFileDialog);
        filepathLineEdit->setObjectName("filepathLineEdit");
        filepathLineEdit->setGeometry(QRect(40, 20, 231, 25));
        applyButton = new QPushButton(NamesFileDialog);
        applyButton->setObjectName("applyButton");
        applyButton->setGeometry(QRect(380, 320, 81, 24));
        cancelButton = new QPushButton(NamesFileDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(470, 320, 81, 24));
        filenameLabel = new QLabel(NamesFileDialog);
        filenameLabel->setObjectName("filenameLabel");
        filenameLabel->setGeometry(QRect(10, 60, 91, 16));
        QFont font;
        font.setBold(true);
        filenameLabel->setFont(font);
        fileLabel = new QLabel(NamesFileDialog);
        fileLabel->setObjectName("fileLabel");
        fileLabel->setGeometry(QRect(10, 80, 251, 16));
        filesizeLabel = new QLabel(NamesFileDialog);
        filesizeLabel->setObjectName("filesizeLabel");
        filesizeLabel->setGeometry(QRect(10, 110, 91, 16));
        filesizeLabel->setFont(font);
        descriptionGroupBox = new QGroupBox(NamesFileDialog);
        descriptionGroupBox->setObjectName("descriptionGroupBox");
        descriptionGroupBox->setGeometry(QRect(10, 170, 261, 101));
        QFont font1;
        font1.setBold(false);
        descriptionGroupBox->setFont(font1);
        descriptionGroupBox->setFlat(false);
        descriptionLabel = new QLabel(descriptionGroupBox);
        descriptionLabel->setObjectName("descriptionLabel");
        descriptionLabel->setGeometry(QRect(10, 20, 231, 71));
        descriptionLabel->setTextFormat(Qt::PlainText);
        descriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        descriptionLabel->setWordWrap(true);
        sizeLabel = new QLabel(NamesFileDialog);
        sizeLabel->setObjectName("sizeLabel");
        sizeLabel->setGeometry(QRect(10, 130, 251, 16));

        retranslateUi(NamesFileDialog);

        QMetaObject::connectSlotsByName(NamesFileDialog);
    } // setupUi

    void retranslateUi(QDialog *NamesFileDialog)
    {
        NamesFileDialog->setWindowTitle(QCoreApplication::translate("NamesFileDialog", "\316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202 \316\221\317\201\317\207\316\265\316\257\316\277\317\205 \316\237\316\275\316\277\316\274\316\254\317\204\317\211\316\275", nullptr));
        openButton->setText(QString());
        applyButton->setText(QCoreApplication::translate("NamesFileDialog", "\316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267", nullptr));
        cancelButton->setText(QCoreApplication::translate("NamesFileDialog", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", nullptr));
        filenameLabel->setText(QCoreApplication::translate("NamesFileDialog", "\316\214\316\275\316\277\316\274\316\261 \316\221\317\201\317\207\316\265\316\257\316\277\317\205:", nullptr));
        fileLabel->setText(QString());
        filesizeLabel->setText(QCoreApplication::translate("NamesFileDialog", "\316\234\316\255\316\263\316\265\316\270\316\277\317\202:", nullptr));
        descriptionGroupBox->setTitle(QCoreApplication::translate("NamesFileDialog", "\316\240\316\265\317\201\316\271\316\263\317\201\316\261\317\206\316\256", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("NamesFileDialog", "\316\244\316\277 \317\203\317\205\316\263\316\272\316\265\316\272\317\201\316\271\316\274\316\255\316\275\316\277 \316\261\317\201\317\207\316\265\316\257\316\277 \317\200\316\265\317\201\316\271\316\273\316\261\316\274\316\262\316\254\316\275\316\265\316\271 \316\274\316\271\316\261 \316\273\316\257\317\203\317\204\316\261 \316\274\316\265 \317\204\316\261 \316\261\316\275\317\204\316\271\316\272\316\265\316\257\316\274\316\265\316\275\316\261 \317\200\316\277\317\205 \316\274\317\200\316\277\317\201\316\277\317\215\316\275 \316\275\316\261 \316\261\316\275\316\261\316\263\316\275\317\211\317\201\316\271\317\203\317\204\316\277\317\215\316\275 \316\261\317\200\316\277 \317\204\316\277\316\275 \316\261\316\273\316\263\317\214\317\201\316\271\316\270\316\274\316\277 \316\265\316\275\317\204\316\277\317\200\316\271\317\203\316\274\316\277\317\215.", nullptr));
        sizeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NamesFileDialog: public Ui_NamesFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMESFILEDIALOG_H
