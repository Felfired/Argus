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
    modelSelectionTabWidget = ui->modelSelectionTabWidget;

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

    yConfidenceThresholdSpinBox = ui->yConfidenceThresholdSpinBox;
    yConfidenceThresholdSpinBox->setRange(0.01, 0.99);
    yConfidenceThresholdSpinBox->setSingleStep(0.01);
    yConfidenceThresholdSpinBox->setDecimals(2);
    yConfidenceThresholdSpinBox->setValue(0.6);

    nmsThresholdSpinBox = ui->nmsThresholdSpinBox;
    nmsThresholdSpinBox->setRange(0.01, 0.99);
    nmsThresholdSpinBox->setSingleStep(0.01);
    nmsThresholdSpinBox->setDecimals(2);
    nmsThresholdSpinBox->setValue(0.3);

    detectionCountSpinBox = ui->detectionCountSpinBox;
    detectionCountSpinBox->setRange(1000, 10000);
    detectionCountSpinBox->setSingleStep(1);
    detectionCountSpinBox->setValue(5000);

    frameskipSpinBox = ui->frameskipSpinBox;
    frameskipSpinBox->setRange(0, 10);
    frameskipSpinBox->setSingleStep(1);
    frameskipSpinBox->setValue(0);
    connect(frameskipSpinBox, &QSpinBox::valueChanged, this, &FaceDetectionDialog::changeFrameskipCheckboxState);

    applyToImageCheckBox = ui->applyToImageCheckBox;
    applyToVideoCheckBox = ui->applyToVideoCheckBox;
    applyToImageCheckBox->setEnabled(false);
    applyToVideoCheckBox->setEnabled(false);

    closeButton = ui->closeButton;
    connect(closeButton, &QPushButton::clicked, this, &FaceDetectionDialog::closeButtonClicked);

    startButton = ui->startButton;
    connect(startButton, &QPushButton::clicked, this, &FaceDetectionDialog::startButtonClicked);

    selectFolderButton = ui->selectFolderButton;
    connect(selectFolderButton, &QPushButton::clicked, this, &FaceDetectionDialog::selectFolderButtonClicked);

    frameskipHelpButton = ui->frameskipHelpButton;
    frameskipHelpButton->setToolTip("Τι είναι αυτό;");
    frameskipHelpButton->setStyleSheet("QPushButton { text-decoration: underline; color: #0000EE; }");
    connect(frameskipHelpButton, &QPushButton::clicked, this, &FaceDetectionDialog::frameskipHelpButtonClicked);

    saveToVideoCheckBox = ui->saveToVideoCheckBox;
    connect(saveToVideoCheckBox, &QCheckBox::stateChanged, this, &FaceDetectionDialog::updateStartButtonState);
    saveToImageCheckBox = ui->saveToImageCheckBox;
    connect(saveToImageCheckBox, &QCheckBox::stateChanged, this, &FaceDetectionDialog::updateStartButtonState);

    QSettings settings("config.ini", QSettings::IniFormat);
    saveFolderPath = settings.value("Save_Preferences/Current_Path").toString();
    saveFolderDisplay = ui->saveFolderDisplay;
    saveFolderDisplay->setText(saveFolderPath);
    saveFolderDisplay->setReadOnly(true);

    FaceDetectionDialog::enableButtons();
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
    init.start(this, loadedVideoPath, saveToVideoFlag, saveToImageFlag, 
        scaleFactor, confidenceThreshold, yConfidenceThreshold, nmsThreshold, detectionCount, selectedModel);
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

    frameskipValue = frameskipSpinBox->value();

    bool applyToImageFlag = applyToImageCheckBox->isChecked();
    bool applyToVideoFlag = applyToVideoCheckBox->isChecked();

    if (applyToImageFlag == false && applyToVideoFlag == false)
    {
        frameskipSelection = 0;
    }
    else if (applyToImageFlag == true && applyToVideoFlag == false)
    {
        frameskipSelection = 1;
    }
    else if (applyToImageFlag == false && applyToVideoFlag == true)
    {
        frameskipSelection = 2;
    }
    else if (applyToImageFlag == true && applyToVideoFlag == true)
    {
        frameskipSelection = 3;
    }

    if (modelSelectionTabWidget->currentIndex() == 0)
    {
        scaleFactor = scaleFactorSpinBox->value();
        confidenceThreshold = confidenceThresholdSpinBox->value();
        yConfidenceThreshold = 0;
        nmsThreshold = 0;
        detectionCount = 0;
        selectedModel = "caffe";
    }
    else if (modelSelectionTabWidget->currentIndex() == 1)
    {
        scaleFactor = 0;
        confidenceThreshold = 0;
        yConfidenceThreshold = yConfidenceThresholdSpinBox->value();
        nmsThreshold = nmsThresholdSpinBox->value();
        detectionCount = detectionCountSpinBox->value();
        selectedModel = "yunet";
    }
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

void FaceDetectionDialog::frameskipHelpButtonClicked()
{
    QMessageBox helpBox;
    helpBox.setWindowTitle("Βοήθεια");
    helpBox.setText("Η συγκεκριμένη επιλογή ρυθμίζει τον αριθμό των καρέ που θα παραλειφθούν από την διαδικασία εξαγωγής εικόνων ή/και τον εντοπισμό προσώπων. Για παράδειγμα για την τιμή <2> θα έχουμε εφαρμογή των αλγορίθμων ανά 2 καρέ.");
    QPushButton* okButton = helpBox.addButton(tr("ΟΚ"), QMessageBox::AcceptRole);
    helpBox.setDefaultButton(okButton);
    helpBox.setIcon(QMessageBox::Information);
    QIcon winIcon = QIcon(":argus/res/app_icons/help.png");
    helpBox.setWindowIcon(winIcon);
    helpBox.exec();
}

void FaceDetectionDialog::changeFrameskipCheckboxState()
{
    int frameskipValue = frameskipSpinBox->value();
    if (frameskipValue != 0)
    {
        applyToImageCheckBox->setEnabled(true);
        applyToVideoCheckBox->setEnabled(true);
    }
    else if (frameskipValue == 0)
    {
        applyToImageCheckBox->setEnabled(false);
        applyToVideoCheckBox->setEnabled(false);
    }
}