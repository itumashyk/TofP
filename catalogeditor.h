#ifndef CATALOGEDITOR_H
#define CATALOGEDITOR_H

#include <QtGui/QDialog>
#include <QtSql>
#include <Utils.h>

namespace Ui {
    class CatalogEditor;
}

class CatalogEditor : public QDialog
{
    Q_OBJECT

public:

    explicit CatalogEditor(int catalogId, QString name, QWidget *parent = 0);
    explicit CatalogEditor(QWidget *parent = 0);
    ~CatalogEditor();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CatalogEditor *ui;
    QSqlRelationalTableModel* productsModel;

    void fillProductsList();
    int catalogId;
};

#endif // CATALOGEDITOR_H
