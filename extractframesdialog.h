#ifndef EXTRACTFRAMESDIALOG_H
#define EXTRACTFRAMESDIALOG_H

#include <QDialog>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ExtractFramesDialog : public QDialog
{
    Q_OBJECT

public:
    ExtractFramesDialog(QWidget *parent = nullptr);

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *frameskipLayout;
    QHBoxLayout *buttonLayout;
    QSpinBox *frameskipSpinBox;
    QLabel *frameskipLabel;
    QPushButton *okButton;
    QPushButton *closeButton;
};

#endif // EXTRACTFRAMESDIALOG_H
