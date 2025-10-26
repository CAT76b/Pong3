/********************************************************************************
** Form generated from reading UI file 'mainwindowqt.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWQT_H
#define UI_MAINWINDOWQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowQT
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainwindowQT)
    {
        if (mainwindowQT->objectName().isEmpty())
            mainwindowQT->setObjectName("mainwindowQT");
        mainwindowQT->resize(800, 600);
        centralwidget = new QWidget(mainwindowQT);
        centralwidget->setObjectName("centralwidget");
        mainwindowQT->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindowQT);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        mainwindowQT->setMenuBar(menubar);
        statusbar = new QStatusBar(mainwindowQT);
        statusbar->setObjectName("statusbar");
        mainwindowQT->setStatusBar(statusbar);

        retranslateUi(mainwindowQT);

        QMetaObject::connectSlotsByName(mainwindowQT);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowQT)
    {
        mainwindowQT->setWindowTitle(QCoreApplication::translate("mainwindowQT", "mainwindowQT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindowQT: public Ui_mainwindowQT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWQT_H
