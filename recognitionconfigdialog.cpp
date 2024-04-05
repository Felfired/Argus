#include "recognitionconfigdialog.h"
#include "./ui_recognitionconfigdialog.h"

RecognitionConfigDialog::RecognitionConfigDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::RecognitionConfigDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);

    sfaceFPLineEdit = ui->sfaceFPLineEdit;
    sfaceFPLineEdit->setReadOnly(true);

    cancelButton = ui->cancelButton;
    connect(cancelButton, &QPushButton::clicked, this, &RecognitionConfigDialog::cancelButtonClicked);

    applyButton = ui->applyButton;
    applyButton->setEnabled(false);
    connect(applyButton, &QPushButton::clicked, this, &RecognitionConfigDialog::applyButtonClicked);

    cancelButton = ui->cancelButton;
    connect(cancelButton, &QPushButton::clicked, this, &RecognitionConfigDialog::cancelButtonClicked);

    openSfaceFileButton = ui->openSfaceFileButton;
    connect(openSfaceFileButton, &QPushButton::clicked, this, &RecognitionConfigDialog::openSFaceFileButtonClicked);

    QSettings settings("config.ini", QSettings::IniFormat);
    if (settings.contains("Recognition_Preferences/SFace_Path"))
    {
        originalSfaceFilePath = settings.value("Recognition_Preferences/SFace_Path").toString();
        sfaceFilePath = originalSfaceFilePath;
        sfaceFPLineEdit->setText(sfaceFilePath);
    }
}

RecognitionConfigDialog::~RecognitionConfigDialog()
{
    delete ui;
}

void RecognitionConfigDialog::cancelButtonClicked()
{
    close();
}

void RecognitionConfigDialog::openSFaceFileButtonClicked()
{
    sfaceFilePath = QFileDialog::getOpenFileName(this, tr("Επιλογή Αρχείου..."), "", tr("Αρχεία Μοντέλου (*.onnx)"));
    sfaceFPLineEdit->setText(sfaceFilePath);

    if (sfaceFilePath != originalSfaceFilePath)
    {
        applyButton->setEnabled(true);
    }
}

void RecognitionConfigDialog::applyButtonClicked()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("Recognition_Preferences/SFace_Path", sfaceFilePath);
    settings.sync();
    close();
}