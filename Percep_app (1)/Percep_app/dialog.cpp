#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::on_pushButtonDlg_clicked()
{
    pp1=ui->lineEdit->text().toInt();
    pp2=ui->lineEdit_2->text().toInt();
    DlgFunc(pp1,pp2);
    //z=11;

}

//void Dialog::DlgFunc(int pp1, int pp2)
//{
    //DlgFunc();
 //   z=11;
   // pp1=ui->lineEdit->text().toInt();
   // pp2=ui->lineEdit_2->text().toInt();
//}


Dialog::~Dialog()
{
    delete ui;
}
