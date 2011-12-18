#include "userform.h"
#include "ui_userform.h"
#include <tofpapplication.h>
#include <QtSql>
#include <QtGui>

UserForm::UserForm(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::UserForm)
{
    ui->setupUi(this);
}

UserForm::~UserForm()
{
    delete productsModel;
    delete ordersModel;
    delete ui;
}

void UserForm:: createTableModels()
{
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel();
    model->setTable("good");
    model->setRelation(Producer, QSqlRelation("company", "companyid", "name"));

    model->setHeaderData(Producer, Qt::Horizontal, "Producer");
    model->setHeaderData(Name, Qt::Horizontal, "Name");
    model->setHeaderData(Price, Qt::Horizontal, "Price, $");
    model->setHeaderData(Description, Qt::Horizontal, "Description");
    model->setFilter("catalog_id IS NOT NULL");
    model->removeColumn(5);
    model->select();
    productsModel = model;

    model = new QSqlRelationalTableModel();
    model->setTable("`order`");
    model->setRelation(goodId, QSqlRelation("good", "goodid", "name"));
    model->setFilter("user_login='" + TofPApplication::getUserLogin() + "'");
    model->select();   

    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->removeColumn(3);
    model->removeColumn(2);
    model->setHeaderData(orderId, Qt::Horizontal, "Order #");
    model->setHeaderData(goodId, Qt::Horizontal, "Product");
    model->setHeaderData(date, Qt::Horizontal, "Date");
    model->setHeaderData(address, Qt::Horizontal, "Address to deliver");
    ordersModel = model;
}


void UserForm::on_orderButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    if (selectedRow >= 0)
    {
        QString name = productsModel->index(selectedRow, Name).data().toString();
        QString price = productsModel->index(selectedRow,Price).data().toString();
        int id = productsModel->index(selectedRow, 0).data().toInt();

        QString label = "You are going to by " + name + " for " + price +
            "$. " + "Please, inser address to deliver:";
        QString adress = QInputDialog::getText(this, "Order Product", label);
        insertOrder(id, adress);
    }
    else
    {
        QMessageBox::warning(this, "Make Order",
            "Please, select product first");
    }
}


void UserForm::insertOrder(int id, QString address)
{
    bool error = true;
    QSqlQuery query;
    error &= query.prepare("SELECT company_companyid FROM good WHERE goodid=?");
    query.addBindValue(id);
    query.exec();
    error &= query.next();
    int companyid = query.value(0).toInt();

    QSqlQuery insertQuery;
    error &= insertQuery.prepare(
        "INSERT INTO `order` "\
        "(catalog_goodid, catalog_company_companyid, user_login, date, address)"\
        "VALUES (?, ?, ?, ?, ?)");

    insertQuery.addBindValue(id);
    insertQuery.addBindValue(companyid);
    insertQuery.addBindValue(TofPApplication::getUserLogin());
    insertQuery.addBindValue(QDateTime::currentDateTime().toString(Qt::ISODate));
    insertQuery.addBindValue(address);
    error &= insertQuery.exec();
    dynamic_cast<QSqlRelationalTableModel*>(ordersModel)->select();
    if (!error)
    {
        QMessageBox::critical(this, "Error while saving to DB.",
            insertQuery.lastError().text());
    }
    else
    {
        QMessageBox::information(this, "Create order",
            "Order was sucsessfully created");
    }
}

void UserForm::  loadTables()
{
    createTableModels();
    QTableView* productsView = ui->tableView;
    productsView->setModel(productsModel);
    productsView->setColumnHidden(0, true);

    QTableView* ordersView = ui->tableViewOrders;
    ordersView->setModel(ordersModel);
}

void UserForm:: on_user_logined()
{
    loadTables();
}

void UserForm:: on_deleteButton_clicked()
{
    int selectedRow = ui->tableViewOrders->currentIndex().row();
    if (selectedRow >= 0)
    {

        int id = ordersModel->index(selectedRow, 0).data().toInt();
        QMessageBox::StandardButton button =
            QMessageBox::question(this, "Delete order", "Delete this order?");
        if (button == QMessageBox::Ok)
        {
            QSqlQuery query;
            qDebug()<<query.prepare("DELETE FROM `order` WHERE orderid = ?") << id;
            query.addBindValue(id);
            qDebug()<<query.exec();
            dynamic_cast<QSqlRelationalTableModel*>(ordersModel)->select();
        }
    }
    else
    {
        QMessageBox::warning(this, "Make Order",
            "Please, select product first");
    }
}
