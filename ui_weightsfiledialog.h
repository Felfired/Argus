/********************************************************************************
** Form generated from reading UI file 'weightsfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEIGHTSFILEDIALOG_H
#define UI_WEIGHTSFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WeightsFileDialog
{
public:
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

    void setupUi(QDialog *WeightsFileDialog)
    {
        if (WeightsFileDialog->objectName().isEmpty())
            WeightsFileDialog->setObjectName("WeightsFileDialog");
        WeightsFileDialog->resize(339, 367);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/icons/weigh-scale.png"), QSize(), QIcon::Normal, QIcon::Off);
        WeightsFileDialog->setWindowIcon(icon);
        WeightsFileDialog->setAutoFillBackground(false);
        progressBar = new QProgressBar(WeightsFileDialog);
        progressBar->setObjectName("progressBar");
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(10, 290, 321, 21));
        progressBar->setValue(24);
        progressBar->setInvertedAppearance(false);
        openButton = new QPushButton(WeightsFileDialog);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(10, 20, 25, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("res/app_icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon1);
        filepathLineEdit = new QLineEdit(WeightsFileDialog);
        filepathLineEdit->setObjectName("filepathLineEdit");
        filepathLineEdit->setGeometry(QRect(40, 20, 291, 25));
        applyButton = new QPushButton(WeightsFileDialog);
        applyButton->setObjectName("applyButton");
        applyButton->setGeometry(QRect(160, 330, 81, 24));
        cancelButton = new QPushButton(WeightsFileDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(250, 330, 81, 24));
        filenameLabel = new QLabel(WeightsFileDialog);
        filenameLabel->setObjectName("filenameLabel");
        filenameLabel->setGeometry(QRect(10, 60, 91, 16));
        QFont font;
        font.setBold(true);
        filenameLabel->setFont(font);
        fileLabel = new QLabel(WeightsFileDialog);
        fileLabel->setObjectName("fileLabel");
        fileLabel->setGeometry(QRect(10, 80, 321, 16));
        filesizeLabel = new QLabel(WeightsFileDialog);
        filesizeLabel->setObjectName("filesizeLabel");
        filesizeLabel->setGeometry(QRect(10, 110, 91, 16));
        filesizeLabel->setFont(font);
        descriptionGroupBox = new QGroupBox(WeightsFileDialog);
        descriptionGroupBox->setObjectName("descriptionGroupBox");
        descriptionGroupBox->setGeometry(QRect(10, 170, 321, 101));
        QFont font1;
        font1.setBold(false);
        descriptionGroupBox->setFont(font1);
        descriptionGroupBox->setFlat(false);
        descriptionLabel = new QLabel(descriptionGroupBox);
        descriptionLabel->setObjectName("descriptionLabel");
        descriptionLabel->setGeometry(QRect(10, 20, 301, 71));
        descriptionLabel->setTextFormat(Qt::PlainText);
        descriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        descriptionLabel->setWordWrap(true);
        sizeLabel = new QLabel(WeightsFileDialog);
        sizeLabel->setObjectName("sizeLabel");
        sizeLabel->setGeometry(QRect(10, 130, 321, 16));

        retranslateUi(WeightsFileDialog);

        QMetaObject::connectSlotsByName(WeightsFileDialog);
    } // setupUi

    void retranslateUi(QDialog *WeightsFileDialog)
    {
        WeightsFileDialog->setWindowTitle(QCoreApplication::translate("WeightsFileDialog", "\316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202 \316\221\317\201\317\207\316\265\316\257\316\277\317\205 \316\222\316\261\317\201\317\216\316\275", nullptr));
        openButton->setText(QString());
        applyButton->setText(QCoreApplication::translate("WeightsFileDialog", "\316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267", nullptr));
        cancelButton->setText(QCoreApplication::translate("WeightsFileDialog", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", nullptr));
        filenameLabel->setText(QCoreApplication::translate("WeightsFileDialog", "\316\214\316\275\316\277\316\274\316\261 \316\221\317\201\317\207\316\265\316\257\316\277\317\205:", nullptr));
        fileLabel->setText(QString());
        filesizeLabel->setText(QCoreApplication::translate("WeightsFileDialog", "\316\234\316\255\316\263\316\265\316\270\316\277\317\202:", nullptr));
        descriptionGroupBox->setTitle(QCoreApplication::translate("WeightsFileDialog", "\316\240\316\265\317\201\316\271\316\263\317\201\316\261\317\206\316\256", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("WeightsFileDialog", "\316\244\316\277 \316\261\317\201\317\207\316\265\316\257\316\277 \316\262\316\261\317\201\317\216\316\275 \317\200\316\265\317\201\316\271\316\273\316\261\316\274\316\262\316\254\316\275\316\265\316\271 \317\204\316\261 \316\264\316\265\316\264\316\277\316\274\316\255\316\275\316\261 \317\200\316\254\316\275\317\211 \317\203\317\204\316\261 \316\277\317\200\316\277\316\257\316\261 \316\255\317\207\316\265\316\271 \316\265\316\272\317\200\316\261\316\271\316\264\316\265\317\205\317\204\316\265\316\257 \317\204\316\277 \316\275\316\265\317\205\317\201\317\211\316\275\316\271\316\272\317\214 \316\264\316\257\316\272\317\204\317\205\316\277. \316\243\317\204\316\267\316\275 \317\203\317\205\316\263\316\272\316\265\316\272\317\201\316\271\316\274\316\255\316\275\316\267 \317\200\316\265\317\201\316\257\317\200\317\204\317\211\317\203\316\267 \316\264\316\265\316\275 \317\205\317\200\316\254\317\201\317\207\316\265\316\271 \317\200\317\201\316\277\316\265\317\200\316\271\317\203\316\272\317\214\317\200\316\267\317\203"
                        "\316\267 \316\263\316\271\316\261\317\204\316\257 \317\204\316\277 \316\261\317\201\317\207\316\265\316\257\316\277 \316\264\316\271\316\261\316\262\316\254\316\266\316\265\317\204\316\261\316\271 \316\274\317\214\316\275\316\277 \316\261\317\200\316\277 \317\204\316\277 \316\264\316\257\316\272\317\204\317\205\316\277.", nullptr));
        sizeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WeightsFileDialog: public Ui_WeightsFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEIGHTSFILEDIALOG_H
