#include "motiondetectiondialog.h"
#include "motiondetection.h"

MotionDetectionDialog::MotionDetectionDialog(const QString& videoPath, const QString& lnamesFilePath, 
    const QString& lweightsFilePath, const QString& lconfigFilePath, QWidget *parent)
    : QDialog(parent)
{
    enableFlag = false;
    mainLayout = new QVBoxLayout(this);
    videocapPath = videoPath;
    namesFilePath = lnamesFilePath;
    weightsFilePath = lweightsFilePath;
    configFilePath = lconfigFilePath;

    frameskipLayout = new QHBoxLayout();
    frameskipSpinBox = new QSpinBox();
    frameskipSpinBox->setRange(0, 5);
    frameskipSpinBox->setValue(0);
    frameskipSpinBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    frameskipLabel = new QLabel("Αριθμός Παράλειψης Καρέ (0-5): ");
    frameskipLayout->addWidget(frameskipLabel);
    frameskipLayout->addWidget(frameskipSpinBox);
    mainLayout->addLayout(frameskipLayout);

    sensitivityGroupBox = new QGroupBox("Ρυθμίσεις Ευαισθησίας");
    sensitivityMainLayout = new QVBoxLayout(sensitivityGroupBox);
    sensitivityLayout = new QHBoxLayout();
    csensitivityLayout = new QHBoxLayout();
    repeatmovementLayout = new QHBoxLayout();

    sensitivityLabel = new QLabel("Ευαισθησία Ανίχνευσης: ");
    sensitivityLayout->addWidget(sensitivityLabel);
    sensitivityComboBox = new QComboBox();
    sensitivityComboBox->addItem("Πολύ Ευαίσθητο");
    sensitivityComboBox->addItem("Ευαίσθητο");
    sensitivityComboBox->addItem("Κανονικό");
    sensitivityLayout->addWidget(sensitivityComboBox);
    sensitivityMainLayout->addLayout(sensitivityLayout);

    sensitivityCheckBox = new QCheckBox("Χρήση Συγκεκριμένης Ευαισθησίας (0.1-1): ");
    sensitivitySpinBox = new QDoubleSpinBox();
    sensitivitySpinBox->setRange(0.1, 1);
    sensitivitySpinBox->setSingleStep(0.01);
    sensitivitySpinBox->setDecimals(2);
    sensitivitySpinBox->setValue(0.6);
    sensitivitySpinBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sensitivitySpinBox->setEnabled(false);
    csensitivityLayout->addWidget(sensitivityCheckBox);
    csensitivityLayout->addWidget(sensitivitySpinBox);
    sensitivityMainLayout->addLayout(csensitivityLayout);

    sensitivityGroupBox->setLayout(sensitivityMainLayout);
    mainLayout->addWidget(sensitivityGroupBox);

    connect(sensitivityCheckBox, &QCheckBox::stateChanged, this, [this](int state)
    {
        sensitivitySpinBox->setEnabled(state == Qt::Checked);
        sensitivityComboBox->setEnabled(!(state == Qt::Checked));
    });

    savesettingsGroupBox = new QGroupBox("Επιλογές Αποθήκευσης");
    savesettingsMainLayout = new QVBoxLayout(savesettingsGroupBox);

    timestampCheckBox = new QCheckBox("Αποθήκευση χρονικών στιγμών κίνησης σε αρχείο κειμένου.");
    savesettingsMainLayout->addWidget(timestampCheckBox);
    connect(timestampCheckBox, &QCheckBox::stateChanged, this, &MotionDetectionDialog::updateOkButtonState);

    imgsaveCheckBox = new QCheckBox("Αποθήκευση στιγμιότυπων όπου εντοπίστηκε κίνηση σε βίντεο.");
    savesettingsMainLayout->addWidget(imgsaveCheckBox);
    connect(imgsaveCheckBox, &QCheckBox::stateChanged, this, &MotionDetectionDialog::updateOkButtonState);

    fbfCheckBox = new QCheckBox("Αποθήκευση στιγμιότυπων όπου εντοπίστηκε κίνηση σε ξεχωριστές εικόνες.");
    savesettingsMainLayout->addWidget(fbfCheckBox);
    connect(fbfCheckBox, &QCheckBox::stateChanged, this, &MotionDetectionDialog::updateOkButtonState);

    selectfolderLayout = new QHBoxLayout();
    QString foldericonPath = ":/res/icons/open.png";
    QPixmap foldericonImage(foldericonPath);
    selectfolderButton = new QPushButton();
    selectfolderButton->setIcon(foldericonImage);
    selectfolderButton->setIconSize(foldericonImage.size());
    selectfolderButton->setText(" Επιλογή φακέλου...");
    connect(selectfolderButton, &QPushButton::clicked, this, &MotionDetectionDialog::buttonSelectFolderClicked);
    selectfolderLayout->addWidget(selectfolderButton);
    folderpathLineEdit = new QLineEdit();
    folderpathLineEdit->setReadOnly(true);
    selectfolderLayout->addWidget(folderpathLineEdit);
    savesettingsMainLayout->addLayout(selectfolderLayout);
    mainLayout->addWidget(savesettingsGroupBox);

    QSettings settings("config.ini", QSettings::IniFormat);
    folderPath = settings.value("Save_Preferences/Current_Path").toString();
    folderpathLineEdit->setText(folderPath);

    spacerItem = new QSpacerItem(350, 20);
    mainLayout->addItem(spacerItem);

    buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    okButton = new QPushButton("Εκκίνηση");
    okButton->setFixedSize(81, 24);
    okButton->setEnabled(enableFlag);
    closeButton = new QPushButton("Κλείσιμο");
    closeButton->setFixedSize(81, 24);
    buttonLayout->addWidget(closeButton);
    buttonLayout->addWidget(okButton);
    mainLayout->addLayout(buttonLayout);  

    setWindowTitle(tr("Παραμετροποίηση Ανίχνευσης Κίνησης"));
    setFixedSize(475, 330);
    QIcon windowIcon(":/argus/res/app_icons/motion_detection.png");
    setWindowIcon(windowIcon);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    connect(closeButton, &QPushButton::clicked, this, &MotionDetectionDialog::reject);
    connect(okButton, &QPushButton::clicked, this, &MotionDetectionDialog::buttonOkClicked);
}

QSpinBox* MotionDetectionDialog::getFrameskipSpinBox() const
{
    return frameskipSpinBox;
}

void MotionDetectionDialog::updateOkButtonState()
{
    if(timestampCheckBox->isChecked() || imgsaveCheckBox->isChecked() || fbfCheckBox->isChecked())
    {
        enableFlag = true;
    }
    else if(!timestampCheckBox->isChecked() && !imgsaveCheckBox->isChecked() && !fbfCheckBox->isChecked())
    {
        enableFlag = false;
    }
    okButton->setEnabled(enableFlag);
}

void MotionDetectionDialog::buttonSelectFolderClicked()
{
    folderPath = QFileDialog::getExistingDirectory(this, "Επιλογή φακελού...", "", QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog);
    if(!folderPath.isEmpty())
    {
        folderpathLineEdit->setText(folderPath);
    }
}

void MotionDetectionDialog::setParams()
{
    frameskipNum = frameskipSpinBox->value();

    if(sensitivityComboBox->isEnabled())
    {
        QString selectedSensitivityText = sensitivityComboBox->currentText();
        if (selectedSensitivityText == "Πολύ Ευαίσθητο")
        {
            sensitivity = 0.9;
        }
        else if (selectedSensitivityText == "Ευαίσθητο")
        {
            sensitivity = 0.8;
        }
        else if (selectedSensitivityText == "Κανονικό")
        {
            sensitivity = 0.6;
        }
    }
    else if(!sensitivityComboBox->isEnabled())
    {
        sensitivity = static_cast<double>(sensitivitySpinBox->value());
    }

    timestampFlag = timestampCheckBox->isChecked();
    imgsaveFlag = imgsaveCheckBox->isChecked();
    fbfFlag = fbfCheckBox->isChecked();
}

void MotionDetectionDialog::disableButtons()
{
    okButton->setEnabled(false);
    closeButton->setEnabled(false);
}

void MotionDetectionDialog::enableButtons()
{
    okButton->setEnabled(true);
    closeButton->setEnabled(true);
}

void MotionDetectionDialog::buttonOkClicked()
{
    MotionDetectionDialog::setParams();
    MotionDetection init = new MotionDetection();
    init.start(this, videocapPath, namesFilePath, 
        weightsFilePath, configFilePath, 
        folderPath, imgsaveFlag, 
        timestampFlag, fbfFlag, sensitivity, frameskipNum);
}


