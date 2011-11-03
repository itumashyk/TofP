#include "productmanagerform.h"
#include "ui_productmanagerform.h"

ProductManagerForm::ProductManagerForm(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::ProductManagerForm)
{
    ui->setupUi(this);
}

ProductManagerForm::~ProductManagerForm()
{
    delete ui;
}
