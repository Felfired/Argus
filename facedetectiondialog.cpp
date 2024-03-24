#include "facedetectiondialog.h"
#include "facedetection.h"
#include "./ui_facedetectiondialog.h"

FaceDetectionDialog::FaceDetectionDialog(const QString& videoPath, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::FaceDetectionDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    loadedVideoPath = videoPath;

    scaleFactorSpinBox = ui->scaleFactorSpinBox;
    scaleFactorSpinBox->setRange(0.1, 2.0);
    scaleFactorSpinBox->setSingleStep(0.01);
    scaleFactorSpinBox->setDecimals(2);
    scaleFactorSpinBox->setValue(0.8);

    confidenceThresholdSpinBox = ui->confidenceThresholdSpinBox;
    confidenceThresholdSpinBox->setRange(0.01, 0.99);
    confidenceThresholdSpinBox->setSingleStep(0.01);
    confidenceThresholdSpinBox->setDecimals(2);
    confidenceThresholdSpinBox->setValue(0.25);

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
    saveToTxtCheckBox = ui->saveToTxtCheckBox;
    connect(saveToTxtCheckBox, &QCheckBox::stateChanged, this, &FaceDetectionDialog::updateStartButtonState);

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
    FaceDetection init = new FaceDetection();
    init.start(this, loadedVideoPath, saveToVideoFlag, saveToImageFlag, saveToTxtFlag, scaleFactor, confidenceThreshold);
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
    saveToTxtFlag = saveToTxtCheckBox->isChecked();
    scaleFactor = scaleFactorSpinBox->value();
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
    if (saveToVideoCheckBox->isChecked() || saveToImageCheckBox->isChecked() || saveToTxtCheckBox->isChecked())
    {
        enableButtonFlag = true;
    }
    else if (!saveToVideoCheckBox->isChecked() && !saveToImageCheckBox->isChecked() && !saveToTxtCheckBox->isChecked())
    {
        enableButtonFlag = false;
    }
    startButton->setEnabled(enableButtonFlag);
}