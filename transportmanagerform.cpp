#include "transportmanagerform.h"
#include "ui_transportmanagerform.h"

TransportManagerForm::TransportManagerForm(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::TransportManagerForm)
{
    ui->setupUi(this);
}

TransportManagerForm::~TransportManagerForm()
{
    delete ui;
}

