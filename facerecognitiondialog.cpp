#include "facerecognitiondialog.h"
#include "facerecognition.h"
#include "./ui_facerecognitiondialog.h"

FaceRecognitionDialog::FaceRecognitionDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::FaceRecognitionDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);

    buttonBox = ui->buttonBox;
    buttonBox->button(QDialogButtonBox::Ok)->setText("Εκκίνηση");
    buttonBox->button(QDialogButtonBox::Cancel)->setText("Κλείσιμο");
    connect(buttonBox, &QDialogButtonBox::rejected, this, &FaceRecognitionDialog::onRejected);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &FaceRecognitionDialog::onAccepted);

    stopButton = ui->stopButton;

    selectFolderButton = ui->selectFolderButton;
    connect(selectFolderButton, &QPushButton::clicked, this, &FaceRecognitionDialog::selectFolderButtonClicked);

    progressBar = ui->progressBar;
    progressBar->setVisible(false);

    folderDisplayLineEdit = ui->folderDisplayLineEdit;
    folderDisplayLineEdit->setReadOnly(true);

    distanceCalculationComboBox = ui->distanceCalculationComboBox;
    distanceCalculationComboBox->addItem("Συνημιτόνου");
    distanceCalculationComboBox->addItem("Ευκλείδιος");
}

FaceRecognitionDialog::~FaceRecognitionDialog()
{
    delete ui;
}

void FaceRecognitionDialog::onRejected()
{
    close();
}

void FaceRecognitionDialog::selectFolderButtonClicked()
{
    folderPath = QFileDialog::getExistingDirectory(this, "Επιλογή φακελού...", "", QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog);
    if (!folderPath.isEmpty())
    {
        folderDisplayLineEdit->setText(folderPath);
    }
}

void FaceRecognitionDialog::setParams()
{
    distanceCalculationMode = distanceCalculationComboBox->currentText();
    if (folderPath.isEmpty())
    {
        QMessageBox::critical(this, tr("Σφάλμα"), tr("Πρέπει να καθορίσετε έναν φάκελο ο οποίος περιέχει φωτογραφίες προς αναγνώριση."));
    }
}

void FaceRecognitionDialog::onAccepted()
{
    FaceRecognitionDialog::setParams();
    FaceRecognition init = new FaceRecognition();
    init.start(this, folderPath, distanceCalculationMode);
    if (onRecognitionCompleted() == 0)
    {
        accept();
    }
}

int FaceRecognitionDialog::onRecognitionCompleted()
{
    return 1;
}