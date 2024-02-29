#include "namesfiledialog.h"
#include "./ui_namesfiledialog.h"

NamesFileDialog::NamesFileDialog(const QString lnamesFilePath, QWidget* parent) 
    : QDialog(parent)
    , ui(new Ui::NamesFileDialog)
{
	ui->setupUi(this);
    isfileLoading = false;
    isfileLoaded = false;
    namesFilePath = lnamesFilePath;

    progressBar = ui->progressBar;
    textBrowser = ui->textBrowser;
    progressBar->setVisible(false);

    filepathLineEdit = ui->filepathLineEdit;
    filepathLineEdit->setReadOnly(true);

    fileLabel = ui->fileLabel;
    sizeLabel = ui->sizeLabel;

    openButton = ui->openButton;
    connect(openButton, &QPushButton::clicked, this, &NamesFileDialog::buttonOpenFileClicked);

    cancelButton = ui->cancelButton;
    cancelButton->setEnabled(true);
    connect(cancelButton, &QPushButton::clicked, this, &NamesFileDialog::buttonCancelClicked);

    applyButton = ui->applyButton;
    applyButton->setEnabled(false);
    connect(applyButton, &QPushButton::clicked, this, &NamesFileDialog::buttonApplyClicked);

    if (!(namesFilePath == ""))
    {
        readAndDisplay(namesFilePath);
    }
}

NamesFileDialog::~NamesFileDialog()
{
	delete ui;
}

void NamesFileDialog::buttonOpenFileClicked()
{
	namesFilePath = QFileDialog::getOpenFileName(this, tr("Άνοιγμα Αρχείου"), "", tr("Αρχεία Ονομάτων (*.names)"));
    filepathLineEdit->setText(namesFilePath);

    if (!namesFilePath.isEmpty())
    {
        isfileLoaded = readAndDisplay(namesFilePath);

        if (isfileLoaded == false)
        {
            QMessageBox::critical(this, tr("Σφάλμα"), tr("Αποτυχία φόρτωσης του αρχείου."));
        }
    }
}

void NamesFileDialog::buttonCancelActivation()
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

void NamesFileDialog::buttonCancelClicked()
{
    close();
}

bool NamesFileDialog::readAndDisplay(QString namesFilePath)
{
    isfileLoading = true;
    buttonCancelActivation();
    QFile namesFile(namesFilePath);
    QFileInfo namesFileInfo(namesFilePath);

    if (!(namesFilePath == ""))
    {
        filepathLineEdit->setText(namesFilePath);
    }

    if (namesFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        progressBar->setVisible(true);
        qint64 namesFileSize = namesFile.size();
        progressBar->setRange(0, namesFileSize);
        progressBar->setValue(0);

        QTextStream in(&namesFile);
        QString namesFileContent;

        while (!in.atEnd())
        {
            namesFileContent += in.read(1024);
            progressBar->setValue(namesFile.pos());
            QCoreApplication::processEvents();
        }

        textBrowser->setPlainText(namesFileContent);
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

void NamesFileDialog::buttonApplyClicked()
{
    emit onApplyButtonClicked(namesFilePath);
    close();
}