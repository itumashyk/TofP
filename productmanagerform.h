#ifndef PRODUCTMANAGERFORM_H
#define PRODUCTMANAGERFORM_H

#include <QWidget>
#include "basewidget.h"
#include <QtSql>

namespace Ui {
    class ProductManagerForm;
}

class ProductManagerForm : public BaseWidget
{
    Q_OBJECT

public:

    enum ColumnCatalog {
        Id = 0,
        Name,
        CreationDate
    };

    explicit ProductManagerForm(QWidget *parent = 0);
    ~ProductManagerForm();

private slots:
    void on_createCatalog_clicked();
    void onUpdateModel();

    void on_pushButton_clicked();

private:
    Ui::ProductManagerForm *ui;

    QSqlTableModel* goodsModel;

    void createModels();
};

#endif // PRODUCTMANAGERFORM_H
