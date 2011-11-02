#include "tofpapplication.h"
#include <QSqlDatabase>
#include <fstream>
#include <Qfile>
#include <QMessageBox>
#include <QTextStream>
#include <cstdlib>
#include <QSqlError>

TofPApplication:: TofPApplication(int &a1, char **&a2) :
    QApplication(a1, a2){}

TofPApplication:: ~TofPApplication()
{
}

void TofPApplication:: setMainWindow(MainWindow* mainWindow)
{
    TofPApplication:: mainWindow = mainWindow;
}

MainWindow* TofPApplication:: getMainWindow()
{
    return mainWindow;
}

int TofPApplication::exec()
{
    connectToDB();
    MainWindow w;
    w.show();
    TofPApplication::setMainWindow(&w);
    return QApplication::exec();
}

void TofPApplication:: connectToDB()
{
    QFile config ("config.ini");
    if (!config.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(NULL, "Error", "Couldn't find configuration file");
        std::exit(1);
    }

    QTextStream configStream(&config);
    QString host = configStream.readLine();
    QString userName = configStream.readLine();
    QString password = configStream.readLine();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(host);
    db.setDatabaseName("top");
    db.setUserName(userName);
    db.setPassword(password);
    bool ok = db.open();
    if (!ok) {
        QMessageBox::critical(NULL, "Error", "Couldn't connect to DB." \
                              " Reason: " + db.lastError().text());
        std::exit(1);
    }
}

MainWindow* TofPApplication::mainWindow = NULL;
