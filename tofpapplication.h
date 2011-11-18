#ifndef TOFPAPPLICATION_H
#define TOFPAPPLICATION_H

#include <QApplication>
#include "mainwindow.h"

class TofPApplication : public QApplication
{
    static MainWindow* mainWindow;
    static QString userLogin;

public:
    TofPApplication(int& a1, char**& a2);
    ~TofPApplication();
    static void setMainWindow(MainWindow*);
    static MainWindow* getMainWindow();
    static int exec();

    static void setUserLogin(QString);
    static QString getUserLogin();

private:
    static void connectToDB();
};

#endif // TOFPAPPLICATION_H
