/********************************************************************************
** Form generated from reading UI file 'aboutopencv.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTOPENCV_H
#define UI_ABOUTOPENCV_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutOpencvDialog
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AboutOpencvDialog)
    {
        if (AboutOpencvDialog->objectName().isEmpty())
            AboutOpencvDialog->setObjectName("AboutOpencvDialog");
        AboutOpencvDialog->resize(381, 201);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/argus/res/app_icons/ocv.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutOpencvDialog->setWindowIcon(icon);
        label = new QLabel(AboutOpencvDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 80, 381, 121));
        label->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/images/opencv-logo.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(AboutOpencvDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 20, 231, 31));
        QFont font;
        font.setItalic(true);
        label_2->setFont(font);

        retranslateUi(AboutOpencvDialog);

        QMetaObject::connectSlotsByName(AboutOpencvDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutOpencvDialog)
    {
        AboutOpencvDialog->setWindowTitle(QCoreApplication::translate("AboutOpencvDialog", "\316\243\317\207\316\265\317\204\316\271\316\272\316\254 \316\274\316\265 \317\204\316\277 OpenCV", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("AboutOpencvDialog", "Copyright \302\251 2024 , OpenCV team\n"
"\316\234\316\265 \316\265\317\200\316\271\317\206\317\215\316\273\316\261\316\276\316\267 \316\272\316\254\316\270\316\265 \316\275\317\214\316\274\316\271\316\274\316\277\317\205 \316\264\316\271\316\272\316\261\316\271\317\216\316\274\316\261\317\204\316\277\317\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutOpencvDialog: public Ui_AboutOpencvDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTOPENCV_H
