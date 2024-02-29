#ifndef ADDPERSONDIALOG_H
#define ADDPERSONDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QDate>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QToolButton>
#include <QLineEdit>
#include <QDateEdit>
#include <QIntValidator>
#include "catalogservice.h"
#include "greeklettervalidator.h"
#include "latinlettervalidator.h"

namespace Ui { class AddPersonDialog; }

class AddPersonDialog : public QDialog
{
	Q_OBJECT

public:
	AddPersonDialog(QWidget* parent = nullptr);
	~AddPersonDialog();

private slots:
	void saveButtonClicked();
	void cancelButtonClicked();
	void addProfileButtonClicked();
	int validateImage(QString profileImgPath);
	void onTextChanged(const QString &text);
	void createSuccessDialog() const;

private:
	Ui::AddPersonDialog* ui;
	QLabel* imgErrorLabel;
	QLabel* nameErrorLabel;
	QLabel* surnameErrorLabel;
	QLabel* idErrorLabel;
	QLabel* dateErrorLabel;
	QLabel* lnameErrorLabel;
	QLabel* lsurnameErrorLabel;
	QPushButton* saveButton;
	QPushButton* cancelButton;
	QToolButton* addProfileButton;
	QLineEdit* profilePathDisplay;
	QLineEdit* nameEdit;
	QLineEdit* surnameEdit;
	QLineEdit* idEdit;
	QDateEdit* dateEdit;
	QLineEdit* lnameEdit;
	QLineEdit* lsurnameEdit;
	QString profileImgPath;
	QString name;
	QString surname;
	QString id;
	QString lname;
	QString lsurname;
	QDate selectedDate;
	bool imgValid;
	bool nameValid;
	bool surnameValid;
	bool lnameValid;
	bool lsurnameValid;
	bool dateValid;
	bool idValid;
};

#endif // ADDPERSONDIALOG_H
