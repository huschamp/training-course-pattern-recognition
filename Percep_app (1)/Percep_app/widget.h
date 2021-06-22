#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    int ff;
    double SS;
    double W0;
    double W[2]= { -100,100 };
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void take(int,int);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
