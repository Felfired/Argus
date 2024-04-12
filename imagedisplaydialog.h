#ifndef IMAGEDISPLAYDIALOG_H
#define IMAGEDISPLAYDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class ImageDisplayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageDisplayDialog(QWidget* parent = nullptr);

    // Function to set the image
    void setImage(const QPixmap& image);

private:
    QLabel* imageLabel;
};

#endif // IMAGEDISPLAYDIALOG_H
