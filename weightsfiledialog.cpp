#include "weightsfiledialog.h"
#include "./ui_weightsfiledialog.h"

WeightsFileDialog::WeightsFileDialog(const QString lweightsFilePath, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::WeightsFileDialog)
{
    ui->setupUi(this);
    isfileLoading = false;
    isfileLoaded = false;
    weightsFilePath = lweightsFilePath;

    progressBar = ui->progressBar;
    progressBar->setVisible(false);

    filepathLineEdit = ui->filepathLineEdit;
    filepathLineEdit->setReadOnly(true);

    fileLabel = ui->fileLabel;
    sizeLabel = ui->sizeLabel;

    openButton = ui->openButton;
    connect(openButton, &QPushButton::clicked, this, &WeightsFileDialog::buttonOpenFileClicked);

    cancelButton = ui->cancelButton;
    cancelButton->setEnabled(true);
    connect(cancelButton, &QPushButton::clicked, this, &WeightsFileDialog::buttonCancelClicked);

    applyButton = ui->applyButton;
    applyButton->setEnabled(false);
    connect(applyButton, &QPushButton::clicked, this, &WeightsFileDialog::buttonApplyClicked);

    if (!(weightsFilePath == ""))
    {
        readFile(weightsFilePath);
    }
}

WeightsFileDialog::~WeightsFileDialog()
{
    delete ui;
}

void WeightsFileDialog::buttonOpenFileClicked()
{
    weightsFilePath = QFileDialog::getOpenFileName(this, tr("Άνοιγμα Αρχείου"), "", tr("Αρχεία Βαρών (*.weights)"));
    filepathLineEdit->setText(weightsFilePath);

    if (!weightsFilePath.isEmpty())
    {
        isfileLoaded = readFile(weightsFilePath);

        if (isfileLoaded == false)
        {
            QMessageBox::critical(this, tr("Σφάλμα"), tr("Αποτυχία φόρτωσης του αρχείου."));
        }
    }
}

void WeightsFileDialog::buttonCancelActivation()
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

bool WeightsFileDialog::readFile(QString weightsFilePath)
{
    isfileLoading = true;
    buttonCancelActivation();
    QFile namesFile(weightsFilePath);
    QFileInfo namesFileInfo(weightsFilePath);

    if (!(weightsFilePath == ""))
    {
        filepathLineEdit->setText(weightsFilePath);
    }

    if (namesFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qint64 namesFileSize = namesFile.size();

        QTextStream in(&namesFile);
        QString namesFileContent;

        namesFile.close();
        isfileLoading = false;
        buttonCancelActivation();
        fileLabel->setText(namesFileInfo.fileName());
        QString sizeText = QString::number(namesFileSize) + " byte(s)";
        sizeLabel->setText(sizeText);
        applyButton->setEnabled(true);

        return true;
    }
    else
    {
        qDebug() << "Error opening file:" << namesFile.errorString();
        isfileLoading = false;
        return false;
    }
}

void WeightsFileDialog::buttonCancelClicked()
{
    close();
}

void WeightsFileDialog::buttonApplyClicked()
{
    emit onApplyButtonClicked(weightsFilePath);
    close();
}