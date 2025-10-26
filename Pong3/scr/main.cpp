#include "mainwindowqt.h"
#include <QApplication>

#ifdef Q_OS_WIN
#include <windows.h> //pour SetProcessDPIAware
#endif

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

#ifdef Q_OS_WIN
    //empeche Windows de redimensionner automatiquement la fenetre sur écran HiDPI
    SetProcessDPIAware();
#endif

    mainwindowQT w;
    w.show();
    return a.exec();
}

//magnus carlsen 2024-06
//v0.8
