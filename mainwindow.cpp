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

    loginForm = new LoginForm;
    userForm = new UserForm;
    productsManagerForm = new ProductManagerForm;
    transportManagerForm = new TransportManagerForm;
    connect(loginForm, SIGNAL(user_have_logined()), userForm, SLOT(on_user_logined()));

    ui->mainStackedWidget->addWidget(loginForm);
    ui->mainStackedWidget->addWidget(userForm);
    ui->mainStackedWidget->addWidget(productsManagerForm);
    ui->mainStackedWidget->addWidget(transportManagerForm);
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
