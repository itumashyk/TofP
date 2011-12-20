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

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ProductManagerForm *ui;

    QSqlRelationalTableModel* catalogsModel;

    void createModels();
};

#endif // PRODUCTMANAGERFORM_H
