#ifndef TRANSPORTMANAGERFORM_H
#define TRANSPORTMANAGERFORM_H

#include <QWidget>

namespace Ui {
    class TransportManagerForm;
}

class TransportManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit TransportManagerForm(QWidget *parent = 0);
    ~TransportManagerForm();

private:
    Ui::TransportManagerForm *ui;
};

#endif // TRANSPORTMANAGERFORM_H
