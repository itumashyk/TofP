#include "editcatalogdialog.h"
#include "ui_editcatalogdialog.h"

#include <Utils.h>

EditCatalogDialog::EditCatalogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCatalogDialog)
{
    ui->setupUi(this);
    setWindowTitle("Adding Products to catalog");
    setLayout(ui->verticalLayout);
    productsModel = Utils::getNonCatalogProducts();
    productsModel->removeColumn(1);
    productsModel->removeColumn(4);
    productsModel->select();
    ui->products->setModel(productsModel);

    ui->products->setColumnHidden(0, true);
}

void EditCatalogDialog::setCatalogId(int id) {
    catalogId = id;
}

EditCatalogDialog::~EditCatalogDialog()
{
    delete ui;
}

void EditCatalogDialog::on_pushButton_clicked()
{

}

void EditCatalogDialog::on_buttonBox_accepted()
{
    int row = ui->products->currentIndex().row();
    if (row >= 0) {
        int goodId = productsModel->index(row, 0).data().toInt();
        Utils::addProductToCatalog(catalogId, goodId);
        productsModel->select();
    } else {
        QMessageBox::warning(this, "Add product",
            "Please, select product first");
    }
}
