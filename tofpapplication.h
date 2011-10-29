#ifndef TOFPAPPLICATION_H
#define TOFPAPPLICATION_H

#include <QApplication>
#include "mainwindow.h"

class TofPApplication : public QApplication
{
    static MainWindow* mainWindow;
    static int i;

public:
    TofPApplication(int& a1, char**& a2);
    static void setMainWindow(MainWindow* mainWindow);

    static MainWindow* getMainWindow();
};

#endif // TOFPAPPLICATION_H
