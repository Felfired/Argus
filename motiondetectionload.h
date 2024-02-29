#ifndef MOTIONDETECTIONLOAD_H
#define MOTIONDETECTIONLOAD_H

#include <QDialog>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>

namespace Ui { class MotionDetectionLoad; }

class MotionDetectionLoad : public QDialog
{
	Q_OBJECT

public:
	MotionDetectionLoad(QWidget* parent = nullptr);
	~MotionDetectionLoad();
	void updateProgress(int progress);
	void updateStatus(QString status);
	void resetProgress();
	void onCompletion();

private slots:
	void buttonCancelClicked();

signals:
	void cancelClicked();

private:
	Ui::MotionDetectionLoad* ui;
	QLabel *statusLabel;
	QProgressBar *progressBar;
	QPushButton *cancelButton;
};


#endif //MOTIONDETECTIONLOAD_H
