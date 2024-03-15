/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionMetadata;
    QAction *actionClearLog;
    QAction *actionDetectMotion;
    QAction *actionUnload;
    QAction *actionNames;
    QAction *actionWeights;
    QAction *actionConfig;
    QAction *actionQt;
    QAction *actionOpenCV;
    QAction *actionVS;
    QAction *actionArgus;
    QAction *actionContact;
    QAction *actionCatalog;
    QAction *actionTrain;
    QAction *actionSavePrefs;
    QAction *actionDataset;
    QAction *actionFaceDetection;
    QAction *actionFaceRecognition;
    QAction *actionCaffeConfig;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridVideoControl;
    QSlider *sliderSeek;
    QLabel *labelDuration;
    QLabel *labelCurrent;
    QLabel *labelSep;
    QFrame *lineSepT;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *videoFrame;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *videoButtons;
    QSlider *sliderVolume;
    QLabel *labelVolume;
    QFrame *lineSepL;
    QPushButton *buttonPause;
    QPushButton *buttonDecRate;
    QPushButton *buttonPlay;
    QPushButton *buttonIncRate;
    QPushButton *buttonStop;
    QFrame *lineSepR;
    QLabel *labelRateTxt;
    QLabel *labelRate;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QTextEdit *textLogger;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QWidget *fileviewWidget;
    QListView *galleryListView;
    QFrame *filecontrolFrame;
    QToolButton *buttonOpenFolder;
    QToolButton *buttonDeleteImage;
    QPushButton *buttonToggleView;
    QToolButton *toolButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGraphicsView *imagegraphicsView;
    QFrame *line;
    QFrame *line_2;
    QFrame *frame;
    QToolButton *buttonZoomIn;
    QToolButton *buttonZoomOut;
    QToolButton *buttonZoomReset;
    QFrame *line_3;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuAbout;
    QMenu *menuSettings;
    QMenu *menuDNN;
    QMenu *menuTools;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1549, 864);
        MainWindow->setMinimumSize(QSize(900, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/argus/res/app_icons/argus.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/argus/res/app_icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/argus/res/app_icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName("actionHelp");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/argus/res/app_icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon3);
        actionMetadata = new QAction(MainWindow);
        actionMetadata->setObjectName("actionMetadata");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/argus/res/app_icons/metadata.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMetadata->setIcon(icon4);
        actionClearLog = new QAction(MainWindow);
        actionClearLog->setObjectName("actionClearLog");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/argus/res/app_icons/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearLog->setIcon(icon5);
        actionDetectMotion = new QAction(MainWindow);
        actionDetectMotion->setObjectName("actionDetectMotion");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/argus/res/app_icons/motion_detection.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDetectMotion->setIcon(icon6);
        actionUnload = new QAction(MainWindow);
        actionUnload->setObjectName("actionUnload");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/argus/res/app_icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnload->setIcon(icon7);
        actionNames = new QAction(MainWindow);
        actionNames->setObjectName("actionNames");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/argus/res/app_icons/object.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNames->setIcon(icon8);
        actionNames->setVisible(true);
        actionWeights = new QAction(MainWindow);
        actionWeights->setObjectName("actionWeights");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/argus/res/app_icons/weight.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWeights->setIcon(icon9);
        actionConfig = new QAction(MainWindow);
        actionConfig->setObjectName("actionConfig");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/argus/res/app_icons/cogs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfig->setIcon(icon10);
        actionQt = new QAction(MainWindow);
        actionQt->setObjectName("actionQt");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/argus/res/app_icons/qt.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQt->setIcon(icon11);
        actionOpenCV = new QAction(MainWindow);
        actionOpenCV->setObjectName("actionOpenCV");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/argus/res/app_icons/ocv.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenCV->setIcon(icon12);
        actionVS = new QAction(MainWindow);
        actionVS->setObjectName("actionVS");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/argus/res/app_icons/vs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVS->setIcon(icon13);
        actionArgus = new QAction(MainWindow);
        actionArgus->setObjectName("actionArgus");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/argus/res/app_icons/ar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArgus->setIcon(icon14);
        actionContact = new QAction(MainWindow);
        actionContact->setObjectName("actionContact");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/argus/res/app_icons/contact.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContact->setIcon(icon15);
        actionCatalog = new QAction(MainWindow);
        actionCatalog->setObjectName("actionCatalog");
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/argus/res/app_icons/catalog.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCatalog->setIcon(icon16);
        actionTrain = new QAction(MainWindow);
        actionTrain->setObjectName("actionTrain");
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/argus/res/app_icons/training.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTrain->setIcon(icon17);
        actionSavePrefs = new QAction(MainWindow);
        actionSavePrefs->setObjectName("actionSavePrefs");
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/argus/res/app_icons/diskette.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSavePrefs->setIcon(icon18);
        actionDataset = new QAction(MainWindow);
        actionDataset->setObjectName("actionDataset");
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/argus/res/app_icons/dataset.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDataset->setIcon(icon19);
        actionFaceDetection = new QAction(MainWindow);
        actionFaceDetection->setObjectName("actionFaceDetection");
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/argus/res/app_icons/detection.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFaceDetection->setIcon(icon20);
        actionFaceDetection->setMenuRole(QAction::NoRole);
        actionFaceRecognition = new QAction(MainWindow);
        actionFaceRecognition->setObjectName("actionFaceRecognition");
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/argus/res/app_icons/recognition.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFaceRecognition->setIcon(icon21);
        actionFaceRecognition->setMenuRole(QAction::NoRole);
        actionCaffeConfig = new QAction(MainWindow);
        actionCaffeConfig->setObjectName("actionCaffeConfig");
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/argus/res/app_icons/caffe_settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCaffeConfig->setIcon(icon22);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 510, 691, 41));
        gridVideoControl = new QGridLayout(gridLayoutWidget);
        gridVideoControl->setObjectName("gridVideoControl");
        gridVideoControl->setContentsMargins(0, 0, 0, 0);
        sliderSeek = new QSlider(gridLayoutWidget);
        sliderSeek->setObjectName("sliderSeek");
        sliderSeek->setMaximumSize(QSize(600, 16777215));
        sliderSeek->setOrientation(Qt::Horizontal);

        gridVideoControl->addWidget(sliderSeek, 1, 0, 1, 1, Qt::AlignVCenter);

        labelDuration = new QLabel(gridLayoutWidget);
        labelDuration->setObjectName("labelDuration");
        labelDuration->setLayoutDirection(Qt::LeftToRight);
        labelDuration->setAlignment(Qt::AlignCenter);

        gridVideoControl->addWidget(labelDuration, 1, 3, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        labelCurrent = new QLabel(gridLayoutWidget);
        labelCurrent->setObjectName("labelCurrent");

        gridVideoControl->addWidget(labelCurrent, 1, 1, 1, 1, Qt::AlignVCenter);

        labelSep = new QLabel(gridLayoutWidget);
        labelSep->setObjectName("labelSep");

        gridVideoControl->addWidget(labelSep, 1, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        lineSepT = new QFrame(gridLayoutWidget);
        lineSepT->setObjectName("lineSepT");
        lineSepT->setFrameShape(QFrame::HLine);
        lineSepT->setFrameShadow(QFrame::Sunken);

        gridVideoControl->addWidget(lineSepT, 0, 0, 1, 4);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 691, 451));
        videoFrame = new QHBoxLayout(horizontalLayoutWidget);
        videoFrame->setObjectName("videoFrame");
        videoFrame->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(20, 470, 691, 41));
        videoButtons = new QHBoxLayout(horizontalLayoutWidget_2);
        videoButtons->setObjectName("videoButtons");
        videoButtons->setContentsMargins(0, 0, 0, 0);
        sliderVolume = new QSlider(horizontalLayoutWidget_2);
        sliderVolume->setObjectName("sliderVolume");
        sliderVolume->setMaximumSize(QSize(80, 16777215));
        sliderVolume->setOrientation(Qt::Horizontal);

        videoButtons->addWidget(sliderVolume, 0, Qt::AlignVCenter);

        labelVolume = new QLabel(horizontalLayoutWidget_2);
        labelVolume->setObjectName("labelVolume");
        labelVolume->setMaximumSize(QSize(30, 16777215));

        videoButtons->addWidget(labelVolume, 0, Qt::AlignVCenter);

        lineSepL = new QFrame(horizontalLayoutWidget_2);
        lineSepL->setObjectName("lineSepL");
        lineSepL->setFrameShape(QFrame::VLine);
        lineSepL->setFrameShadow(QFrame::Sunken);

        videoButtons->addWidget(lineSepL);

        buttonPause = new QPushButton(horizontalLayoutWidget_2);
        buttonPause->setObjectName("buttonPause");
        buttonPause->setMaximumSize(QSize(30, 30));
        buttonPause->setStyleSheet(QString::fromUtf8(""));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/argus/res/app_icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPause->setIcon(icon23);
        buttonPause->setIconSize(QSize(16, 16));

        videoButtons->addWidget(buttonPause);

        buttonDecRate = new QPushButton(horizontalLayoutWidget_2);
        buttonDecRate->setObjectName("buttonDecRate");
        buttonDecRate->setMaximumSize(QSize(30, 30));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/argus/res/app_icons/decrease_speed.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDecRate->setIcon(icon24);

        videoButtons->addWidget(buttonDecRate);

        buttonPlay = new QPushButton(horizontalLayoutWidget_2);
        buttonPlay->setObjectName("buttonPlay");
        buttonPlay->setMaximumSize(QSize(30, 30));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/argus/res/app_icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPlay->setIcon(icon25);
        buttonPlay->setIconSize(QSize(16, 16));

        videoButtons->addWidget(buttonPlay);

        buttonIncRate = new QPushButton(horizontalLayoutWidget_2);
        buttonIncRate->setObjectName("buttonIncRate");
        buttonIncRate->setMaximumSize(QSize(30, 30));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/argus/res/app_icons/increase_speed.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonIncRate->setIcon(icon26);

        videoButtons->addWidget(buttonIncRate);

        buttonStop = new QPushButton(horizontalLayoutWidget_2);
        buttonStop->setObjectName("buttonStop");
        buttonStop->setMaximumSize(QSize(30, 30));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/argus/res/app_icons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonStop->setIcon(icon27);

        videoButtons->addWidget(buttonStop);

        lineSepR = new QFrame(horizontalLayoutWidget_2);
        lineSepR->setObjectName("lineSepR");
        lineSepR->setFrameShape(QFrame::VLine);
        lineSepR->setFrameShadow(QFrame::Sunken);

        videoButtons->addWidget(lineSepR);

        labelRateTxt = new QLabel(horizontalLayoutWidget_2);
        labelRateTxt->setObjectName("labelRateTxt");
        labelRateTxt->setMaximumSize(QSize(70, 16777215));
        QFont font;
        font.setPointSize(9);
        labelRateTxt->setFont(font);
        labelRateTxt->setAlignment(Qt::AlignCenter);

        videoButtons->addWidget(labelRateTxt);

        labelRate = new QLabel(horizontalLayoutWidget_2);
        labelRate->setObjectName("labelRate");
        labelRate->setMaximumSize(QSize(40, 16777215));
        labelRate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        videoButtons->addWidget(labelRate);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(20, 550, 691, 161));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textLogger = new QTextEdit(gridLayoutWidget_2);
        textLogger->setObjectName("textLogger");
        textLogger->setMaximumSize(QSize(16777215, 120));
        textLogger->setFrameShape(QFrame::WinPanel);

        gridLayout->addWidget(textLogger, 1, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(840, 510, 681, 221));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        fileviewWidget = new QWidget(gridLayoutWidget_3);
        fileviewWidget->setObjectName("fileviewWidget");
        galleryListView = new QListView(fileviewWidget);
        galleryListView->setObjectName("galleryListView");
        galleryListView->setGeometry(QRect(0, 0, 681, 221));
        galleryListView->setFrameShape(QFrame::WinPanel);

        gridLayout_2->addWidget(fileviewWidget, 0, 0, 1, 1);

        filecontrolFrame = new QFrame(centralwidget);
        filecontrolFrame->setObjectName("filecontrolFrame");
        filecontrolFrame->setEnabled(true);
        filecontrolFrame->setGeometry(QRect(810, 510, 30, 221));
        filecontrolFrame->setFrameShape(QFrame::StyledPanel);
        filecontrolFrame->setFrameShadow(QFrame::Raised);
        buttonOpenFolder = new QToolButton(filecontrolFrame);
        buttonOpenFolder->setObjectName("buttonOpenFolder");
        buttonOpenFolder->setGeometry(QRect(0, 0, 30, 30));
        buttonOpenFolder->setMaximumSize(QSize(30, 30));
        buttonOpenFolder->setIcon(icon1);
        buttonDeleteImage = new QToolButton(filecontrolFrame);
        buttonDeleteImage->setObjectName("buttonDeleteImage");
        buttonDeleteImage->setGeometry(QRect(0, 30, 30, 30));
        buttonDeleteImage->setMaximumSize(QSize(30, 30));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/argus/res/app_icons/x.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDeleteImage->setIcon(icon28);
        buttonToggleView = new QPushButton(filecontrolFrame);
        buttonToggleView->setObjectName("buttonToggleView");
        buttonToggleView->setGeometry(QRect(0, 60, 30, 30));
        buttonToggleView->setMaximumSize(QSize(30, 30));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/argus/res/app_icons/view_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonToggleView->setIcon(icon29);
        toolButton = new QToolButton(filecontrolFrame);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(0, 90, 30, 30));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/argus/res/app_icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon30);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(810, 20, 711, 481));
        tab = new QWidget();
        tab->setObjectName("tab");
        imagegraphicsView = new QGraphicsView(tab);
        imagegraphicsView->setObjectName("imagegraphicsView");
        imagegraphicsView->setGeometry(QRect(-10, 0, 731, 421));
        imagegraphicsView->setMinimumSize(QSize(689, 400));
        line = new QFrame(tab);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 410, 721, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(tab);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(480, 420, 16, 31));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        frame = new QFrame(tab);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(490, 420, 221, 31));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        buttonZoomIn = new QToolButton(frame);
        buttonZoomIn->setObjectName("buttonZoomIn");
        buttonZoomIn->setGeometry(QRect(60, 0, 30, 30));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/argus/res/app_icons/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonZoomIn->setIcon(icon31);
        buttonZoomOut = new QToolButton(frame);
        buttonZoomOut->setObjectName("buttonZoomOut");
        buttonZoomOut->setGeometry(QRect(90, 0, 30, 30));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/argus/res/app_icons/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonZoomOut->setIcon(icon32);
        buttonZoomReset = new QToolButton(frame);
        buttonZoomReset->setObjectName("buttonZoomReset");
        buttonZoomReset->setGeometry(QRect(120, 0, 30, 30));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/argus/res/app_icons/zoom_reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonZoomReset->setIcon(icon33);
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/res/icons/select.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon34, QString());
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(810, 490, 710, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1549, 22));
        menubar->setStyleSheet(QString::fromUtf8(""));
        menubar->setLocale(QLocale(QLocale::Greek, QLocale::Greece));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuFile->setStyleSheet(QString::fromUtf8(""));
        menuFile->setToolTipsVisible(true);
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuHelp->setToolTipsVisible(true);
        menuAbout = new QMenu(menuHelp);
        menuAbout->setObjectName("menuAbout");
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/argus/res/app_icons/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAbout->setIcon(icon35);
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        menuDNN = new QMenu(menuSettings);
        menuDNN->setObjectName("menuDNN");
        menuDNN->setEnabled(true);
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/argus/res/app_icons/neural.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuDNN->setIcon(icon36);
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setStyleSheet(QString::fromUtf8(""));
        toolBar->setLocale(QLocale(QLocale::Greek, QLocale::Greece));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(menuAbout->menuAction());
        menuHelp->addSeparator();
        menuHelp->addAction(actionContact);
        menuAbout->addAction(actionQt);
        menuAbout->addAction(actionOpenCV);
        menuAbout->addAction(actionVS);
        menuAbout->addSeparator();
        menuAbout->addAction(actionArgus);
        menuSettings->addAction(menuDNN->menuAction());
        menuSettings->addAction(actionSavePrefs);
        menuDNN->addAction(actionNames);
        menuDNN->addAction(actionWeights);
        menuDNN->addAction(actionConfig);
        menuDNN->addSeparator();
        menuDNN->addAction(actionCaffeConfig);
        menuTools->addAction(actionCatalog);
        menuTools->addAction(actionTrain);
        menuTools->addAction(actionDataset);
        toolBar->addAction(actionMetadata);
        toolBar->addAction(actionClearLog);
        toolBar->addAction(actionUnload);
        toolBar->addSeparator();
        toolBar->addAction(actionDetectMotion);
        toolBar->addAction(actionFaceDetection);
        toolBar->addAction(actionFaceRecognition);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Argus", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\316\206\316\275\316\277\316\271\316\263\316\274\316\261", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "\316\206\316\275\316\277\316\271\316\263\316\274\316\261 \316\265\316\275\317\214\317\202 \316\261\317\201\317\207\316\265\316\257\316\277\317\205.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExit->setText(QCoreApplication::translate("MainWindow", "\316\210\316\276\316\277\316\264\316\277\317\202", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainWindow", "\316\210\316\276\316\277\316\264\316\277\317\202 \316\261\317\200\316\277 \317\204\316\277 \317\200\317\201\317\214\316\263\317\201\316\261\316\274\316\274\316\261.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionHelp->setText(QCoreApplication::translate("MainWindow", "\316\237\316\264\316\267\316\263\317\214\317\202...", nullptr));
        actionHelp->setIconText(QCoreApplication::translate("MainWindow", "Help", nullptr));
#if QT_CONFIG(tooltip)
        actionHelp->setToolTip(QCoreApplication::translate("MainWindow", "\316\206\316\275\316\277\316\271\316\263\316\274\316\261 \317\204\316\277\317\205 \316\277\316\264\316\267\316\263\316\277\317\215 \317\207\317\201\316\256\317\203\316\267\317\202.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMetadata->setText(QString());
#if QT_CONFIG(tooltip)
        actionMetadata->setToolTip(QCoreApplication::translate("MainWindow", "\316\240\317\201\316\277\316\262\316\277\316\273\316\256 \316\274\316\265\317\204\316\261\316\264\316\265\316\264\316\277\316\274\316\255\316\275\317\211\316\275.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionClearLog->setText(QString());
#if QT_CONFIG(tooltip)
        actionClearLog->setToolTip(QCoreApplication::translate("MainWindow", "\316\232\316\261\316\270\316\261\317\201\316\271\317\203\316\274\317\214\317\202 \316\267\316\274\316\265\317\201\316\277\316\273\316\277\316\263\316\257\316\277\317\205 \316\265\316\272\317\204\316\255\316\273\316\265\317\203\316\267\317\202.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDetectMotion->setText(QString());
#if QT_CONFIG(tooltip)
        actionDetectMotion->setToolTip(QCoreApplication::translate("MainWindow", "\316\221\316\275\316\257\317\207\316\275\316\265\317\205\317\203\316\267 \316\272\316\257\316\275\316\267\317\203\316\267\317\202.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionUnload->setText(QString());
#if QT_CONFIG(tooltip)
        actionUnload->setToolTip(QCoreApplication::translate("MainWindow", "\316\221\317\206\316\261\316\257\317\201\316\265\317\203\316\267 \317\206\316\277\317\201\317\204\317\211\316\274\316\255\316\275\316\277\317\205 \316\261\317\201\317\207\316\265\316\257\316\277\317\205.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionNames->setText(QCoreApplication::translate("MainWindow", "\316\221\317\201\317\207\316\265\316\257\316\277 \316\237\316\275\316\277\316\274\316\254\317\204\317\211\316\275...", nullptr));
        actionWeights->setText(QCoreApplication::translate("MainWindow", "\316\221\317\201\317\207\316\265\316\257\316\277 \316\222\316\261\317\201\317\216\316\275...", nullptr));
        actionConfig->setText(QCoreApplication::translate("MainWindow", "\316\221\317\201\317\207\316\265\316\257\316\277 \316\240\316\261\317\201\316\261\316\274\316\265\317\204\317\201\316\277\317\200\316\277\316\271\316\256\317\203\316\265\317\211\316\275...", nullptr));
        actionQt->setText(QCoreApplication::translate("MainWindow", "\316\243\317\207\316\265\317\204\316\271\316\272\316\254 \316\274\316\265 \317\204\316\277 Qt...", nullptr));
        actionOpenCV->setText(QCoreApplication::translate("MainWindow", "\316\243\317\207\316\265\317\204\316\271\316\272\316\254 \316\274\316\265 \317\204\316\277 OpenCV...", nullptr));
        actionVS->setText(QCoreApplication::translate("MainWindow", "\316\243\317\207\316\265\317\204\316\271\316\272\316\254 \316\274\316\265 \317\204\316\277 Visual Studio 2022...", nullptr));
        actionArgus->setText(QCoreApplication::translate("MainWindow", "\316\243\317\207\316\265\317\204\316\271\316\272\316\254 \316\274\316\265 \317\204\316\277 Argus...", nullptr));
        actionContact->setText(QCoreApplication::translate("MainWindow", "\316\225\317\200\316\271\316\272\316\277\316\271\316\275\317\211\316\275\316\257\316\261", nullptr));
        actionCatalog->setText(QCoreApplication::translate("MainWindow", "\316\232\316\261\317\204\316\254\316\273\316\277\316\263\316\277\317\202 \316\221\317\204\317\214\316\274\317\211\316\275...", nullptr));
        actionTrain->setText(QCoreApplication::translate("MainWindow", "\316\225\316\272\317\200\316\261\316\257\316\264\316\265\317\205\317\203\316\267 \316\235\316\265\317\205\317\201\317\211\316\275\316\271\316\272\316\277\317\215 \316\224\316\271\316\272\317\204\317\215\316\277\317\205...", nullptr));
        actionSavePrefs->setText(QCoreApplication::translate("MainWindow", "\316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202 \316\221\317\200\316\277\316\270\316\256\316\272\316\265\317\205\317\203\316\267\317\202...", nullptr));
        actionDataset->setText(QCoreApplication::translate("MainWindow", "\316\224\316\265\316\264\316\277\316\274\316\255\316\275\316\261 \316\246\317\211\317\204\316\277\316\263\317\201\316\261\317\206\316\271\317\216\316\275...", nullptr));
        actionFaceDetection->setText(QString());
#if QT_CONFIG(tooltip)
        actionFaceDetection->setToolTip(QCoreApplication::translate("MainWindow", "\316\225\316\275\317\204\316\277\317\200\316\271\317\203\316\274\317\214\317\202 \317\200\317\201\316\277\317\203\317\216\317\200\317\211\316\275.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFaceRecognition->setText(QString());
        actionFaceRecognition->setIconText(QString());
#if QT_CONFIG(tooltip)
        actionFaceRecognition->setToolTip(QCoreApplication::translate("MainWindow", "\316\221\316\275\316\261\316\263\316\275\317\216\317\201\316\271\317\203\316\267 \317\200\317\201\316\277\317\203\317\216\317\200\317\211\316\275.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCaffeConfig->setText(QCoreApplication::translate("MainWindow", "\316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202 \316\234\316\277\316\275\317\204\316\255\316\273\316\277\317\205 \316\225\316\275\317\204\316\277\317\200\316\271\317\203\316\274\316\277\317\215 \316\240\317\201\316\277\317\203\317\216\317\200\317\211\316\275...", nullptr));
        labelDuration->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        labelCurrent->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        labelSep->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        labelVolume->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        buttonPause->setText(QString());
        buttonDecRate->setText(QString());
        buttonPlay->setText(QString());
        buttonIncRate->setText(QString());
        buttonStop->setText(QString());
        labelRateTxt->setText(QCoreApplication::translate("MainWindow", "\316\244\316\261\317\207\317\215\317\204\316\267\317\204\316\261:", nullptr));
        labelRate->setText(QCoreApplication::translate("MainWindow", "1x", nullptr));
#if QT_CONFIG(tooltip)
        textLogger->setToolTip(QCoreApplication::translate("MainWindow", "Log output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        buttonOpenFolder->setToolTip(QCoreApplication::translate("MainWindow", "\316\225\317\200\316\271\316\273\316\277\316\263\316\256 \317\206\316\261\316\272\316\255\316\273\316\277\317\205.", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonOpenFolder->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        buttonDeleteImage->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        buttonToggleView->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\316\225\316\275\316\261\316\273\316\273\316\261\316\263\316\256 \317\200\317\201\316\277\316\265\317\200\316\271\317\203\316\272\317\214\317\200\316\271\317\203\316\267\317\202 \316\265\316\271\316\272\317\214\316\275\316\261\317\202.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonToggleView->setText(QString());
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        buttonZoomIn->setToolTip(QCoreApplication::translate("MainWindow", "\316\234\316\265\316\263\316\255\316\270\317\205\316\275\317\203\316\267 \316\265\316\271\316\272\317\214\316\275\316\261\317\202.", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonZoomIn->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        buttonZoomOut->setToolTip(QCoreApplication::translate("MainWindow", "\316\243\316\274\316\257\316\272\317\201\317\205\316\275\317\203\316\267 \316\265\316\271\316\272\317\214\316\275\316\261\317\202.", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonZoomOut->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        buttonZoomReset->setToolTip(QCoreApplication::translate("MainWindow", "\316\225\317\200\316\261\316\275\316\261\317\206\316\277\317\201\316\254 \316\265\316\271\316\272\317\214\316\275\316\261\317\202.", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonZoomReset->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\316\240\317\201\316\277\316\262\316\277\316\273\316\256 \316\225\316\271\316\272\317\214\316\275\317\211\316\275", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\316\221\317\201\317\207\316\265\316\257\316\277", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "\316\222\316\277\316\256\316\270\316\265\316\271\316\261", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "\316\243\317\207\316\265\317\204\316\271\316\272\316\254", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "\316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202", nullptr));
        menuDNN->setTitle(QCoreApplication::translate("MainWindow", "\316\241\317\205\316\270\316\274\316\257\317\203\316\265\316\271\317\202 \316\235\316\265\317\205\317\201\317\211\316\275\316\271\316\272\316\277\317\215 \316\224\316\271\316\272\317\204\317\215\316\277\317\205", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "\316\225\317\201\316\263\316\261\316\273\316\265\316\257\316\261", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
