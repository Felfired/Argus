#include "imagedisplaydialog.h"

ImageDisplayDialog::ImageDisplayDialog(QWidget* parent) : QDialog(parent)
{
    // Create QLabel to display the image
    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);

    // Create layout for the dialog
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);

    setLayout(layout);
}

void ImageDisplayDialog::setImage(const QPixmap& image)
{
    imageLabel->setPixmap(image);
}