#ifndef TRANSPORTMANAGERFORM_H
#define TRANSPORTMANAGERFORM_H

#include <QWidget>
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

private:
    Ui::TransportManagerForm *ui;
};

#endif // TRANSPORTMANAGERFORM_H
