#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QSlider>
#include <QVideoWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QMediaMetaData>
#include <QPushButton>
#include <QAudioOutput>
#include <QToolBar>
#include <QTextEdit>
#include <QProgressBar>
#include <QToolButton>
#include <QFileSystemModel>
#include <QListView>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QModelIndex>
#include <QGraphicsPixmapItem>
#include <QResizeEvent>
#include <QMessageBox>
#include "motiondetectiondialog.h"
#include "extractframesdialog.h"
#include "namesfiledialog.h"
#include "weightsfiledialog.h"
#include "configfiledialog.h"
#include "catalogdialog.h"
#include "saveconfigdialog.h"
#include "datasetdialog.h"
#include "motiondetection.h"
#include "caffeconfigdialog.h"
#include "facedetectiondialog.h"
#include "facerecognitiondialog.h"
#include "recognitionconfigdialog.h"
#include "aboutargusdialog.h"
#include "aboutopencvdialog.h"
#include "contacthelpdialog.h"
#include <opencv2/core/cuda.hpp>
#include <opencv2/core/core.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setVideoDuration();
    void updateVideoDuration(qint64 currentDuration);
    void getMetadata();
    void resizeEvent(QResizeEvent* event) override;
    void loadImage(const QString &pathToImage);
    void updateLogger(QString logText);
    QString getLogTime();
    QString getVideoPath();

signals:

private slots:
    void actionOpenTriggered();
    void buttonPlayClicked();
    void buttonStopClicked();
    void buttonPauseClicked();
    void buttonDecRateClicked();
    void buttonIncRateClicked();
    void actionExitTriggered();
    void actionMetadataTriggered();
    void actionClearLogTriggered();
    void actionDetectMotionTriggered();
    void actionExtractFramesTriggered();
    void actionUnloadTriggered();
    void actionNamesTriggered();
    void actionWeightsTriggered();
    void actionConfigTriggered();
    void actionCatalogTriggered();
    void actionSavePrefsTriggered();
    void actionDatasetTriggered();
    void actionFaceDetectionTriggered();
    void actionFaceRecognitionTriggered();
    void actionRecognitionConfigTriggered();
    void actionCaffeConfigTriggered();
    void actionAboutArgusTriggered();
    void actionOpenCVTriggered();
    void actionContactTriggered();
    void buttonOpenFolderClicked();
    void buttonToggleViewClicked();
    void buttonZoomInClicked();
    void buttonZoomOutClicked();
    void buttonZoomResetClicked();
    void onGalleryFileDoubleClicked(const QModelIndex &index);
    void onVideoLoaded(bool videoLoaded);
    void saveNamesFile(const QString& filePath);
    void saveWeightsFile(const QString& filePath);
    void saveConfigFile(const QString& filePath);
    void loadConfiguration();
    bool validateDNNFiles();
    void resultsFolderManagement(QString toolSelection);

private:
    Ui::MainWindow* ui;
    QMediaPlayer* videoPlayer;
    QVideoWidget* videoWidget;
    QAudioOutput* audioOutput;
    QSlider* sliderSeek;
    QSlider* sliderVolume;
    QHBoxLayout* videoFrame;
    QLabel* labelDuration;
    QLabel* labelCurrent;
    QLabel* labelVolume;
    QLabel* labelRate;
    QAction* actionOpen;
    QAction* actionExit;
    QAction* actionMetadata;
    QAction* actionClearLog;
    QAction* actionDetectMotion;
    QAction* actionExtractFrames;
    QAction* actionUnload;
    QAction* actionNames;
    QAction* actionWeights;
    QAction* actionConfig;
    QAction* actionCatalog;
    QAction* actionSavePrefs;
    QAction* actionDataset;
    QAction* actionFaceDetection;
    QAction* actionFaceRecognition;
    QAction* actionCaffeConfig;
    QAction* actionRecognitionConfig;
    QAction* actionAboutArgus;
    QAction* actionOpenCV;
    QAction* actionContact;
    QPushButton *buttonPlay;
    QPushButton *buttonPause;
    QPushButton *buttonStop;
    QPushButton *buttonIncRate;
    QPushButton *buttonDecRate;
    QTextEdit *textLogger;
    QProgressBar *detectionProgress;
    QToolBar *toolBar;
    qreal playbackRate;
    QString output;
    QToolButton *buttonOpenFolder;
    QFileSystemModel galleryModel;
    QListView *galleryListView;
    QPushButton *buttonToggleView;
    QGraphicsView *imagegraphicsView;
    QGraphicsScene *imagegraphicsScene;
    QGraphicsPixmapItem *imageDisplayed;
    QToolButton *buttonZoomIn;
    QToolButton *buttonZoomOut;
    QToolButton *buttonZoomReset;
    QString lastImagePath;
    QString placeholderImagePath;
    QString loadedVideoPath;
    QString namesFilePath;
    QString weightsFilePath;
    QString configFilePath;
    QPixmap lastImage;
    QUrl nullUrl;
    MotionDetectionDialog* motiondetectionDialog;
    ExtractFramesDialog* extractframesDialog;
    WeightsFileDialog* weightsfileDialog;
    ConfigFileDialog* configfileDialog;
    NamesFileDialog* namesfileDialog;
    CatalogDialog* catalogDialog;
    DatasetDialog* datasetDialog;
    SaveConfigDialog* saveConfigDialog;
    CaffeConfigDialog* caffeConfigDialog;
    FaceDetectionDialog* faceDetectionDialog;
    FaceRecognitionDialog* faceRecognitionDialog;
    RecognitionConfigDialog* recognitionConfigDialog;
    AboutArgusDialog* aboutArgusDialog;
    AboutOpencvDialog* aboutOpencvDialog;
    ContactHelpDialog* contactHelpDialog;
    bool videoLoaded;
    bool toggleViewButtonState;
    int zoomCap;
};
#endif // MAINWINDOW_H

