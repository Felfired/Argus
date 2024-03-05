#ifndef MOTIONDETECTIONDIALOG_H
#define MOTIONDETECTIONDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QSpacerItem>
#include <QSlider>
#include <QSpinBox>
#include <QDoubleSpinbox>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QString>
#include <QPixmap>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>

class MotionDetectionDialog : public QDialog
{
    Q_OBJECT

public:
    MotionDetectionDialog(const QString &videoPath, const QString &namesFilePath, const QString &weightsFilePath, const QString &configFilePath, QWidget *parent = nullptr);
    QSpinBox* getFrameskipSpinBox() const;
    void setParams();
    void disableButtons();
    void enableButtons();

private slots:
    void updateOkButtonState();
    void buttonSelectFolderClicked();
    void buttonOkClicked();

private:
    QVBoxLayout *mainLayout;
    QVBoxLayout *sensitivityMainLayout;
    QVBoxLayout *savesettingsMainLayout;
    QHBoxLayout *frameskipLayout;
    QHBoxLayout *buttonLayout;
    QHBoxLayout *selectfolderLayout;
    QHBoxLayout *sensitivityLayout;
    QHBoxLayout *csensitivityLayout;
    QHBoxLayout *repeatmovementLayout;
    QSpacerItem *spacerItem;
    QGroupBox *sensitivityGroupBox;
    QGroupBox *savesettingsGroupBox;
    QCheckBox *sensitivityCheckBox;
    QDoubleSpinBox *sensitivitySpinBox;
    QCheckBox *repeatmovementCheckBox;
    QLineEdit *folderpathLineEdit;
    QSpinBox *frameskipSpinBox;
    QComboBox *sensitivityComboBox;
    QLabel *frameskipLabel;
    QCheckBox *timestampCheckBox;
    QCheckBox *imgsaveCheckBox;
    QCheckBox *fbfCheckBox;
    QLabel *sensitivityLabel;
    QPushButton *selectfolderButton;
    QPushButton *okButton;
    QPushButton *closeButton;
    QString folderPath;
    QString videocapPath;
    QString namesFilePath;
    QString weightsFilePath;
    QString configFilePath;
    bool enableFlag;
    bool timestampFlag;
    bool imgsaveFlag;
    bool fbfFlag;
    double sensitivity;
    int frameskipNum;
};

#endif // MOTIONDETECTIONDIALOG_H
