#include "addpersondialog.h"
#include "./ui_addpersondialog.h"

AddPersonDialog::AddPersonDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AddPersonDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    profileImgPath = "";

    saveButton = ui->saveButton;
    connect(saveButton, &QPushButton::clicked, this, &AddPersonDialog::saveButtonClicked);

    cancelButton = ui->cancelButton;
    connect(cancelButton, &QPushButton::clicked, this, &AddPersonDialog::cancelButtonClicked);

    addProfileButton = ui->addProfileButton;
    connect(addProfileButton, &QPushButton::clicked, this, &AddPersonDialog::addProfileButtonClicked);

    nameEdit = ui->nameEdit;
    nameEdit->setValidator(new GreekLetterValidator);
    connect(nameEdit, &QLineEdit::textChanged, this, &AddPersonDialog::onTextChanged);

    surnameEdit = ui->surnameEdit;
    surnameEdit->setValidator(new GreekLetterValidator);
    connect(surnameEdit, &QLineEdit::textChanged, this, &AddPersonDialog::onTextChanged);

    dateEdit = ui->dateEdit;

    idEdit = ui->idEdit;
    idEdit->setValidator(new QIntValidator);
    connect(idEdit, &QLineEdit::textChanged, this, &AddPersonDialog::onTextChanged);

    lnameEdit = ui->lnameEdit;
    lnameEdit->setValidator(new LatinLetterValidator);
    connect(lnameEdit, &QLineEdit::textChanged, this, &AddPersonDialog::onTextChanged);

    lsurnameEdit = ui->lsurnameEdit;
    lsurnameEdit->setValidator(new LatinLetterValidator);
    connect(lsurnameEdit, &QLineEdit::textChanged, this, &AddPersonDialog::onTextChanged);

    imgErrorLabel = ui->imgErrorLabel;
    nameErrorLabel = ui->nameErrorLabel;
    surnameErrorLabel = ui->surnameErrorLabel;
    idErrorLabel = ui->idErrorLabel;
    dateErrorLabel = ui->dateErrorLabel;
    lnameErrorLabel = ui->lnameErrorLabel;
    lsurnameErrorLabel = ui->lsurnameErrorLabel;
    profilePathDisplay = ui->profilePathDisplay;
    profilePathDisplay->setReadOnly(true);
}

AddPersonDialog::~AddPersonDialog()
{
    delete ui;
}

void AddPersonDialog::cancelButtonClicked()
{
    close();
}

void AddPersonDialog::addProfileButtonClicked()
{
    profileImgPath = QFileDialog::getOpenFileName(this, tr("Άνοιγμα Αρχείου"), "", tr("Αρχεία εικόνας (*.png *.jpg)"));
    profilePathDisplay->setText(profileImgPath);
    if (profileImgPath == "")
    {
        imgErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
        imgErrorLabel->setText("Δεν έχει οριστεί εικόνα προφίλ.");
        // Return early to avoid access violation when opening and closing the file dialog.
        return;
    }
    else
    {
        int rc = validateImage(profileImgPath);
        if (rc == 1)
        {
            imgErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            imgErrorLabel->setText("Μη έγκυρο αρχείο εικόνας.");
            imgValid = false;
        }
        else if (rc == 2)
        {
            imgErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            imgErrorLabel->setText("Μη έγκυρος τύπος εικόνας.");
            imgValid = false;
        }
        else if (rc == 3)
        {
            imgErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            imgErrorLabel->setText("Μη έγκυρες διαστάσεις εικόνας.");
            imgValid = false;
        }
        else if (rc == 0)
        {
            imgErrorLabel->setStyleSheet("QLabel { color : #000000 ; }");
            imgErrorLabel->setText("Η εικόνα είναι έγκυρη.");
            imgValid = true;
        }
    }
    return;
}

void AddPersonDialog::saveButtonClicked()
{
    selectedDate = dateEdit->date();
    dateValid = true;
    int returnCode;
    CatalogService service = new CatalogService();

    if (dateValid == true && idValid == true && nameValid == true && 
        surnameValid == true && lnameValid == true && lsurnameValid == true && imgValid == true)
    {
        bool idExists = service.personExists(id);
        if (idExists == true)
        {
            QMessageBox::critical(this, tr("Σφάλμα!"), "Το συγκεκριμένο αναγνωριστικό υπάρχει ήδη.");
        }
        else if (idExists == false)
        {
            returnCode = service.addPerson(name, surname, id, selectedDate, lname, lsurname, profileImgPath);
        }
    }
    else
    {
        QMessageBox::critical(this, tr("Σφάλμα!"), "Έχετε εισάγει μη έγκυρες πληροφορίες. Παρακαλώ ελέγξτε τα πεδία και δοκιμάστε ξανά.");
    }

    if (returnCode == 0)
    {
        close();
        AddPersonDialog::createSuccessDialog();
    }
}

// Passing parameters by const reference (const QString &) is more efficient than passing by value, 
// especially for large objects like QString. When passed by value, a copy of the object is made, 
// which can be expensive in terms of memory and performance. By passing by const reference, 
// we avoid the overhead of copying the object.
void AddPersonDialog::onTextChanged(const QString &text)
{
    // We get the lineEdit that activated the signal here by utilizing the sender function.
    QLineEdit* targetLineEdit = qobject_cast<QLineEdit*>(sender());

    if (targetLineEdit == nameEdit)
    {
        if (text.length() <= 2)
        {
            nameErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            nameErrorLabel->setText("Το όνομα πρέπει να περιέχει παραπάνω απο 2 χαρακτήρες.");
            nameValid = false;
        }
        if (text.length() > 2 && text.length() <= 40)
        {
            nameErrorLabel->setStyleSheet("QLabel { color : #000000 ; }");
            nameErrorLabel->setText("Το όνομα είναι έγκυρο.");
            nameValid = true;
            name = text;
        }
        if (text.length() > 40)
        {
            nameErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            nameErrorLabel->setText("Το όνομα πρέπει να περιέχει λιγότερους απο 41 χαρακτήρες.");
            nameValid = false;
        }
    }

    else if (targetLineEdit == surnameEdit)
    {
        if (text.length() <= 2)
        {
            surnameErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            surnameErrorLabel->setText("Το επίθετο πρέπει να περιέχει παραπάνω απο 2 χαρακτήρες.");
            surnameValid = false;
        }
        if (text.length() > 2 && text.length() <= 40)
        {
            surnameErrorLabel->setStyleSheet("QLabel { color : #000000 ; }");
            surnameErrorLabel->setText("Το επίθετο είναι έγκυρο.");
            surnameValid = true;
            surname = text;
        }
        if (text.length() > 40)
        {
            surnameErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            surnameErrorLabel->setText("Το επίθετο πρέπει να περιέχει λιγότερους απο 41 χαρακτήρες.");
            surnameValid = false;
        }
    }

    else if (targetLineEdit == idEdit)
    {
        int num = text.toInt();
        if (text.at(0) == 0)
        {
            idErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            idErrorLabel->setText("Το αναγνωριστικό δεν μπορεί να έχει το '0' πρώτα.");
            idValid = false;
        }
        if (num < 1000 || num > 9999)
        {
            idErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            idErrorLabel->setText("Το αναγνωριστικό πρέπει να είναι απο 1000 έως 9999.");
            idValid = false;
        }
        if (num >= 1000 && num <= 9999)
        {
            idErrorLabel->setStyleSheet("QLabel { color : #000000 ; }");
            idErrorLabel->setText("Το αναγνωριστικό είναι έγκυρο.");
            id = text;
            idValid = true;
        }
    }

    else if (targetLineEdit == lnameEdit)
    {
        if (text.length() <= 2)
        {
            lnameErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            lnameErrorLabel->setText("Το όνομα πρέπει να περιέχει παραπάνω απο 2 χαρακτήρες.");
            lnameValid = false;
        }
        if (text.length() > 2 && text.length() <= 40)
        {
            lnameErrorLabel->setStyleSheet("QLabel { color : #000000 ; }");
            lnameErrorLabel->setText("Το όνομα είναι έγκυρο.");
            lnameValid = true;
            lname = text;
        }
        if (text.length() > 40)
        {
            lnameErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            lnameErrorLabel->setText("Το όνομα πρέπει να περιέχει λιγότερους απο 41 χαρακτήρες.");
            lnameValid = false;
        }
    }

    else if (targetLineEdit == lsurnameEdit)
    {
        if (text.length() <= 2)
        {
            lsurnameErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            lsurnameErrorLabel->setText("Το επίθετο πρέπει να περιέχει παραπάνω απο 2 χαρακτήρες.");
            lsurnameValid = false;
        }
        if (text.length() > 2 && text.length() <= 40)
        {
            lsurnameErrorLabel->setStyleSheet("QLabel { color : #000000 ; }");
            lsurnameErrorLabel->setText("Το επίθετο είναι έγκυρο.");
            lsurnameValid = true;
            lsurname = text;
        }
        if (text.length() > 40)
        {
            lsurnameErrorLabel->setStyleSheet("QLabel { color : #ff0f0f ; }");
            lsurnameErrorLabel->setText("Το επίθετο πρέπει να περιέχει λιγότερους απο 41 χαρακτήρες.");
            lsurnameValid = false;
        }
    }
}

int AddPersonDialog::validateImage(QString profileImgPath)
{
    QImage image(profileImgPath);

    // Check if the image is valid.
    if (image.isNull()) 
    {
        return 1;
    }

    // Check if the image format is supported (PNG or JPG).
    if (image.format() == QImage::Format_Invalid) 
    {
        return 2;
    }

    // Check if the image dimensions are 170x170.
    if (image.width() == 256 && image.height() == 256) 
    {
        return 0;
    }
    else 
    {
        return 3;
    }
}

void AddPersonDialog::createSuccessDialog() const
{
    QMessageBox successBox;
    successBox.setWindowTitle("Επιτυχία.");
    QIcon windowIcon(":argus/res/app_icons/plus.png");
    successBox.setWindowIcon(windowIcon);
    successBox.setText("Η καταχώρηση έγινε με αναγνωριστικο: " + id);
    QPixmap successIcon(":argus/res/dialog_icons/OK_DIALOG.png");
    successBox.setIconPixmap(successIcon);
    successBox.addButton(QMessageBox::Ok);
    successBox.exec();
}