QT       += core gui
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    extractframesdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    motiondetection.cpp \
    motiondetectiondialog.cpp

HEADERS += \
    extractframesdialog.h \
    mainwindow.h \
    motiondetection.h \
    motiondetectiondialog.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += C:\Users\matdi\Desktop\opencv\build\install\include

LIBS += C:\Users\matdi\Desktop\opencv\build\bin\libopencv_core470.dll
LIBS += C:\Users\matdi\Desktop\opencv\build\bin\libopencv_highgui470.dll
LIBS += C:\Users\matdi\Desktop\opencv\build\bin\libopencv_imgcodecs470.dll
LIBS += C:\Users\matdi\Desktop\opencv\build\bin\libopencv_videoio470.dll
LIBS += C:\Users\matdi\Desktop\opencv\build\bin\libopencv_imgproc470.dll
LIBS += C:\Users\matdi\Desktop\opencv\build\bin\libopencv_video470.dll


RESOURCES += \
    resources.qrc
