#include "tofpapplication.h"

TofPApplication:: TofPApplication(int &a1, char **&a2) :
    QApplication(a1, a2) {}

void TofPApplication:: setMainWindow(MainWindow* mainWindow)
{
    TofPApplication:: mainWindow = mainWindow;
}

MainWindow* TofPApplication:: getMainWindow()
{
    return mainWindow;
}

MainWindow* TofPApplication::mainWindow = NULL;
