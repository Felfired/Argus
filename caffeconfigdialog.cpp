#include "caffeconfigdialog.h"
#include "./ui_caffeconfigdialog.h"

CaffeConfigDialog::CaffeConfigDialog(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::CaffeConfigDialog)
{
	ui->setupUi(this);
	setWindowModality(Qt::ApplicationModal);

    openModelFileButton = ui->openModelFileButton;
    connect(openModelFileButton, &QPushButton::clicked, this, &CaffeConfigDialog::openModelFileClicked);
    modelFPLineEdit = ui->modelFPLineEdit;
    modelFPLineEdit->setReadOnly(true);

    openConfigFileButton = ui->openConfigFileButton;
    connect(openConfigFileButton, &QPushButton::clicked, this, &CaffeConfigDialog::openConfigFileClicked);
    configFPLineEdit = ui->configFPLineEdit;
    configFPLineEdit->setReadOnly(true);

    saveButton = ui->saveButton;
    saveButton->setEnabled(false);
    connect(saveButton, &QPushButton::clicked, this, &CaffeConfigDialog::saveButtonClicked);

    closeButton = ui->closeButton;
    connect(closeButton, &QPushButton::clicked, this, &CaffeConfigDialog::cancelButtonClicked);

    QSettings settings("config.ini", QSettings::IniFormat);
    if (settings.contains("Caffe_Preferences/Model_Path"))
    {
        originalModelFilePath = settings.value("Caffe_Preferences/Model_Path").toString();
        modelFilePath = originalModelFilePath;
        modelFPLineEdit->setText(modelFilePath);
    }
    if (settings.contains("Caffe_Preferences/Config_Path"))
    {
        originalConfigFilePath = settings.value("Caffe_Preferences/Config_Path").toString();
        configFilePath = originalConfigFilePath;
        configFPLineEdit->setText(configFilePath);
    }
}

CaffeConfigDialog::~CaffeConfigDialog()
{
    delete ui;
}

void CaffeConfigDialog::cancelButtonClicked()
{
    close();
}

void CaffeConfigDialog::openModelFileClicked()
{
    modelFilePath = QFileDialog::getOpenFileName(this, tr("Επιλογή Αρχείου..."), "", tr("Αρχεία Μοντέλου (*.caffemodel)"));
    modelFPLineEdit->setText(modelFilePath);

    if (modelFilePath != originalModelFilePath)
    {
        saveButton->setEnabled(true);
    }
}

void CaffeConfigDialog::openConfigFileClicked()
{
    configFilePath = QFileDialog::getOpenFileName(this, tr("Επιλογή Αρχείου..."), "", tr("Αρχεία Παραμετροποιήσεων (*.PROTOTXT)"));
    configFPLineEdit->setText(configFilePath);

    if (configFilePath != originalConfigFilePath)
    {
        saveButton->setEnabled(true);
    }
}

void CaffeConfigDialog::saveButtonClicked()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("Caffe_Preferences/Model_Path", modelFilePath);
    settings.setValue("Caffe_Preferences/Config_Path", configFilePath);
    settings.sync();
    close();
}