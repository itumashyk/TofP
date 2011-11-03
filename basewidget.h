#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>

namespace Ui {
    class BaseWidget;
}

/*
 Base class for all widgets in MainWindow
 */
class BaseWidget : public QWidget
{
    Q_OBJECT
public:
    BaseWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);

signals:

public slots:

};

#endif // BASEWIDGET_H
