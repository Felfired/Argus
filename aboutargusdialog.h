#ifndef ABOUTARGUSDIALOG_H
#define ABOUTARGUSDIALOG_H

#include <QDialog>

namespace Ui { class AboutArgusDialog; }

class AboutArgusDialog : public QDialog
{
	Q_OBJECT

public:
	AboutArgusDialog(QWidget* parent = nullptr);
	~AboutArgusDialog();

private:
	Ui::AboutArgusDialog* ui;

};

#endif // ABOUTARGUSDIALOG_H
