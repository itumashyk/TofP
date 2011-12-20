#include "transportmanagerform.h"
#include "ui_transportmanagerform.h"

#include <Utils.h>

TransportManagerForm::TransportManagerForm(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::TransportManagerForm)
{
    ui->setupUi(this);
    setLayout(ui->verticalLayout);
    createModel();
}

TransportManagerForm::~TransportManagerForm()
{
    delete ui;
}

void TransportManagerForm::createModel() {
    transportModel = Utils::getTransportModel();
    transportModel->select();

    ui->transportList->setModel(transportModel);
}

void TransportManagerForm::on_pushButton_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Add Transport", "Enter the name of Transport Company",
                                               QLineEdit::Normal, "", &ok);
    if (ok) {
        Utils::addNewTransport(name);
        transportModel->select();
    }
}

void TransportManagerForm::on_pushButton_2_clicked()
{
    int row = ui->transportList->currentIndex().row();
    if (row >= 0) {
        int transportId = transportModel->index(row, 0).data().toInt();
        Utils::deleteTransport(transportId);
        transportModel->select();
    } else {
        QMessageBox::warning(this, "Delete Transport",
            "Please, select transport first");
    }
}
