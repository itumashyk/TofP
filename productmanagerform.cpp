#include "productmanagerform.h"
#include "ui_productmanagerform.h"
#include "createcatalogdialog.h"
#include <QtSql>
#include <QtGui>

ProductManagerForm::ProductManagerForm(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::ProductManagerForm)
{
    ui->setupUi(this);
    createModels();
    ui->tableView->setModel(goodsModel);
    ui->tableView->setColumnHidden(0, true);
}

ProductManagerForm::~ProductManagerForm()
{
    delete ui;
}

void ProductManagerForm::createModels()
{
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel();

   model->setTable("good");
   model->setFilter("catalog_id = 1");
   model->removeColumn(1);
   model->removeColumn(4);

   model->select();
    goodsModel = model;

}

void ProductManagerForm::on_createCatalog_clicked()
{
    CreateCatalogDialog * dialog = new CreateCatalogDialog(this);
    dialog->exec();
    onUpdateModel();
}

void ProductManagerForm::onUpdateModel()
{
    goodsModel->select();
}

void ProductManagerForm::on_pushButton_clicked()
{
    bool error = true;
    QSqlQuery query;
    error &= query.prepare("UPDATE `good` SET catalog_id = NULL WHERE goodid = ?");

    int row = ui->tableView->currentIndex().row();
    if (row >= 0)
    {
        int goodId = goodsModel->index(row, 0).data().toInt();
        qDebug() << goodId;
        query.addBindValue(goodId);
        qDebug() << query.lastQuery();
        error &= query.exec();
        if (!error)
        {
            QMessageBox::critical(this, "Error while adding product to Catalog.",
                query.lastError().text());
        }
        else
        {
            QMessageBox::information(this, "Delete product",
                "Product was deleted from Catalog");
            onUpdateModel();
        }
    }
    else
    {
        QMessageBox::warning(this, "Add product",
            "Please, select product first");
    }
}
