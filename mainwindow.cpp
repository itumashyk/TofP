#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginform.h"
#include "userform.h"
#include "productmanagerform.h"
#include "transportmanagerform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainStackedWidget->addWidget(new LoginForm);
    ui->mainStackedWidget->addWidget(new UserForm);
    ui->mainStackedWidget->addWidget(new ProductManagerForm);
    ui->mainStackedWidget->addWidget(new TransportManagerForm);
}

MainWindow::~MainWindow()
{
    int widgetsCount = ui->mainStackedWidget->count();
    for (int i = 0; i < widgetsCount ; i++) {
        delete ui->mainStackedWidget->widget(i);
    }
    delete ui;
}

void MainWindow:: switchToWidget(Widgets widget)
{
    ui->mainStackedWidget->setCurrentIndex(widget);
}
