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
    model->removeColumn(0);
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->setRelation(0,QSqlRelation("company", "companyid", "name"));

    model->setHeaderData(0, Qt::Horizontal, "Producer");
    model->setHeaderData(1, Qt::Horizontal, "Name");
    model->setHeaderData(2, Qt::Horizontal, "Price, $");
    model->setHeaderData(3, Qt::Horizontal, "Description");
    model->select();
    tableModel = model;
}

