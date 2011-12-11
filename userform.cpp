#include "userform.h"
#include "ui_userform.h"
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
        qDebug() << tableModel->index(selectedRow, 0).data().toString();
        QString label = "You are going to by " + name + " for " + price +
            "$. " + "Please, inser address to deliver:";
        qDebug() << QInputDialog::getText(this, "Order Product", label);
    }
    else
    {
    QMessageBox::warning(this, "Make Order", "Please, select product first");
    }
}
