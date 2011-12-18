#ifndef CREATECATALOGDIALOG_H
#define CREATECATALOGDIALOG_H

#include <QtGui/QDialog>
#include <QtSql>

namespace Ui {
    class CreateCatalogDialog;
}

class CreateCatalogDialog : public QDialog
{
    Q_OBJECT

public:

    explicit CreateCatalogDialog(QWidget *parent = 0);
    ~CreateCatalogDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CreateCatalogDialog *ui;

    QSqlTableModel* goodsModel;
    void fillProductsList();
};

#endif // CREATECATALOGDIALOG_H
