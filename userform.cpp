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
    createTableModel();
    QTableView* tableView = ui->tableView;
    tableView->setItemDelegate(new QSqlRelationalDelegate(tableView));
    tableView->setModel(tableModel);
    tableView->setColumnHidden(0, true);
}

UserForm::~UserForm()
{
    delete tableModel;
    delete ui;
}

void UserForm:: createTableModel()
{
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel();
    model->setTable("good");
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->setRelation(Producer, QSqlRelation("company", "companyid", "name"));

    model->setHeaderData(Producer, Qt::Horizontal, "Producer");
    model->setHeaderData(Name, Qt::Horizontal, "Name");
    model->setHeaderData(Price, Qt::Horizontal, "Price, $");
    model->setHeaderData(Description, Qt::Horizontal, "Description");
    model->select();
    tableModel = model;
}


void UserForm::on_orderButton_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    if (selectedRow >= 0)
    {
        QString name = tableModel->index(selectedRow, 2).data().toString();
        QString price = tableModel->index(selectedRow, 3).data().toString();
        int id = tableModel->index(selectedRow, 0).data().toInt();

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
