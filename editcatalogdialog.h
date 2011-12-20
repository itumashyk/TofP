#ifndef EDITCATALOGDIALOG_H
#define EDITCATALOGDIALOG_H

#include <QtGui/QDialog>
#include <QtSql>

namespace Ui {
    class EditCatalogDialog;
}

class EditCatalogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCatalogDialog(QWidget *parent = 0);
    void setCatalogId(int id);
    ~EditCatalogDialog();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::EditCatalogDialog *ui;
    QSqlRelationalTableModel* productsModel;

    int catalogId;
};

#endif // EDITCATALOGDIALOG_H
