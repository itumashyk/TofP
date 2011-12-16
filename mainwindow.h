#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum Widgets
    {
        LOGIN = 0,
        USER = 1,
        GOODS = 2,
        TRANSPORT = 3
    };

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void switchToWidget(Widgets widget);

private:
    Ui::MainWindow *ui;   

    QWidget* loginForm;
    QWidget* userForm;
    QWidget* transportManagerForm;
    QWidget* productsManagerForm;
};

#endif // MAINWINDOW_H
