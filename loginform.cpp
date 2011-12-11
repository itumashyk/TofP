#include "loginform.h"
#include "ui_loginform.h"
#include "tofpapplication.h"
#include "mainwindow.h"
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "mainwindow.h"
#include <stdexcept>
#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_loginButton_clicked()
{
    QSqlQueryModel model;
    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE login=?");
    QString login = ui->loginLineEdit->text();
    query.addBindValue(login);
    query.exec();
    model.setQuery(query);

    QString password = model.record(0).value("password").toString();
    Roles role = (Roles) model.record(0).value("role").toInt();
    if(password != "" && password == ui->passwordLineEdit->text())
    {
        TofPApplication::setUserLogin(login);
        showWidgetAccordingRole(role);
    }
    else
    {
        QMessageBox::critical(this, "Login", "Incorrect password");
    }
}

void LoginForm:: showWidgetAccordingRole(Roles role)
{
    switch(role)
    {
    case USER:
        TofPApplication::getMainWindow()->switchToWidget(MainWindow::USER);
        break;

    case GOODS_ADMIN:
        TofPApplication::getMainWindow()->switchToWidget(MainWindow::GOODS);
        break;

    case TRANSPORT_ADMIN:
        TofPApplication::getMainWindow()->switchToWidget(MainWindow::TRANSPORT);
        break;

    default:
        throw std:: invalid_argument("no such role");
    }
}
