#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QtGui>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
  //  bool prefLessThan(const , const);
    ~MainWindow();


   // void error_input(double a,double b);


private slots:
   // void draw(int, double, double);


    void on_pushButton_clicked();

signals:

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
