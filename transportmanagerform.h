#ifndef TRANSPORTMANAGERFORM_H
#define TRANSPORTMANAGERFORM_H

#include <QWidget>
#include <QtSql>
#include "basewidget.h"

namespace Ui {
    class TransportManagerForm;
}

class TransportManagerForm : public BaseWidget
{
    Q_OBJECT

public:
    explicit TransportManagerForm(QWidget *parent = 0);
    ~TransportManagerForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TransportManagerForm *ui;

    QSqlRelationalTableModel* transportModel;
    void createModel();
};

#endif // TRANSPORTMANAGERFORM_H
