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
    ~TofPApplication();
    static void setMainWindow(MainWindow* mainWindow);
    static MainWindow* getMainWindow();
    static int exec();

private:
    static void connectToDB();
};

#endif // TOFPAPPLICATION_H
