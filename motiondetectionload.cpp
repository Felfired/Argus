#include "motiondetectionload.h"
#include "./ui_motiondetectionload.h"

MotionDetectionLoad::MotionDetectionLoad(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::MotionDetectionLoad)
{
    ui->setupUi(this);
    statusLabel = ui->statusLabel;
    progressBar = ui->progressBar;
    cancelButton = ui->cancelButton;
    connect(cancelButton, &QPushButton::clicked, this, &MotionDetectionLoad::buttonCancelClicked);
}

void MotionDetectionLoad::updateStatus(QString status)
{
    statusLabel->setText(status);
}

void MotionDetectionLoad::updateProgress(int progress)
{
    progressBar->setValue(progress);
}

void MotionDetectionLoad::resetProgress()
{
    progressBar->setValue(0);
}

void MotionDetectionLoad::buttonCancelClicked()
{
    emit cancelClicked();
}

void MotionDetectionLoad::onCompletion()
{
    close();
}

MotionDetectionLoad::~MotionDetectionLoad()
{
    delete ui;
}