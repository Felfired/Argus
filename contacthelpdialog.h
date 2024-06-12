#ifndef CONTACTHELPDIALOG_H
#define CONTACTHELPDIALOG_H

#include <QDialog>

namespace Ui { class ContactHelpDialog; }

class ContactHelpDialog : public QDialog
{
	Q_OBJECT

public:
	ContactHelpDialog(QWidget* parent = nullptr);
	~ContactHelpDialog();

private:
	Ui::ContactHelpDialog* ui;

};

#endif // CONTACTHELPDIALOG_H
