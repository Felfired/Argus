#include "facedetectiondialog.h"
#include "./ui_facedetectiondialog.h"

FaceDetectionDialog::FaceDetectionDialog(const QString& videoPath, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::FaceDetectionDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);

    closeButton = ui->closeButton;
    connect(closeButton, &QPushButton::clicked, this, &FaceDetectionDialog::closeButtonClicked);

    startButton = ui->startButton;
    connect(startButton, &QPushButton::clicked, this, &FaceDetectionDialog::startButtonClicked);

    selectFolderButton = ui->selectFolderButton;
    connect(selectFolderButton, &QPushButton::clicked, this, &FaceDetectionDialog::selectFolderButtonClicked);

    saveToVideoCheckBox = ui->saveToVideoCheckBox;
    connect(saveToVideoCheckBox, &QCheckBox::stateChanged, this, &FaceDetectionDialog::updateStartButtonState);
    saveToImageCheckBox = ui->saveToImageCheckBox;
    connect(saveToImageCheckBox, &QCheckBox::stateChanged, this, &FaceDetectionDialog::updateStartButtonState);

    QSettings settings("config.ini", QSettings::IniFormat);
    saveFolderPath = settings.value("Save_Preferences/Results_Path").toString();
    saveFolderDisplay = ui->saveFolderDisplay;
    saveFolderDisplay->setText(saveFolderPath);
}

FaceDetectionDialog::~FaceDetectionDialog()
{
    delete ui;
}

void FaceDetectionDialog::closeButtonClicked()
{
    close();
}

void FaceDetectionDialog::startButtonClicked()
{
    FaceDetectionDialog::setParams();

}

void FaceDetectionDialog::selectFolderButtonClicked()
{
    saveFolderPath = QFileDialog::getExistingDirectory(this, "Επιλογή φακελού...", "", QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog);
    if (!saveFolderPath.isEmpty())
    {
        saveFolderDisplay->setText(saveFolderPath);
    }
}

void FaceDetectionDialog::setParams()
{
    saveToVideoFlag = saveToVideoCheckBox->isChecked();
    saveToImageFlag = saveToImageCheckBox->isChecked();
}

void FaceDetectionDialog::enableButtons()
{
    FaceDetectionDialog::updateStartButtonState();
    closeButton->setEnabled(true);
}

void FaceDetectionDialog::disableButtons()
{
    startButton->setEnabled(false);
    closeButton->setEnabled(false);
}

void FaceDetectionDialog::updateStartButtonState()
{
    if (saveToVideoCheckBox->isChecked() || saveToImageCheckBox->isChecked())
    {
        enableButtonFlag = true;
    }
    else if (!saveToVideoCheckBox->isChecked() && !saveToImageCheckBox->isChecked())
    {
        enableButtonFlag = false;
    }
    startButton->setEnabled(enableButtonFlag);
}