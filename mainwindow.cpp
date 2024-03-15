#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playbackRate = 1;
    videoLoaded = false;
    zoomCap = 0;
    
    MainWindow::loadConfiguration();

    actionOpen = ui->actionOpen;
    connect(actionOpen, &QAction::triggered, this, &MainWindow::actionOpenTriggered);
    addAction(actionOpen);

    actionExit = ui->actionExit;
    connect(actionExit, &QAction::triggered, this, &MainWindow::actionExitTriggered);
    addAction(actionExit);

    actionNames = ui->actionNames;
    connect(actionNames, &QAction::triggered, this, &MainWindow::actionNamesTriggered);
    addAction(actionNames);

    actionWeights = ui->actionWeights;
    connect(actionWeights, &QAction::triggered, this, &MainWindow::actionWeightsTriggered);
    addAction(actionWeights);

    actionConfig = ui->actionConfig;
    connect(actionConfig, &QAction::triggered, this, &MainWindow::actionConfigTriggered);
    addAction(actionConfig);

    actionMetadata = ui->actionMetadata;
    actionMetadata->setEnabled(false);
    connect(actionMetadata, &QAction::triggered, this, &MainWindow::actionMetadataTriggered);
    addAction(actionMetadata);

    actionClearLog = ui->actionClearLog;
    connect(actionClearLog, &QAction::triggered, this, &MainWindow::actionClearLogTriggered);
    addAction(actionClearLog);

    actionUnload = ui->actionUnload;
    connect(actionUnload, &QAction::triggered, this, &MainWindow::actionUnloadTriggered);
    addAction(actionUnload);
    actionUnload->setEnabled(false);

    actionDetectMotion = ui->actionDetectMotion;
    actionDetectMotion->setEnabled(false);
    connect(actionDetectMotion, &QAction::triggered, this, &MainWindow::actionDetectMotionTriggered);
    connect(this, &MainWindow::onVideoLoaded, actionDetectMotion, &QAction::setEnabled);
    addAction(actionDetectMotion);

    actionFaceDetection = ui->actionFaceDetection;
    actionFaceDetection->setEnabled(false);
    connect(actionFaceDetection, &QAction::triggered, this, &MainWindow::actionFaceDetectionTriggered);
    connect(this, &MainWindow::onVideoLoaded, actionFaceDetection, &QAction::setEnabled);
    addAction(actionFaceDetection);

    actionCatalog = ui->actionCatalog;
    connect(actionCatalog, &QAction::triggered, this, &MainWindow::actionCatalogTriggered);
    addAction(actionCatalog);

    actionSavePrefs = ui->actionSavePrefs;
    connect(actionSavePrefs, &QAction::triggered, this, &MainWindow::actionSavePrefsTriggered);
    addAction(actionSavePrefs);

    actionDataset = ui->actionDataset;
    connect(actionDataset, &QAction::triggered, this, &MainWindow::actionDatasetTriggered);
    addAction(actionDataset);

    actionCaffeConfig = ui->actionCaffeConfig;
    connect(actionCaffeConfig, &QAction::triggered, this, &MainWindow::actionCaffeConfigTriggered);
    addAction(actionCaffeConfig);

    buttonPlay = ui->buttonPlay;
    buttonPlay->setToolTip("Αναπαραγωγή.");
    connect(buttonPlay, &QPushButton::clicked, this, &MainWindow::buttonPlayClicked);
    buttonPlay->setEnabled(false);

    buttonPause = ui->buttonPause;
    buttonPause->setToolTip("Παύση.");
    connect(buttonPause, &QPushButton::clicked, this, &MainWindow::buttonPauseClicked);
    buttonPause->setEnabled(false);

    buttonStop = ui->buttonStop;
    buttonStop->setToolTip("Διακοπή.");
    connect(buttonStop, &QPushButton::clicked, this, &MainWindow::buttonStopClicked);
    buttonStop->setEnabled(false);

    buttonDecRate = ui->buttonDecRate;
    buttonDecRate->setToolTip("Μείωση ταχύτητας αναπαραγωγής.");
    labelRate = ui->labelRate;
    connect(buttonDecRate, &QPushButton::clicked, this, &MainWindow::buttonDecRateClicked);
    buttonDecRate->setEnabled(false);

    buttonIncRate = ui->buttonIncRate;
    buttonIncRate->setToolTip("Αύξηση ταχύτητας αναπαραγωγής.");
    connect(buttonIncRate, &QPushButton::clicked, this, &MainWindow::buttonIncRateClicked);
    buttonIncRate->setEnabled(false);

    videoPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    videoPlayer->setVideoOutput(videoWidget);
    videoFrame = ui->videoFrame;
    videoFrame->addWidget(videoWidget);

    audioOutput = new QAudioOutput(this);
    videoPlayer->setAudioOutput(audioOutput);

    labelVolume = ui->labelVolume;
    sliderVolume = ui->sliderVolume;
    sliderVolume->setRange(0, 100);
    sliderVolume->setValue(audioOutput->volume());
    connect(sliderVolume, &QSlider::valueChanged, audioOutput, &QAudioOutput::setVolume);
    connect(sliderVolume, &QSlider::valueChanged, [&](int volume)
    {
        QString currentVolume = QString::number(volume) + "%";
        labelVolume->setText(currentVolume);
    });

    labelCurrent = ui->labelCurrent;
    labelCurrent->setText("00:00:00");

    sliderSeek = ui->sliderSeek;
    connect(videoPlayer, &QMediaPlayer::durationChanged, sliderSeek, &QSlider::setMaximum);
    connect(videoPlayer, &QMediaPlayer::positionChanged, sliderSeek, &QSlider::setValue);
    connect(sliderSeek, &QSlider::sliderMoved, videoPlayer, &QMediaPlayer::setPosition);

    textLogger = ui->textLogger;
    textLogger->setReadOnly(true);
    textLogger->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    output = getLogTime() + " Argus v0.02, all rights reserved.";
    textLogger->append(output);

    galleryListView = ui->galleryListView;
    connect(galleryListView, &QListView::doubleClicked, this, &MainWindow::onGalleryFileDoubleClicked);

    buttonToggleView = ui->buttonToggleView;
    toggleViewButtonState = false;
    connect(buttonToggleView, &QToolButton::clicked, this, &MainWindow::buttonToggleViewClicked);

    buttonOpenFolder = ui->buttonOpenFolder;
    connect(buttonOpenFolder, &QToolButton::clicked, this, &MainWindow::buttonOpenFolderClicked);

    placeholderImagePath = ":argus/res/images/placeholder-image.png";
    QImage getImage(placeholderImagePath);

    imagegraphicsView = ui->imagegraphicsView;
    imagegraphicsScene = new QGraphicsScene(this);
    imageDisplayed = new QGraphicsPixmapItem(QPixmap::fromImage(getImage));
    imagegraphicsScene->addItem(imageDisplayed);
    imagegraphicsView->setScene(imagegraphicsScene);
    imagegraphicsView->fitInView(imageDisplayed, Qt::KeepAspectRatio);
    imagegraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    imagegraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    imagegraphicsView->show();

    buttonZoomIn = ui->buttonZoomIn;
    connect(buttonZoomIn, &QToolButton::clicked, this, &MainWindow::buttonZoomInClicked);

    buttonZoomOut = ui->buttonZoomOut;
    connect(buttonZoomOut, &QToolButton::clicked, this, &MainWindow::buttonZoomOutClicked);

    buttonZoomReset = ui->buttonZoomReset;
    connect(buttonZoomReset, &QToolButton::clicked, this, &MainWindow::buttonZoomResetClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadConfiguration()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    if (settings.contains("DNN_Configuration/Names_File"))
    {
        namesFilePath = settings.value("DNN_Configuration/Names_File").toString();
    }
    if (settings.contains("DNN_Configuration/Weights_File"))
    {
        weightsFilePath = settings.value("DNN_Configuration/Weights_File").toString();
    }
    if (settings.contains("DNN_Configuration/Config_File"))
    {
        configFilePath = settings.value("DNN_Configuration/Config_File").toString();
    }
}

void MainWindow::actionOpenTriggered()
{
    loadedVideoPath = QFileDialog::getOpenFileName(this, "Άνοιγμα ενός αρχείου βίντεο.", "", "Video File (*.avi, *.mpg, *.mp4)");
    buttonStopClicked();
    videoPlayer->setSource(QUrl::fromLocalFile(loadedVideoPath));
    output = getLogTime() + " Φόρτωση αρχείου...";
    textLogger->append(output);

    //Catch the LoadedMedia status so we know the video is ready to be played.
    connect(videoPlayer, &QMediaPlayer::mediaStatusChanged, [&](QMediaPlayer::MediaStatus status)
    {
        if (status == QMediaPlayer::LoadedMedia && !videoLoaded)
        {
            videoPlayer->setPlaybackRate(playbackRate);
            actionMetadata->setDisabled(0);
            setVideoDuration();
            output = getLogTime() + " Έτοιμο.";
            textLogger->append(output);
            videoLoaded = true;
            //Emit the signal indicating the change in the video loaded state.
            emit onVideoLoaded(true);
        }

        else if (status == QMediaPlayer::InvalidMedia)
        {
            ui->statusbar->showMessage(" Παρουσιάστηκε σφάλμα φόρτωσης του αρχείου.");
        }
    });

    //Catch the PositionChanged event to update the timer accordingly.
    connect(videoPlayer, &QMediaPlayer::positionChanged, [&](qint64 currentDuration)
    {
        updateVideoDuration(currentDuration);
    });
}

void MainWindow::buttonPlayClicked()
{
    videoPlayer->play();
    ui->statusbar->showMessage("Αναπαραγωγή...");
}

void MainWindow::buttonStopClicked()
{
    videoPlayer->stop();
    ui->statusbar->showMessage("Διακοπή...");
}

void MainWindow::buttonPauseClicked()
{
    videoPlayer->pause();
    ui->statusbar->showMessage("Παύση...");
}

void MainWindow::buttonDecRateClicked()
{
    if (playbackRate > 0.25)
    {
        playbackRate = playbackRate - 0.25;
        videoPlayer->setPlaybackRate(playbackRate);
        QString currentRate = QString::number(playbackRate) + "x";
        labelRate->setText(currentRate);
    }
}

void MainWindow::buttonIncRateClicked()
{
    if (playbackRate < 4)
    {
        playbackRate = playbackRate + 0.25;
        videoPlayer->setPlaybackRate(playbackRate);
        QString currentRate = QString::number(playbackRate) + "x";
        labelRate->setText(currentRate);
    }
}

void MainWindow::buttonOpenFolderClicked()
{
    QString rootPath = QFileDialog::getExistingDirectory(nullptr, "Επιλογή φακέλου...");
    galleryModel.setRootPath(rootPath);
    galleryListView->setModel(&galleryModel);
    galleryListView->setRootIndex(galleryModel.index(rootPath));
    output = getLogTime() + " Άνοιγμα φακέλου απο την τοποθεσία " + rootPath;
    textLogger->append(output);
}

void MainWindow::buttonToggleViewClicked()
{
    QString offIconPath = ":argus/res/app_icons/view_off.png";
    QString onIconPath = ":argus/res/app_icons/view_on.png";
    QIcon onIcon(onIconPath);
    QIcon offIcon(offIconPath);

    if(toggleViewButtonState == true)
    {
        buttonToggleView->setIcon(offIcon);
        toggleViewButtonState = false;
        output = getLogTime() + " Απενεργοποίηση προεπισκόπησης εικόνας.";
        textLogger->append(output);
        loadImage(placeholderImagePath);
    }

    else if(toggleViewButtonState == false)
    {

        if(lastImagePath.isEmpty())
        {
            QMessageBox::information(this, "Ενημέρωση", "Για να ανοίξετε την προεπισκόπιση πρέπει να επιλέξετε μια εικόνα.");
            return;
        }

        else
        {
            buttonToggleView->setIcon(onIcon);
            toggleViewButtonState = true;
            output = getLogTime() + " Ενεργοποίηση προεπισκόπησης εικόνας.";
            textLogger->append(output);
            loadImage(lastImagePath);
        }
    }
}

void MainWindow::onGalleryFileDoubleClicked(const QModelIndex &index)
{
    if(toggleViewButtonState == true)
    {
        lastImagePath = galleryModel.fileInfo(index).absoluteFilePath();
        loadImage(lastImagePath);
    }

    else if(toggleViewButtonState == false)
    {
        lastImagePath = galleryModel.fileInfo(index).absoluteFilePath();
        return;
    }

}

void MainWindow::buttonZoomInClicked()
{
    if(zoomCap > -5)
    {
        imagegraphicsView->scale(1.2, 1.2);
        zoomCap = zoomCap - 1;

        if(zoomCap < 0)
        {
            imagegraphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        }
        else
        {
            imagegraphicsView->setDragMode(QGraphicsView::NoDrag);
        }
    }
    else
    {
        return;
    }
}

void MainWindow::buttonZoomOutClicked()
{
    if(zoomCap < 5)
    {
        imagegraphicsView->scale(1/1.2, 1/1.2);
        zoomCap = zoomCap + 1;

        if(zoomCap < 0)
        {
            imagegraphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        }
        else
        {
            imagegraphicsView->setDragMode(QGraphicsView::NoDrag);
        }
    }
    else
    {
        return;
    }
}

void MainWindow::buttonZoomResetClicked()
{
    if(zoomCap > 0)
    {
        while(zoomCap > 0)
        {
            imagegraphicsView->scale(1.2, 1.2);
            zoomCap = zoomCap - 1;
        }
    }

    else if(zoomCap < 0)
    {
        while(zoomCap < 0)
        {
            imagegraphicsView->scale(1/1.2, 1/1.2);
            zoomCap = zoomCap + 1;
        }
    }

    else if(zoomCap == 0)
    {
        return;
    }
}

void MainWindow::actionExitTriggered()
{
    QCoreApplication::quit();
}

void MainWindow::actionMetadataTriggered()
{
    getMetadata();
}

void MainWindow::actionClearLogTriggered()
{
    textLogger->clear();
}

void MainWindow::actionDetectMotionTriggered()
{
    bool validateFiles;
    validateFiles = validateDNNFiles();
    if (validateFiles == true)
    {
        motiondetectionDialog = new MotionDetectionDialog(loadedVideoPath, namesFilePath, weightsFilePath, configFilePath, this);
        motiondetectionDialog->show();
        motiondetectionDialog->activateWindow();
    }
    else if (validateFiles == false)
    {
        QMessageBox::critical(this, tr("Σφάλμα"), tr("Τα αρχεία που απαιτούνται από το νευρωνικό δίκτυο δεν έχουν ρυθμιστεί σωστά. "
            "Ανατρέξτε στην καρτέλα \"Ρυθμίσεις Νευρωνικού Δικτύου\" για να ελέγξετε για σφάλματα."));
    }
}

void MainWindow::actionExtractFramesTriggered()
{
    extractframesDialog->show();
    extractframesDialog->activateWindow();
}

void MainWindow::actionUnloadTriggered()
{
    videoPlayer->stop();
    videoPlayer->setSource(QUrl());
    labelDuration->setText("00:00:00");
    labelCurrent->setText("00:00:00");
    videoLoaded = false;
    emit onVideoLoaded(videoLoaded);
    QString output = getLogTime() + " Το αρχείο αποφορτώθηκε...";
    textLogger->append(output);

}

void MainWindow::actionNamesTriggered()
{
    namesfileDialog = new NamesFileDialog(namesFilePath);
    connect(namesfileDialog, &NamesFileDialog::onApplyButtonClicked, this, &MainWindow::saveNamesFile);
    namesfileDialog->show();
    namesfileDialog->activateWindow();
}

void MainWindow::actionWeightsTriggered()
{
    weightsfileDialog = new WeightsFileDialog(weightsFilePath);
    connect(weightsfileDialog, &WeightsFileDialog::onApplyButtonClicked, this, &MainWindow::saveWeightsFile);
    weightsfileDialog->show();
    weightsfileDialog->activateWindow();
}

void MainWindow::actionConfigTriggered()
{
    configfileDialog = new ConfigFileDialog(configFilePath);
    connect(configfileDialog, &ConfigFileDialog::onApplyButtonClicked, this, &MainWindow::saveConfigFile);
    configfileDialog->show();
    configfileDialog->activateWindow();
}

void MainWindow::actionCatalogTriggered()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    if (settings.contains("Save_Preferences/Catalog_Path"))
    {
        catalogDialog = new CatalogDialog();
        catalogDialog->show();
        catalogDialog->activateWindow();
    }
    else
    {
        QMessageBox::critical(this, tr("Σφάλμα"), tr("Ο φάκελος αποθήκευσης αρχείων καταλόγου δεν έχει οριστεί. "
        "Ανατρέξτε στην καρτέλα \"Ρυθμίσεις Αποθήκευσης\" για να ορίσετε την τοποθεσία αποθήκευσης."));         
    }
}

void MainWindow::actionSavePrefsTriggered()
{
    saveConfigDialog = new SaveConfigDialog();
    saveConfigDialog->show();
    saveConfigDialog->activateWindow();
}

void MainWindow::actionDatasetTriggered()
{
    datasetDialog = new DatasetDialog();
    datasetDialog->show();
    datasetDialog->activateWindow();
}

void MainWindow::actionFaceDetectionTriggered()
{
    faceDetectionDialog = new FaceDetectionDialog(loadedVideoPath, this);
    faceDetectionDialog->show();
    faceDetectionDialog->activateWindow();
}

void MainWindow::actionCaffeConfigTriggered()
{
    caffeConfigDialog = new CaffeConfigDialog();
    caffeConfigDialog->show();
    caffeConfigDialog->activateWindow();
}

void MainWindow::saveNamesFile(const QString& filePath)
{
    namesFilePath = filePath;
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("DNN_Configuration/Names_File", namesFilePath);
}

void MainWindow::saveWeightsFile(const QString& filePath)
{
    weightsFilePath = filePath;
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("DNN_Configuration/Weights_File", weightsFilePath);
}

void MainWindow::saveConfigFile(const QString& filePath)
{
    configFilePath = filePath;
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("DNN_Configuration/Config_File", configFilePath);
}

bool MainWindow::validateDNNFiles()
{
    QFileInfo namesFileInfo(namesFilePath);
    QFileInfo weightsFileInfo(weightsFilePath);
    QFileInfo configFileInfo(configFilePath);

    if ((namesFileInfo.exists() && namesFileInfo.isFile())
        && (weightsFileInfo.exists() && weightsFileInfo.isFile())
        && (configFileInfo.exists() && configFileInfo.isFile()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::onVideoLoaded(bool videoLoaded)
{
    actionDetectMotion->setEnabled(videoLoaded);
    actionFaceDetection->setEnabled(videoLoaded);
    actionMetadata->setEnabled(videoLoaded);
    buttonDecRate->setEnabled(videoLoaded);
    buttonIncRate->setEnabled(videoLoaded);
    buttonPause->setEnabled(videoLoaded);
    buttonPlay->setEnabled(videoLoaded);
    buttonStop->setEnabled(videoLoaded);
    actionOpen->setEnabled(!videoLoaded);
    actionUnload->setEnabled(videoLoaded);
}

void MainWindow::setVideoDuration()
{
    QMediaMetaData mData = videoPlayer->metaData();
    QVariant videoDuration = mData.value(QMediaMetaData::Duration);
    qint64 mVideoDuration = videoDuration.toLongLong();
    QTime tVideoDuration(0, 0, 0, 0);
    tVideoDuration = tVideoDuration.addMSecs(mVideoDuration);
    QString sVideoDuration = tVideoDuration.toString("hh:mm:ss");
    labelDuration = ui->labelDuration;
    labelDuration->setText(sVideoDuration);
}

void MainWindow::updateVideoDuration(qint64 currentDuration)
{
    QTime tCurrentDuration(0, 0, 0, 0);
    tCurrentDuration = tCurrentDuration.addMSecs(currentDuration);
    QString sCurrentDuration = tCurrentDuration.toString("hh:mm:ss");
    labelCurrent->setText(sCurrentDuration);
}

void MainWindow::getMetadata()
{
    textLogger->append("--Μεταδεδομένα--");
    QMediaMetaData mData = videoPlayer->metaData();
    // Extract and display all metadata
    QList<QMediaMetaData::Key> keys = mData.keys();
    for (const QMediaMetaData::Key &key : keys)
    {
        QVariant value = mData.value(key);
        if (key == QMediaMetaData::VideoFrameRate)
        {
            if (value.isValid())
            {
                double framerate = value.toDouble();
                textLogger->append("Ρυθμός ανανέωσης καρέ: " + QString::number(framerate) + " fps");
            }

            else
            {
                textLogger->append("Ο ρυθμός ανανέωσης καρέ δεν είναι διαθέσιμος.");
            }
        }
        else if (key == QMediaMetaData::Title)
        {
            if (value.isValid())
            {
                QString title = value.toString();
                textLogger->append("Τιτλός: " + title);
            }

            else
            {
                textLogger->append("Ο τίτλος του βίντεο δεν είναι διαθέσιμος.");
            }
        }

        else if (key == QMediaMetaData::Resolution)
        {
            if (value.isValid())
            {
                QSize resolution = value.toSize();
                textLogger->append("Ανάλυση: " + QString::number(resolution.width()) + "x" + QString::number(resolution.height()));
            }

            else
            {
                textLogger->append("Η ανάλυση του βίντεο δεν είναι διαθέσιμη.");
            }
        }
    }
}

QString MainWindow::getLogTime()
{
    QString currentTime = QDateTime::currentDateTime().toString("hh:mm:ss") + ":";
    return currentTime;
}

QString MainWindow::getVideoPath()
{
    return loadedVideoPath;
}

void MainWindow::updateLogger(QString logText)
{
    output = getLogTime() + logText;
    textLogger->append(output);
}

void MainWindow::loadImage(const QString &pathToImage)
{
    QImage getImage(pathToImage);
    imagegraphicsScene->clear();
    imageDisplayed = new QGraphicsPixmapItem(QPixmap::fromImage(getImage));
    imagegraphicsScene->addItem(imageDisplayed);
    imagegraphicsView->fitInView(imageDisplayed, Qt::KeepAspectRatio);

    if (pathToImage == placeholderImagePath)
    {
        imagegraphicsView->resetTransform();
    }
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    QRectF bounds = imagegraphicsScene->itemsBoundingRect();
    imagegraphicsView->fitInView(bounds, Qt::KeepAspectRatio);
}


