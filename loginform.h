#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include "basewidget.h"
#include "roles.h"

namespace Ui {
    class LoginForm;
}

class LoginForm : public BaseWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();

signals:
    void user_have_logined();

private:
    void showWidgetAccordingRole(Roles role);

private slots:

    void on_loginButton_clicked();



private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
