#include "mainwindow.h"
#include "tofpapplication.h"

int main(int argc, char *argv[])
{
    TofPApplication a(argc, argv);
    MainWindow w;
    w.show();
    TofPApplication::setMainWindow(& w);

    return a.exec();
}
