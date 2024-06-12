/********************************************************************************
** Form generated from reading UI file 'contacthelpdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTHELPDIALOG_H
#define UI_CONTACTHELPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ContactHelpDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *ContactHelpDialog)
    {
        if (ContactHelpDialog->objectName().isEmpty())
            ContactHelpDialog->setObjectName("ContactHelpDialog");
        ContactHelpDialog->resize(400, 69);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/argus/res/app_icons/contact.png"), QSize(), QIcon::Normal, QIcon::Off);
        ContactHelpDialog->setWindowIcon(icon);
        label = new QLabel(ContactHelpDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 381, 41));
        label->setScaledContents(false);
        label->setWordWrap(true);

        retranslateUi(ContactHelpDialog);

        QMetaObject::connectSlotsByName(ContactHelpDialog);
    } // setupUi

    void retranslateUi(QDialog *ContactHelpDialog)
    {
        ContactHelpDialog->setWindowTitle(QCoreApplication::translate("ContactHelpDialog", "\316\225\317\200\316\271\316\272\316\277\316\271\316\275\317\211\316\275\316\257\316\261", nullptr));
        label->setText(QCoreApplication::translate("ContactHelpDialog", "\316\223\316\271\316\261 \316\277\317\200\316\277\316\271\316\261\316\264\316\256\317\200\316\277\317\204\316\265 \316\261\317\200\316\277\317\201\316\257\316\261, \317\200\317\201\317\214\316\262\316\273\316\267\316\274\316\261 \316\256 \317\200\317\201\317\214\317\204\316\261\317\203\316\267 \316\274\317\200\316\277\317\201\316\265\316\257\317\204\316\265 \316\275\316\261 \317\203\317\204\316\265\316\257\316\273\316\265\317\204\316\265 \316\255\316\275\316\261 \316\267\316\273\316\265\316\272\317\204\317\201\316\277\316\275\316\271\316\272\317\214 \316\274\316\256\316\275\317\205\316\274\316\261 \317\203\317\204\316\267\316\275 \316\264\316\271\316\265\317\215\316\270\317\205\316\275\317\203\316\267: matsasjim@gmail.com", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactHelpDialog: public Ui_ContactHelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTHELPDIALOG_H
