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
    explicit UserForm(QWidget *parent = 0);
    ~UserForm();

private:
    Ui::UserForm *ui;
    QAbstractItemModel* tableModel;

    void createTableModel();
};

#endif // USERFORM_H
