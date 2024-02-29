#include "configfiledialog.h"
#include "./ui_configfiledialog.h"

ConfigFileDialog::ConfigFileDialog(const QString lconfigFilePath, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ConfigFileDialog)
{
    ui->setupUi(this);
    isfileLoading = false;
    isfileLoaded = false;
    configFilePath = lconfigFilePath;

    progressBar = ui->progressBar;
    textBrowser = ui->textBrowser;
    progressBar->setVisible(false);

    filepathLineEdit = ui->filepathLineEdit;
    filepathLineEdit->setReadOnly(true);

    fileLabel = ui->fileLabel;
    sizeLabel = ui->sizeLabel;

    openButton = ui->openButton;
    connect(openButton, &QPushButton::clicked, this, &ConfigFileDialog::buttonOpenFileClicked);

    cancelButton = ui->cancelButton;
    cancelButton->setEnabled(true);
    connect(cancelButton, &QPushButton::clicked, this, &ConfigFileDialog::buttonCancelClicked);

    applyButton = ui->applyButton;
    applyButton->setEnabled(false);
    connect(applyButton, &QPushButton::clicked, this, &ConfigFileDialog::buttonApplyClicked);

    if (!(configFilePath == ""))
    {
        readAndDisplay(configFilePath);
    }
}

ConfigFileDialog::~ConfigFileDialog()
{
    delete ui;
}

void ConfigFileDialog::buttonOpenFileClicked()
{
    configFilePath = QFileDialog::getOpenFileName(this, tr("Άνοιγμα Αρχείου"), "", tr("Αρχεία Παραμετροποιήσεων (*.cfg)"));
    filepathLineEdit->setText(configFilePath);

    if (!configFilePath.isEmpty())
    {
        isfileLoaded = readAndDisplay(configFilePath);

        if (isfileLoaded == false)
        {
            QMessageBox::critical(this, tr("Σφάλμα"), tr("Αποτυχία φόρτωσης του αρχείου."));
        }
    }
}

void ConfigFileDialog::buttonCancelActivation()
{
    if (isfileLoading == true)
    {
        cancelButton->setEnabled(false);
    }
    else if (isfileLoading == false)
    {
        cancelButton->setEnabled(true);
    }
}

void ConfigFileDialog::buttonCancelClicked()
{
    close();
}

bool ConfigFileDialog::readAndDisplay(QString configFilePath)
{
    isfileLoading = true;
    buttonCancelActivation();
    QFile configFile(configFilePath);
    QFileInfo configFileInfo(configFilePath);

    if (!(configFilePath == ""))
    {
        filepathLineEdit->setText(configFilePath);
    }

    if (configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        progressBar->setVisible(true);
        qint64 configFileSize = configFile.size();
        progressBar->setRange(0, configFileSize);
        progressBar->setValue(0);

        QTextStream in(&configFile);
        QString configFileContent;

        while (!in.atEnd())
        {
            configFileContent += in.read(1024);
            progressBar->setValue(configFile.pos());
            QCoreApplication::processEvents();
        }

        textBrowser->setPlainText(configFileContent);
        configFile.close();
        isfileLoading = false;
        buttonCancelActivation();
        fileLabel->setText(configFileInfo.fileName());
        QString sizeText = QString::number(configFileSize) + " byte(s)";
        sizeLabel->setText(sizeText);
        applyButton->setEnabled(true);

        return true;
    }
    else
    {
        qDebug() << "Error opening file:" << configFile.errorString();
        isfileLoading = false;
        return false;
    }
}

void ConfigFileDialog::buttonApplyClicked()
{
    emit onApplyButtonClicked(configFilePath);
    close();
}