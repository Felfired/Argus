#include "facerecognitiondialog.h"
#include "./ui_facerecognitiondialog.h"

FaceRecognitionDialog::FaceRecognitionDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::FaceRecognitionDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);

    progressBar = ui->progressBar;
    progressBar->setVisible(false);

}

FaceRecognitionDialog::~FaceRecognitionDialog()
{
    delete ui;
}