/********************************************************************************
** Form generated from reading UI file 'catalogdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGDIALOG_H
#define UI_CATALOGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_CatalogDialog
{
public:
    QFrame *line_2;
    QLabel *sortLabel;
    QComboBox *sortComboBox;
    QPushButton *addButton;
    QLineEdit *searchLineEdit;
    QLabel *pathLabel;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *birthLabel;
    QLabel *idLabel;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *trainedStatusLabel;
    QLabel *datasetLabel;
    QTableWidget *catalogTableWidget;
    QFrame *frame;
    QLabel *pictureLabel;
    QToolButton *refreshTableButton;
    QPushButton *deleteButton;

    void setupUi(QDialog *CatalogDialog)
    {
        if (CatalogDialog->objectName().isEmpty())
            CatalogDialog->setObjectName("CatalogDialog");
        CatalogDialog->resize(727, 431);
        QFont font;
        font.setUnderline(false);
        CatalogDialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/icons/id.png"), QSize(), QIcon::Normal, QIcon::Off);
        CatalogDialog->setWindowIcon(icon);
        line_2 = new QFrame(CatalogDialog);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(-10, 30, 771, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        sortLabel = new QLabel(CatalogDialog);
        sortLabel->setObjectName("sortLabel");
        sortLabel->setGeometry(QRect(260, 10, 101, 22));
        sortComboBox = new QComboBox(CatalogDialog);
        sortComboBox->setObjectName("sortComboBox");
        sortComboBox->setGeometry(QRect(360, 10, 151, 22));
        addButton = new QPushButton(CatalogDialog);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(30, 10, 75, 22));
        searchLineEdit = new QLineEdit(CatalogDialog);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(560, 10, 131, 22));
        pathLabel = new QLabel(CatalogDialog);
        pathLabel->setObjectName("pathLabel");
        pathLabel->setGeometry(QRect(110, 20, 16, 16));
        QFont font1;
        font1.setUnderline(true);
        pathLabel->setFont(font1);
        pathLabel->setCursor(QCursor(Qt::WhatsThisCursor));
        groupBox = new QGroupBox(CatalogDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(420, 250, 291, 171));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 30, 81, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 60, 81, 16));
        birthLabel = new QLabel(groupBox);
        birthLabel->setObjectName("birthLabel");
        birthLabel->setGeometry(QRect(170, 30, 111, 16));
        idLabel = new QLabel(groupBox);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(170, 60, 111, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 90, 131, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 120, 151, 16));
        trainedStatusLabel = new QLabel(groupBox);
        trainedStatusLabel->setObjectName("trainedStatusLabel");
        trainedStatusLabel->setGeometry(QRect(170, 120, 111, 16));
        datasetLabel = new QLabel(groupBox);
        datasetLabel->setObjectName("datasetLabel");
        datasetLabel->setGeometry(QRect(170, 90, 111, 16));
        catalogTableWidget = new QTableWidget(CatalogDialog);
        if (catalogTableWidget->columnCount() < 3)
            catalogTableWidget->setColumnCount(3);
        catalogTableWidget->setObjectName("catalogTableWidget");
        catalogTableWidget->setGeometry(QRect(0, 40, 400, 391));
        catalogTableWidget->setFrameShape(QFrame::WinPanel);
        catalogTableWidget->setFrameShadow(QFrame::Sunken);
        catalogTableWidget->setShowGrid(false);
        catalogTableWidget->setColumnCount(3);
        frame = new QFrame(CatalogDialog);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(525, 50, 185, 185));
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        pictureLabel = new QLabel(frame);
        pictureLabel->setObjectName("pictureLabel");
        pictureLabel->setGeometry(QRect(1, 2, 180, 180));
        refreshTableButton = new QToolButton(CatalogDialog);
        refreshTableButton->setObjectName("refreshTableButton");
        refreshTableButton->setGeometry(QRect(400, 40, 25, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("res/icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreshTableButton->setIcon(icon1);
        deleteButton = new QPushButton(CatalogDialog);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(150, 10, 75, 22));

        retranslateUi(CatalogDialog);

        QMetaObject::connectSlotsByName(CatalogDialog);
    } // setupUi

    void retranslateUi(QDialog *CatalogDialog)
    {
        CatalogDialog->setWindowTitle(QCoreApplication::translate("CatalogDialog", "\316\232\316\261\317\204\316\254\316\273\316\277\316\263\316\277\317\202 \316\221\317\204\317\214\316\274\317\211\316\275", nullptr));
        sortLabel->setText(QCoreApplication::translate("CatalogDialog", "\316\244\316\261\316\276\316\271\316\275\317\214\316\274\316\267\317\203\316\267 \316\272\316\261\317\204\316\261:", nullptr));
        addButton->setText(QCoreApplication::translate("CatalogDialog", "\316\240\317\201\316\277\317\203\316\270\316\256\316\272\316\267", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("CatalogDialog", "\316\221\316\275\316\261\316\266\316\256\317\204\316\267\317\203\316\267...", nullptr));
        pathLabel->setText(QCoreApplication::translate("CatalogDialog", "?", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CatalogDialog", "\316\222\316\261\317\203\316\271\316\272\316\254 \316\243\317\204\316\277\316\271\317\207\316\265\316\257\316\261", nullptr));
        label_3->setText(QCoreApplication::translate("CatalogDialog", "\316\227\316\274. \316\223\316\255\316\275\316\275\316\267\317\203\316\267\317\202:", nullptr));
        label_4->setText(QCoreApplication::translate("CatalogDialog", "ID:", nullptr));
        birthLabel->setText(QString());
        idLabel->setText(QString());
        label_5->setText(QCoreApplication::translate("CatalogDialog", "\316\243\317\215\316\275\316\277\316\273\316\277 \316\246\317\211\317\204\316\277\316\263\317\201\316\261\317\206\316\271\317\216\316\275:", nullptr));
        label_6->setText(QCoreApplication::translate("CatalogDialog", "\316\232\316\261\317\204\316\254\317\203\317\204\316\261\317\203\316\267 \316\225\316\272\317\200\316\261\316\257\316\264\316\265\317\205\317\203\316\267\317\202:", nullptr));
        trainedStatusLabel->setText(QString());
        datasetLabel->setText(QString());
        pictureLabel->setText(QString());
        refreshTableButton->setText(QCoreApplication::translate("CatalogDialog", "...", nullptr));
        deleteButton->setText(QCoreApplication::translate("CatalogDialog", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CatalogDialog: public Ui_CatalogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGDIALOG_H
