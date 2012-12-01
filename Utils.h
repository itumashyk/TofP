#ifndef UTILS_H
#define UTILS_H

#include <QtSql>
#include <QtGui>
#include <QtCore>

class Utils
{
public:
    Utils();
    static QSqlRelationalTableModel* getNonCatalogProducts();
    static QSqlRelationalTableModel* getProductsFromCatalog(int catalogId);
    static QSqlRelationalTableModel* getCatalogsModel();
    static QSqlRelationalTableModel* getTransportModel();
    static QSqlRelationalTableModel* getPublishedProducts();
    static QSqlRelationalTableModel* getModel(QString table, QString filter);

    static void addProductToCatalog(int catalogId, int goodId);
    static void deleteProductFromCatalog(int goodId);
    static void addNewCatalog(QString name);
    static void addNewTransport(QString transport);
    static void deleteCatalog(int id);
    static void deleteTransport(int id);
};

#endif // UTILS_H
