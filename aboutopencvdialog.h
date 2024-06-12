#ifndef ABOUTOPENCVDIALOG_H
#define ABOUTOPENCVDIALOG_H

#include <QDialog>

namespace Ui { class AboutOpencvDialog; }

class AboutOpencvDialog : public QDialog
{
	Q_OBJECT

public:
	AboutOpencvDialog(QWidget* parent = nullptr);
	~AboutOpencvDialog();

private:
	Ui::AboutOpencvDialog* ui;

};

#endif // ABOUTOPENCVDIALOG_H
