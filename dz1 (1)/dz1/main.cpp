#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
  //  InputDialog * pInputDialog = new InputDialog;
  //  QObject::connect(pInputDialog, SIGNAL(pushOk(int,double,double)), &w, SLOT(draw(int,double,double)));
  //  QObject::connect(&w, SIGNAL(pushBtn()), pInputDialog , SLOT(createDialog1()));


    return a.exec();
}
