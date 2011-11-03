#include "userform.h"
#include "ui_userform.h"

UserForm::UserForm(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::UserForm)
{
    ui->setupUi(this);
}

UserForm::~UserForm()
{
    delete ui;
}

