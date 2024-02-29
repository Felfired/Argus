#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint);
    w.move(0, 0);
    w.showMaximized();
    return a.exec();
}
