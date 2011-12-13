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

    enum Column {
        Producer = 1,
        Name,
        Price,
        Description
    };

    explicit UserForm(QWidget *parent = 0);
    ~UserForm();

private slots:
    void on_orderButton_clicked();

private:
    Ui::UserForm *ui;
    QAbstractItemModel* tableModel;
    void insertOrder(int id, QString addres);
    void createTableModel();
};

#endif // USERFORM_H
