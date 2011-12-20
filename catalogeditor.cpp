#include "catalogeditor.h"
#include "ui_catalogeditor.h"

#include <editcatalogdialog.h>

CatalogEditor::CatalogEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CatalogEditor)
{
    ui->setupUi(this);
    setLayout(ui->verticalLayout);
}

CatalogEditor::CatalogEditor(int aCatalogId, QString name, QWidget *aParent) :
    QDialog(aParent),
    ui(new Ui::CatalogEditor)
{
    ui->setupUi(this);
    catalogId = aCatalogId;
    setLayout(ui->verticalLayout);
    setWindowTitle("Edit '" + name + "' catalog");
    fillProductsList();
}

CatalogEditor::~CatalogEditor()
{
    delete ui;
}

void CatalogEditor::fillProductsList()
{
   productsModel = Utils::getProductsFromCatalog(catalogId);
   productsModel->removeColumn(1);
   productsModel->removeColumn(4);
   productsModel->select();

   ui->products->setModel(productsModel);
   ui->products->setColumnHidden(0, true);
}

void CatalogEditor::on_pushButton_clicked()
{
    EditCatalogDialog dialog(this);
    dialog.setCatalogId(catalogId);
    dialog.exec();
    productsModel->select();
}

void CatalogEditor::on_pushButton_2_clicked()
{
    int row = ui->products->currentIndex().row();
    if (row >= 0) {
        int goodId = productsModel->index(row, 0).data().toInt();
        Utils::deleteProductFromCatalog(goodId);
        productsModel->select();
    } else {
        QMessageBox::warning(this, "Delete product",
            "Please, select product first");
    }
}
