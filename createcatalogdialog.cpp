#include "createcatalogdialog.h"
#include "ui_createcatalogdialog.h"
#include <QtSql>
#include <QtGui>

CreateCatalogDialog::CreateCatalogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCatalogDialog)
{
    ui->setupUi(this);
    fillProductsList();
}

CreateCatalogDialog::~CreateCatalogDialog()
{
    delete ui;
}

void CreateCatalogDialog::on_buttonBox_accepted()
{
    bool error = true;
    QSqlQuery query;
    error &= query.prepare("UPDATE `good` SET catalog_id = 1 WHERE goodid = ?");

    int row = ui->products->currentIndex().row();
    if (row >= 0)
    {
        int goodId = goodsModel->index(row, 0).data().toInt();
        query.addBindValue(goodId);
        error &= query.exec();
        qDebug() << query.lastQuery();
        if (!error)
        {
            QMessageBox::critical(this, "Error while adding product to Catalog.",
                query.lastError().text());
        }
        else
        {
            QMessageBox::information(this, "Add product",
                "Product was added to Catalog");
        }
    }
    else
    {
        QMessageBox::warning(this, "Add product",
            "Please, select product first");
    }
}

void CreateCatalogDialog::fillProductsList()
{
   QSqlRelationalTableModel* model = new QSqlRelationalTableModel();

   model->setTable("good");
   model->setFilter("catalog_id IS NULL");
   model->removeColumn(1);
   model->removeColumn(4);
   model->select();

   goodsModel = model;

   ui->products->setModel(model);
   ui->products->setColumnHidden(0, true);
}
