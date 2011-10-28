#ifndef PRODUCTMANAGERFORM_H
#define PRODUCTMANAGERFORM_H

#include <QWidget>

namespace Ui {
    class ProductManagerForm;
}

class ProductManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagerForm(QWidget *parent = 0);
    ~ProductManagerForm();

private:
    Ui::ProductManagerForm *ui;
};

#endif // PRODUCTMANAGERFORM_H
