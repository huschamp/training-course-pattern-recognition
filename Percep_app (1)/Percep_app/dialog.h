#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    //void DlgFunc();
    int pp1;
    int pp2;
    int z;
   // QPushButton pushButtonDlg;
    //QString mmm;
    ~Dialog();

public slots:
    void on_pushButtonDlg_clicked();

signals:
    void DlgFunc(int,int);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
