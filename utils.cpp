#include "utils.h"

Utils::Utils()
{

}

QSqlRelationalTableModel* Utils::getModel(QString table, QString filter) {
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel();

    model->setTable(table);

    qDebug() << "filter = " << filter;
    if (filter != "") {
        model->setFilter(filter);
    }

    return model;
}

QSqlRelationalTableModel* Utils::getCatalogsModel() {
    return Utils::getModel("catalog", "");
}

QSqlRelationalTableModel* Utils::getTransportModel() {
    return Utils::getModel("transport_company", "");
}

QSqlRelationalTableModel* Utils::getNonCatalogProducts() {
    return Utils::getModel("good", "catalog_id IS NULL");
}

QSqlRelationalTableModel* Utils::getProductsFromCatalog(int catalogId) {
    return Utils::getModel("good", "catalog_id=" + QString::number(catalogId));
//    return Utils::getModel("good", "catalog_id=7");
}

QSqlRelationalTableModel* Utils::getPublishedProducts() {
    return Utils::getModel("good", "catalog_id IS NOT NULL");
}

void Utils::addProductToCatalog(int catalogId, int goodId) {

    bool error = true;
    QSqlQuery query;
    error &= query.prepare("UPDATE `good` SET catalog_id = ? WHERE goodid = ?");
    query.addBindValue(catalogId);
    query.addBindValue(goodId);
    error &= query.exec();
    qDebug() << query.lastQuery();
    if (!error) {
            QMessageBox::critical(0, "Error while adding product to Catalog.",
                query.lastError().text());
    } else {
            QMessageBox::information(0, "Add product",
                "Product was added to Catalog");
    }
}

void Utils::deleteProductFromCatalog(int goodId) {

    bool error = true;
    QSqlQuery query;
    error &= query.prepare("UPDATE `good` SET catalog_id = NULL WHERE goodid = ?");
    qDebug() << goodId;
    query.addBindValue(goodId);
    qDebug() << query.lastQuery();
    error &= query.exec();
    if (!error) {
            QMessageBox::critical(0, "Error while deleting product to Catalog.",
                query.lastError().text());
    } else {
            QMessageBox::information(0, "Delete product",
                "Product was deleted from Catalog");
    }
}

void Utils::addNewCatalog(QString name) {
    bool error = true;
    QSqlQuery query;

    error &= query.prepare("INSERT INTO `catalog` (creation_date, name) VALUES (?, ?)");

    query.addBindValue(QDateTime::currentDateTime().toString(Qt::ISODate));
    query.addBindValue(name);

    qDebug() << query.lastQuery();
    error &= query.exec();
    if (!error) {
            QMessageBox::critical(0, "Error while adding new Catalog.",
                query.lastError().text());
    } else {
            QMessageBox::information(0, "New Catalog",
                "Catalog was created");
    }
}

void Utils::deleteCatalog(int id) {
    bool error = true;
    QSqlQuery query;
    error &= query.prepare("DELETE FROM `catalog` WHERE id = ?");
    query.addBindValue(id);
    qDebug() << query.lastQuery();
    error &= query.exec();
    if (!error) {
            QMessageBox::critical(0, "Error while deleting catalog.",
                query.lastError().text());
    } else {
            QMessageBox::information(0, "Delete catalog",
                "Catalog was deleted");
    }
}

void Utils::addNewTransport(QString transport) {
    bool error = true;
    QSqlQuery query;

    error &= query.prepare("INSERT INTO `transport_company` (name) VALUES (?)");

    query.addBindValue(transport);

    qDebug() << query.lastQuery();
    error &= query.exec();
    if (!error) {
            QMessageBox::critical(0, "Error while adding new Transport",
                query.lastError().text());
    } else {
            QMessageBox::information(0, "New Transport",
                "Transport was created");
    }
}

void Utils::deleteTransport(int id) {
    bool error = true;
    QSqlQuery query;
    error &= query.prepare("DELETE FROM `transport_company` WHERE transport_id = ?");
    query.addBindValue(id);
    qDebug() << query.lastQuery();
    error &= query.exec();
    if (!error) {
            QMessageBox::critical(0, "Error while deleting Transport.",
                query.lastError().text());
    } else {
            QMessageBox::information(0, "Delete transport",
                "Transport was deleted");
    }
}
