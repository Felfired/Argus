/********************************************************************************
** Form generated from reading UI file 'aboutargus.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTARGUS_H
#define UI_ABOUTARGUS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutArgusDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AboutArgusDialog)
    {
        if (AboutArgusDialog->objectName().isEmpty())
            AboutArgusDialog->setObjectName("AboutArgusDialog");
        AboutArgusDialog->resize(357, 258);
        AboutArgusDialog->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/argus/res/app_icons/ar.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutArgusDialog->setWindowIcon(icon);
        label = new QLabel(AboutArgusDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 150, 341, 111));
        label->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/images/argus-logo.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(AboutArgusDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 20, 341, 91));
        QFont font;
        font.setItalic(true);
        label_2->setFont(font);
        label_2->setScaledContents(false);
        label_2->setWordWrap(true);
        label_3 = new QLabel(AboutArgusDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(118, 130, 221, 21));
        label_3->setFont(font);
        label_3->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(AboutArgusDialog);

        QMetaObject::connectSlotsByName(AboutArgusDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutArgusDialog)
    {
        AboutArgusDialog->setWindowTitle(QCoreApplication::translate("AboutArgusDialog", "\316\243\317\207\316\265\317\204\316\271\316\272\316\254 \316\274\316\265 \317\204\316\277 Argus", nullptr));
#if QT_CONFIG(tooltip)
        AboutArgusDialog->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("AboutArgusDialog", "\302\251 2024 \316\234\316\265 \316\265\317\200\316\271\317\206\317\215\316\273\316\261\316\276\316\267 \317\200\316\261\316\275\317\204\317\214\317\202 \316\264\316\271\316\272\316\261\316\271\317\216\316\274\316\261\317\204\316\277\317\202.\n"
"\316\224\316\227\316\234\316\227\316\244\316\241\316\231\316\237\316\243 \316\234\316\221\316\244\316\243\316\221\316\243\n"
"\316\240\316\261\316\275\316\265\317\200\316\271\317\203\317\204\316\256\316\274\316\271\316\277 \316\221\316\271\316\263\316\261\316\257\316\277\317\205\n"
"\316\244\316\274\316\256\316\274\316\261 \316\234\316\267\317\207\316\261\316\275\316\271\316\272\317\216\316\275 \316\240\316\273\316\267\317\201\316\277\317\206\316\277\317\201\316\271\316\261\316\272\317\216\316\275 \316\272\316\261\316\271 \316\225\317\200\316\271\316\272\316\277\316\271\316\275\317\211\316\275\316\271\316\261\316\272\317\216\316\275 \316\243\317\205\317\203\317\204\316\267\316\274\316\254\317\204\317\211\316\275\n"
"", nullptr));
#if QT_CONFIG(tooltip)
        label_3->setToolTip(QCoreApplication::translate("AboutArgusDialog", "https://theodorekalpaklis.weebly.com/", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("AboutArgusDialog", "\316\224\316\267\316\274\316\271\316\277\317\205\317\201\316\263\317\214\317\202 \316\233\316\277\316\263\317\214\317\204\317\205\317\200\316\277\317\205: \316\230. \316\232\316\261\316\273\317\200\316\261\316\272\316\273\316\256\317\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutArgusDialog: public Ui_AboutArgusDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTARGUS_H
