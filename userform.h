#ifndef USERFORM_H
#define USERFORM_H

#include <QWidget>
#include "basewidget.h"
#include <QtSql>

namespace Ui {
    class UserForm;
}

class UserForm : public BaseWidget
{
    Q_OBJECT

public:

    enum ColumnProduct {
        Producer = 1,
        Name,
        Price,
        Description,
        Catalog
    };

    enum ColumnOrder{
        orderId,
        goodId,
        date,
        address
    };

    explicit UserForm(QWidget *parent = 0);
    ~UserForm();

private slots:
    void on_orderButton_clicked();

    void on_deleteButton_clicked();

public slots:
    void on_user_logined();

private:
    Ui::UserForm *ui;
    QAbstractItemModel* productsModel;
    QAbstractItemModel* ordersModel;

    void insertOrder(int id, QString addres);
    void createTableModels();
    void loadTables();
};

#endif // USERFORM_H
