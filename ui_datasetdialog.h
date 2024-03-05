/********************************************************************************
** Form generated from reading UI file 'datasetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASETDIALOG_H
#define UI_DATASETDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatasetDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tabSelectPerson;
    QTableWidget *catalogDisplayTableWidget;
    QLabel *descriptionSelectLabel;
    QLabel *selectPersonImageLabel;
    QTextEdit *searchTextEdit;
    QToolButton *clearSelectionButton;
    QWidget *tabAddImg;
    QLabel *datasetImageLabel;
    QTableWidget *tableWidget;
    QLabel *datasetDescriptionLabel;
    QPushButton *openButton;
    QLabel *label;
    QLabel *labelID;
    QToolButton *deleteButton;
    QToolButton *refreshButton;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *DatasetDialog)
    {
        if (DatasetDialog->objectName().isEmpty())
            DatasetDialog->setObjectName("DatasetDialog");
        DatasetDialog->resize(429, 409);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/app_icons/dataset.png"), QSize(), QIcon::Normal, QIcon::Off);
        DatasetDialog->setWindowIcon(icon);
        tabWidget = new QTabWidget(DatasetDialog);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 411, 351));
        tabSelectPerson = new QWidget();
        tabSelectPerson->setObjectName("tabSelectPerson");
        catalogDisplayTableWidget = new QTableWidget(tabSelectPerson);
        catalogDisplayTableWidget->setObjectName("catalogDisplayTableWidget");
        catalogDisplayTableWidget->setGeometry(QRect(10, 111, 380, 201));
        catalogDisplayTableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        catalogDisplayTableWidget->setFrameShape(QFrame::WinPanel);
        catalogDisplayTableWidget->setShowGrid(false);
        descriptionSelectLabel = new QLabel(tabSelectPerson);
        descriptionSelectLabel->setObjectName("descriptionSelectLabel");
        descriptionSelectLabel->setGeometry(QRect(50, 10, 321, 61));
        descriptionSelectLabel->setWordWrap(true);
        selectPersonImageLabel = new QLabel(tabSelectPerson);
        selectPersonImageLabel->setObjectName("selectPersonImageLabel");
        selectPersonImageLabel->setGeometry(QRect(10, 20, 32, 32));
        selectPersonImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/app_icons/select_person.png")));
        selectPersonImageLabel->setScaledContents(true);
        searchTextEdit = new QTextEdit(tabSelectPerson);
        searchTextEdit->setObjectName("searchTextEdit");
        searchTextEdit->setGeometry(QRect(287, 83, 103, 31));
        searchTextEdit->setFrameShape(QFrame::WinPanel);
        searchTextEdit->setFrameShadow(QFrame::Sunken);
        clearSelectionButton = new QToolButton(tabSelectPerson);
        clearSelectionButton->setObjectName("clearSelectionButton");
        clearSelectionButton->setGeometry(QRect(258, 82, 30, 30));
        clearSelectionButton->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/argus/res/app_icons/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearSelectionButton->setIcon(icon1);
        tabWidget->addTab(tabSelectPerson, QString());
        tabAddImg = new QWidget();
        tabAddImg->setObjectName("tabAddImg");
        datasetImageLabel = new QLabel(tabAddImg);
        datasetImageLabel->setObjectName("datasetImageLabel");
        datasetImageLabel->setGeometry(QRect(10, 20, 32, 32));
        datasetImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/argus/res/app_icons/add_image.png")));
        datasetImageLabel->setScaledContents(true);
        tableWidget = new QTableWidget(tabAddImg);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 151, 351, 161));
        tableWidget->setFrameShape(QFrame::WinPanel);
        datasetDescriptionLabel = new QLabel(tabAddImg);
        datasetDescriptionLabel->setObjectName("datasetDescriptionLabel");
        datasetDescriptionLabel->setGeometry(QRect(50, 10, 341, 61));
        datasetDescriptionLabel->setScaledContents(false);
        datasetDescriptionLabel->setWordWrap(true);
        openButton = new QPushButton(tabAddImg);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(294, 110, 91, 24));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("res/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon2);
        label = new QLabel(tabAddImg);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 110, 161, 16));
        labelID = new QLabel(tabAddImg);
        labelID->setObjectName("labelID");
        labelID->setGeometry(QRect(180, 110, 49, 16));
        QFont font;
        font.setBold(true);
        labelID->setFont(font);
        deleteButton = new QToolButton(tabAddImg);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(360, 150, 30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/argus/res/app_icons/x.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon3);
        deleteButton->setAutoRaise(false);
        refreshButton = new QToolButton(tabAddImg);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(360, 180, 30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/argus/res/app_icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreshButton->setIcon(icon4);
        tabWidget->addTab(tabAddImg, QString());
        cancelButton = new QPushButton(DatasetDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(340, 370, 75, 24));
        saveButton = new QPushButton(DatasetDialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(260, 370, 75, 24));

        retranslateUi(DatasetDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DatasetDialog);
    } // setupUi

    void retranslateUi(QDialog *DatasetDialog)
    {
        DatasetDialog->setWindowTitle(QCoreApplication::translate("DatasetDialog", "\316\224\316\265\316\264\316\277\316\274\316\255\316\275\316\261 \316\246\317\211\317\204\316\277\316\263\317\201\316\261\317\206\316\271\317\216\316\275", nullptr));
        descriptionSelectLabel->setText(QCoreApplication::translate("DatasetDialog", "\316\240\317\201\316\271\316\275 \317\200\317\201\316\277\317\207\317\211\317\201\316\256\317\203\316\265\317\204\316\265 \317\203\317\204\316\267\316\275 \317\200\317\201\316\277\317\203\316\270\316\256\316\272\316\267 \317\206\317\211\317\204\316\277\316\263\317\201\316\261\317\206\316\271\316\272\317\216\316\275 \316\264\316\265\316\264\316\277\316\274\316\255\316\275\317\211\316\275 \317\200\317\201\316\255\317\200\316\265\316\271 \316\275\316\261 \316\265\317\200\316\271\316\273\316\255\316\276\316\265\317\204\316\265 \316\263\316\271\316\261 \317\200\316\277\316\271\317\214 \316\254\317\204\316\277\316\274\316\277 \316\270\316\261 \317\204\316\271\317\202 \316\265\316\271\317\203\316\254\316\263\316\265\317\204\316\265. \316\227 \316\264\316\271\316\261\316\264\316\271\316\272\316\261\317\203\316\257\316\261 \316\274\317\200\316\277\317\201\316\265\316\257 \316\275\316\261 \316\263\316\257\316\275\316\265\316\271 \316\263\316\271\316\261 \316\255\316\275\316\261 \316\254\317\204\316\277\316\274\316\277 \317"
                        "\204\316\267\316\275 \317\206\316\277\317\201\316\254.", nullptr));
        selectPersonImageLabel->setText(QString());
        searchTextEdit->setPlaceholderText(QCoreApplication::translate("DatasetDialog", "\316\221\316\275\316\261\316\266\316\256\317\204\316\267\317\203\316\267...", nullptr));
#if QT_CONFIG(tooltip)
        clearSelectionButton->setToolTip(QCoreApplication::translate("DatasetDialog", "\316\232\316\261\316\270\316\261\317\201\316\271\317\203\316\274\317\214\317\202 \316\265\317\200\316\271\316\273\316\277\316\263\316\256\317\202.", nullptr));
#endif // QT_CONFIG(tooltip)
        clearSelectionButton->setText(QCoreApplication::translate("DatasetDialog", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSelectPerson), QCoreApplication::translate("DatasetDialog", "\316\225\317\200\316\271\316\273\316\277\316\263\316\256 \316\221\317\204\317\214\316\274\316\277\317\205", nullptr));
        datasetImageLabel->setText(QString());
        datasetDescriptionLabel->setText(QCoreApplication::translate("DatasetDialog", "\316\225\316\264\317\216 \316\274\317\200\316\277\317\201\316\265\316\257\317\204\316\265 \316\275\316\261 \317\200\317\201\316\277\317\203\316\270\316\255\317\203\316\265\317\204\316\265 \317\204\316\271\317\202 \316\265\316\271\316\272\317\214\316\275\316\265\317\202 \316\274\316\265 \317\203\317\204\316\277\316\271\317\207\316\265\316\257\316\261 \317\200\317\201\316\277\317\203\317\216\317\200\316\277\317\205 \317\200\316\277\317\205 \316\270\316\261 \317\207\317\201\316\267\317\203\316\271\316\274\316\277\317\200\316\277\316\271\316\256\317\203\316\265\316\271 \316\277 \316\261\316\273\316\263\317\214\317\201\316\271\316\270\316\274\316\277\317\202 \317\204\316\277\317\205 \316\275\316\265\317\205\317\201\317\211\316\275\316\271\316\272\316\277\317\215 \316\264\316\271\316\272\317\204\317\215\316\277\317\205. \316\244\316\277 \316\261\317\200\316\261\316\271\317\204\316\277\317\215\316\274\316\265\316\275\316\277 \316\274\316\255\316\263\316\265\316\270\316\277\317\202 \317\206\317\211\317\204\316\277\316"
                        "\263\317\201\316\261\317\206\316\257\316\261\317\202 \316\265\316\271\316\275\316\261\316\271 512x512.", nullptr));
        openButton->setText(QCoreApplication::translate("DatasetDialog", " \316\206\316\275\316\277\316\271\316\263\316\274\316\261...", nullptr));
        label->setText(QCoreApplication::translate("DatasetDialog", "\316\225\317\200\316\271\316\273\316\265\316\263\316\274\316\255\316\275\316\277 \316\261\316\275\316\261\316\263\316\275\317\211\317\201\316\271\317\203\317\204\316\271\316\272\317\214: ", nullptr));
        labelID->setText(QString());
        deleteButton->setText(QCoreApplication::translate("DatasetDialog", "...", nullptr));
        refreshButton->setText(QCoreApplication::translate("DatasetDialog", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAddImg), QCoreApplication::translate("DatasetDialog", "\316\240\317\201\316\277\317\203\316\270\316\256\316\272\316\267", nullptr));
        cancelButton->setText(QCoreApplication::translate("DatasetDialog", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", nullptr));
        saveButton->setText(QCoreApplication::translate("DatasetDialog", "\316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatasetDialog: public Ui_DatasetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASETDIALOG_H
