#include "loginform.h"
#include "ui_loginform.h"
#include "tofpapplication.h"
#include "mainwindow.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButton_clicked()
{
    TofPApplication::getMainWindow()->switchToWidget(MainWindow::USER);
}
