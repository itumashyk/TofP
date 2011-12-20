#include "productmanagerform.h"
#include "ui_productmanagerform.h"
#include <QtSql>
#include <QtGui>
#include <Utils.h>
#include <catalogeditor.h>

ProductManagerForm::ProductManagerForm(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::ProductManagerForm)
{
    ui->setupUi(this);
    setLayout(ui->gridLayout);
    createModels();
    ui->tableView->setModel(catalogsModel);
//    ui->tableView->setColumnHidden(0, true);
}

ProductManagerForm::~ProductManagerForm()
{
    delete ui;
}

void ProductManagerForm::createModels()
{
    catalogsModel = Utils::getCatalogsModel();
    catalogsModel->select();
}

void ProductManagerForm::on_createCatalog_clicked()
{
//    CreateCatalogDialog * dialog = new CreateCatalogDialog(this);
//    dialog->exec();
//    onUpdateModel();
}

void ProductManagerForm::onUpdateModel()
{
    catalogsModel->select();
}

void ProductManagerForm::on_pushButton_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row >= 0) {
        int goodId = catalogsModel->index(row, 0).data().toInt();
        Utils::deleteProductFromCatalog(goodId);
        onUpdateModel();
    } else {
        QMessageBox::warning(this, "Add product",
            "Please, select product first");
    }
}

void ProductManagerForm::on_pushButton_2_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "New Catalog", "Enter the name of new Catalog",
                                           QLineEdit::Normal, "", &ok);
    if (ok) {
        Utils::addNewCatalog(name);
    }
    onUpdateModel();

}

void ProductManagerForm::on_pushButton_4_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row >= 0) {
        int id = catalogsModel->index(row, 0).data().toInt();
        Utils::deleteCatalog(id);
        onUpdateModel();
    } else {
        QMessageBox::warning(this, "Delete catalog",
            "Please, select catalog first");
    }
}

void ProductManagerForm::on_pushButton_3_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row >= 0) {
        int catalogId = catalogsModel->index(row, 0).data().toInt();
        QString name = catalogsModel->index(row, 2).data().toString();
        qDebug() << "catalogId = " << catalogId;
        CatalogEditor dialog(catalogId, name, this);
        dialog.exec();
    } else {
        QMessageBox::warning(this, "Edit catalog",
            "Please, select catalog first");
    }

}
