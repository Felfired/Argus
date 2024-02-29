/********************************************************************************
** Form generated from reading UI file 'addpersondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSONDIALOG_H
#define UI_ADDPERSONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPersonDialog
{
public:
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *surnameLabel;
    QLineEdit *surnameEdit;
    QLabel *idLabel;
    QLineEdit *idEdit;
    QLabel *birthLabel;
    QDateEdit *dateEdit;
    QLabel *lnameLabel;
    QLineEdit *lnameEdit;
    QLabel *lsurnameLabel;
    QLineEdit *lsurnameEdit;
    QLabel *surnameErrorLabel;
    QLabel *nameErrorLabel;
    QLabel *idErrorLabel;
    QLabel *lsurnameErrorLabel;
    QLabel *lnameErrorLabel;
    QLabel *dateErrorLabel;
    QGroupBox *groupBox_2;
    QToolButton *addProfileButton;
    QLineEdit *profilePathDisplay;
    QLabel *imgErrorLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddPersonDialog)
    {
        if (AddPersonDialog->objectName().isEmpty())
            AddPersonDialog->setObjectName("AddPersonDialog");
        AddPersonDialog->resize(480, 510);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/icons/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddPersonDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(AddPersonDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 441, 331));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 30, 421, 301));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        surnameLabel = new QLabel(formLayoutWidget);
        surnameLabel->setObjectName("surnameLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, surnameLabel);

        surnameEdit = new QLineEdit(formLayoutWidget);
        surnameEdit->setObjectName("surnameEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, surnameEdit);

        idLabel = new QLabel(formLayoutWidget);
        idLabel->setObjectName("idLabel");
        idLabel->setInputMethodHints(Qt::ImhNone);

        formLayout->setWidget(4, QFormLayout::LabelRole, idLabel);

        idEdit = new QLineEdit(formLayoutWidget);
        idEdit->setObjectName("idEdit");
        idEdit->setInputMethodHints(Qt::ImhDigitsOnly);

        formLayout->setWidget(4, QFormLayout::FieldRole, idEdit);

        birthLabel = new QLabel(formLayoutWidget);
        birthLabel->setObjectName("birthLabel");

        formLayout->setWidget(6, QFormLayout::LabelRole, birthLabel);

        dateEdit = new QDateEdit(formLayoutWidget);
        dateEdit->setObjectName("dateEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, dateEdit);

        lnameLabel = new QLabel(formLayoutWidget);
        lnameLabel->setObjectName("lnameLabel");

        formLayout->setWidget(8, QFormLayout::LabelRole, lnameLabel);

        lnameEdit = new QLineEdit(formLayoutWidget);
        lnameEdit->setObjectName("lnameEdit");

        formLayout->setWidget(8, QFormLayout::FieldRole, lnameEdit);

        lsurnameLabel = new QLabel(formLayoutWidget);
        lsurnameLabel->setObjectName("lsurnameLabel");

        formLayout->setWidget(10, QFormLayout::LabelRole, lsurnameLabel);

        lsurnameEdit = new QLineEdit(formLayoutWidget);
        lsurnameEdit->setObjectName("lsurnameEdit");

        formLayout->setWidget(10, QFormLayout::FieldRole, lsurnameEdit);

        surnameErrorLabel = new QLabel(formLayoutWidget);
        surnameErrorLabel->setObjectName("surnameErrorLabel");

        formLayout->setWidget(3, QFormLayout::SpanningRole, surnameErrorLabel);

        nameErrorLabel = new QLabel(formLayoutWidget);
        nameErrorLabel->setObjectName("nameErrorLabel");

        formLayout->setWidget(1, QFormLayout::SpanningRole, nameErrorLabel);

        idErrorLabel = new QLabel(formLayoutWidget);
        idErrorLabel->setObjectName("idErrorLabel");

        formLayout->setWidget(5, QFormLayout::SpanningRole, idErrorLabel);

        lsurnameErrorLabel = new QLabel(formLayoutWidget);
        lsurnameErrorLabel->setObjectName("lsurnameErrorLabel");

        formLayout->setWidget(11, QFormLayout::SpanningRole, lsurnameErrorLabel);

        lnameErrorLabel = new QLabel(formLayoutWidget);
        lnameErrorLabel->setObjectName("lnameErrorLabel");

        formLayout->setWidget(9, QFormLayout::SpanningRole, lnameErrorLabel);

        dateErrorLabel = new QLabel(formLayoutWidget);
        dateErrorLabel->setObjectName("dateErrorLabel");

        formLayout->setWidget(7, QFormLayout::SpanningRole, dateErrorLabel);

        groupBox_2 = new QGroupBox(AddPersonDialog);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 360, 441, 81));
        addProfileButton = new QToolButton(groupBox_2);
        addProfileButton->setObjectName("addProfileButton");
        addProfileButton->setGeometry(QRect(10, 30, 25, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("res/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        addProfileButton->setIcon(icon1);
        profilePathDisplay = new QLineEdit(groupBox_2);
        profilePathDisplay->setObjectName("profilePathDisplay");
        profilePathDisplay->setGeometry(QRect(50, 30, 381, 25));
        imgErrorLabel = new QLabel(groupBox_2);
        imgErrorLabel->setObjectName("imgErrorLabel");
        imgErrorLabel->setGeometry(QRect(50, 60, 381, 16));
        horizontalLayoutWidget = new QWidget(AddPersonDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(300, 460, 161, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(horizontalLayoutWidget);
        saveButton->setObjectName("saveButton");

        horizontalLayout->addWidget(saveButton);

        cancelButton = new QPushButton(horizontalLayoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        retranslateUi(AddPersonDialog);

        QMetaObject::connectSlotsByName(AddPersonDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPersonDialog)
    {
        AddPersonDialog->setWindowTitle(QCoreApplication::translate("AddPersonDialog", "\316\240\317\201\316\277\317\203\316\270\316\256\316\272\316\267 \316\221\317\204\317\214\316\274\316\277\317\205", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddPersonDialog", "\316\222\316\261\317\203\316\271\316\272\316\254 \316\243\317\204\316\277\317\207\316\265\316\257\316\261", nullptr));
        nameLabel->setText(QCoreApplication::translate("AddPersonDialog", "\316\214\316\275\316\277\316\274\316\261:", nullptr));
        surnameLabel->setText(QCoreApplication::translate("AddPersonDialog", "\316\225\317\200\317\216\316\275\317\205\316\274\316\277:", nullptr));
        idLabel->setText(QCoreApplication::translate("AddPersonDialog", "\316\234\316\277\316\275\316\261\316\264\316\271\316\272\317\214 \316\221\316\275\316\261\316\263\316\275\317\211\317\201\316\271\317\203\317\204\316\271\316\272\317\214 (ID):", nullptr));
        birthLabel->setText(QCoreApplication::translate("AddPersonDialog", "\316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261 \316\223\316\255\316\275\316\275\316\267\317\203\316\267\317\202:", nullptr));
        lnameLabel->setText(QCoreApplication::translate("AddPersonDialog", "\316\214\316\275\316\277\316\274\316\261 (\316\233\316\261\317\204\316\271\316\275\316\271\316\272\316\254):", nullptr));
        lsurnameLabel->setText(QCoreApplication::translate("AddPersonDialog", "\316\225\317\200\317\216\316\275\317\205\316\274\316\277 (\316\233\316\261\317\204\316\271\316\275\316\271\316\272\316\254):", nullptr));
        surnameErrorLabel->setText(QString());
        nameErrorLabel->setText(QString());
        idErrorLabel->setText(QString());
        lsurnameErrorLabel->setText(QString());
        lnameErrorLabel->setText(QString());
        dateErrorLabel->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("AddPersonDialog", "\316\240\317\201\316\277\317\203\316\270\316\256\316\272\316\267 \316\246\317\211\317\204\316\277\316\263\317\201\316\261\317\206\316\257\316\261\317\202", nullptr));
        addProfileButton->setText(QString());
        imgErrorLabel->setText(QString());
        saveButton->setText(QCoreApplication::translate("AddPersonDialog", "\316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddPersonDialog", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPersonDialog: public Ui_AddPersonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSONDIALOG_H
