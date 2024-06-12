#include "facerecognitiondialog.h"
#include "facerecognition.h"
#include "catalogservice.h"
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
    stopButton->setEnabled(false);
    connect(stopButton, &QToolButton::clicked, this, &FaceRecognitionDialog::stopButtonClicked);

    selectFolderButton = ui->selectFolderButton;
    connect(selectFolderButton, &QPushButton::clicked, this, &FaceRecognitionDialog::selectFolderButtonClicked);

    progressBar = ui->progressBar;
    progressBar->setVisible(false);

    folderDisplayLineEdit = ui->folderDisplayLineEdit;
    folderDisplayLineEdit->setReadOnly(true);

    distanceCalculationComboBox = ui->distanceCalculationComboBox;
    distanceCalculationComboBox->addItem("Συνημιτόνου");
    distanceCalculationComboBox->addItem("Ευκλείδιος");

    saveToTextCheckBox = ui->saveToTextCheckBox;

    resultsTableWidget = ui->resultsTableWidget;
    resultsTableWidget->setColumnCount(3);
    QStringList tableHeaders;
    tableHeaders << "-" << "Όνομα" << "Επίθετο";
    resultsTableWidget->setHorizontalHeaderLabels(tableHeaders);
    resultsTableWidget->verticalHeader()->setDefaultSectionSize(75);
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

void FaceRecognitionDialog::stopButtonClicked()
{
    selectFolderButton->setEnabled(true);
    stopButton->setEnabled(false);
    buttonBox->setEnabled(true);
    progressBar->setVisible(false);
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
    FaceRecognitionDialog::clearResultsTable();
    FaceRecognitionDialog::setParams();
    bool saveToTxtFlag = saveToTextCheckBox->isChecked();
    FaceRecognition init = new FaceRecognition();
    init.start(this, folderPath, distanceCalculationMode, saveToTxtFlag);
    buttonBox->setEnabled(false);
    selectFolderButton->setEnabled(false);
    stopButton->setEnabled(false);
    progressBar->setVisible(true);
    if (onRecognitionCompleted() == 0)
    {
        accept();
    }
}

int FaceRecognitionDialog::onRecognitionCompleted()
{
    return 1;
}

void FaceRecognitionDialog::setLoadingProgress(int progress)
{
    progressBar->setValue(progress);
}

void FaceRecognitionDialog::onCompletion()
{
    progressBar->setVisible(false);
    progressBar->setValue(0);
    stopButton->setEnabled(false);
    buttonBox->setEnabled(true);
    selectFolderButton->setEnabled(true);
}

void FaceRecognitionDialog::addRecognitionToTable(std::string idFound)
{
    QString id = QString::fromUtf8(idFound.c_str());
    CatalogService service;
    QStringList entryData;
    entryData = service.getEntryData(id);
    QString name = entryData.at(0);
    QString surname = entryData.at(1);
    int thumbnailWidth = 75;
    int thumbnailHeight = 75;

    int rowCount = ui->resultsTableWidget->rowCount();
    resultsTableWidget->insertRow(rowCount);

    QLabel* thumbnailLabel = new QLabel;
    thumbnailLabel->setAlignment(Qt::AlignCenter);
    QLabel* nameLabel = new QLabel;
    QLabel* surnameLabel = new QLabel;
    nameLabel->setText(name);
    surnameLabel->setText(surname);
    QPixmap thumbnail(entryData.at(8)); // Replace "thumbnail.png" with your actual image file
    thumbnail = thumbnail.scaled(thumbnailWidth, thumbnailHeight, Qt::KeepAspectRatio);
    thumbnailLabel->setPixmap(thumbnail);
    resultsTableWidget->setCellWidget(rowCount, 0, thumbnailLabel);
    resultsTableWidget->setCellWidget(rowCount, 1, nameLabel);
    resultsTableWidget->setCellWidget(rowCount, 2, surnameLabel);
    resultsTableWidget->update();
}

void FaceRecognitionDialog::clearResultsTable()
{
    resultsTableWidget->clearContents();
    resultsTableWidget->setRowCount(0);
}