#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include "stdlib.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*    QCPBars * bars = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
    //bars->setData(x, y);
    int h;
    h=2;
    bars->setWidth(h);
    //ui->widget->addGraph();
    ui->widget->addPlottable(bars);
    QPen pen;
        pen.setWidthF(1.5);//Толщина контура столбца
        bars->setName(QString::fromUtf8("Гистограмма")); // Легенда
        pen.setColor(QColor(50, 50, 100));// Цвет контура столбца
        bars->setPen(pen);
        // Цвет самого столбца, четвертый параметр - прозрачность
        bars->setBrush(QColor(50, 50, 250, 70));
        //
        QVector<double> ticks;
            QVector<QString> labels;
            ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
            labels << "1" << "2" << "3" << "4" << "5" << "6" << "7";
            ui->widget->xAxis->setAutoTicks(false);
            ui->widget->xAxis->setAutoTickLabels(false);
            ui->widget->xAxis->setTickVector(ticks);
            ui->widget->xAxis->setTickVectorLabels(labels);
            ui->widget->xAxis->setSubTickCount(0);
            ui->widget->xAxis->setTickLength(0, 4);
            ui->widget->xAxis->grid()->setVisible(true);
            ui->widget->xAxis->setRange(0, 8);

            ui->widget->yAxis->setRange(0, 12.1);
                ui->widget->yAxis->setPadding(5);
                ui->widget->yAxis->setLabel(QString::fromUtf8("Значения элементов"));
                ui->widget->yAxis->grid()->setSubGridVisible(true);
                QPen gridPen;
                gridPen.setStyle(Qt::SolidLine);
                gridPen.setColor(QColor(0, 0, 0, 25));
                ui->widget->yAxis->grid()->setPen(gridPen);
                gridPen.setStyle(Qt::DotLine);
                ui->widget->yAxis->grid()->setSubGridPen(gridPen);

                QVector<double> fossilData;
                    qsrand (time(NULL));
                    fossilData  << qrand() % 10 + 2.5
                                << qrand() % 10 + 2.5
                                << qrand() % 10 + 2.5
                                << qrand() % 10 + 2.5
                                << qrand() % 10 + 2.5
                                << qrand() % 10 + 2.5
                                << qrand() % 10 + 2.5;
                    bars->setData(ticks, fossilData);

    ui->widget->replot();
   // btn = new QPushButton("&Интервал", this);
  //  connect(btn, SIGNAL(clicked()), this, SLOT(createDialog()));
  */
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    srand(time(NULL));

    int kolvo=ui->lineEdit->text().toInt();
    int ot=ui->spinBox->value();
    int doo=ui->spinBox_2->value();
    double *mas=new double[kolvo];
    for (int i = 0; i < kolvo ; i++)
    {
       //massiv[i] = first + static_cast <double> (rand())( static_cast <double> (RAND_MAX/(last - first)));
        mas[i] = rand() % (doo-ot+1);
       // std::cout<<massiv[i]<<std::endl;
    }
    //double sv=rand() % (doo-ot+1) + ot;
    QCPBars * bars = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
    //bars->setData(x, y);
    double h;
    h=0.5;
    h=1;
    bars->setWidth(h);
    //ui->widget->addGraph();
    ui->widget->addPlottable(bars);
    QPen pen;
        pen.setWidthF(1.5);//Толщина контура столбца
        bars->setName(QString::fromUtf8("Гистограмма")); // Легенда
        pen.setColor(QColor(50, 50, 100));// Цвет контура столбца
        bars->setPen(pen);
        // Цвет самого столбца, четвертый параметр - прозрачность
        bars->setBrush(QColor(50, 50, 250, 70));
        //
        QVector<double> ticks(0);
            QVector<QString> labels;
            int numticks=log2(kolvo);
            numticks=numticks+1;
            for (int i=0;i<=numticks;i++)
            {
            ticks.append(i);
            }
            //double sh=(doo-ot)/numticks;
            //ticks << 1 << 2 << 3 << 4;// << 5 << 6 << 7;
            //labels << "1" << "2" << "3" << "4" << "5" << "6" << "7";
           // ui->widget->xAxis->setAutoTicks(false);
           // ui->widget->xAxis->setAutoTickLabels(false);
           // ui->widget->xAxis->setTickVector(ticks);
           // ui->widget->xAxis->setTickVectorLabels(labels);
         //   ui->widget->xAxis->setSubTickCount(0);
         //   ui->widget->xAxis->setTickLength(0, 4);
            ui->widget->xAxis->grid()->setVisible(true);
            ui->widget->xAxis->setRange(ot-2, doo+2);
           // ui->widget->xAxis->setRange(0, numticks);

            ui->widget->yAxis->setRange(0, kolvo/2); //25
            //    ui->widget->yAxis->setPadding(5);
                ui->widget->yAxis->setLabel(QString::fromUtf8("Количество элементов"));
                ui->widget->yAxis->grid()->setSubGridVisible(true);
                QPen gridPen;
                gridPen.setStyle(Qt::SolidLine);
                gridPen.setColor(QColor(0, 0, 0, 25));
                ui->widget->yAxis->grid()->setPen(gridPen);
                gridPen.setStyle(Qt::DotLine);
                ui->widget->yAxis->grid()->setSubGridPen(gridPen);

                //QVector<double> fossilData;
                 //   qsrand (time(NULL));
                 //   fossilData  << qrand() % 10 + 2.5
                  //              << qrand() % 10 + 2.5
                  //              << qrand() % 10 + 2.5
                  //              << qrand() % 10 + 2.5
                  //              << qrand() % 10 + 2.5
                  //              << qrand() % 10 + 2.5
                  //              << qrand() % 10 + 2.5;
                    //bars->setData(ticks, fossilData);
                    QVector<double> y(0);
                    for (int i=0;i<kolvo;i++)
                    {
                    //y.append((double)rand()/(doo));
                        y.append(((qrand() % ((doo-ot+1)*100)) + ot)/100.0);//doo+ot);//+1);
                    }
                    QString toStr = QString::number(y[1]);

                    ui->label_5->setText(toStr);
                //    ui->widget->yAxis->setTickVector(y);
                   QVector<double> t(0);
                    double g;
                    g=(double(doo)-double(ot))/double(numticks);
                   /* for (int i=0;i<kolvo;i++)
                    {
                       qDebug() << y[i];
                    }*/
                    //g=(double(max(y))-double(min(y)))/double(numticks);
                    h=g;
                    QString toStr1 = QString::number(g,'g',3);

                    ui->label_6->setText(toStr1);
                    bars->setWidth(h);
                    //gvvv
                    for (int i=0;i<=numticks;i++)
                    {
                    //ticks[i]=ot+g*(i+1);
                        ticks[i]=ot+g*(i);
                    }
                    ticks.append(doo);
                    //bbb
                    //qSort(y);
                    QVector<double> v(0);
                  /*  for (int j=1;j<=ticks.length();j++) //j=1;<=
                    {
                    for (int i=0;i<kolvo;i++)
                    {
                        if (j!=ticks.length())
                        {
                        if (y[i]=ot+g*j && y[i]>=ot+g*(j-1))
                        {
                            t.append(y[i]);
                        }
                        }
                        else
                        {
                            if (y[i]<=ot+g*j && y[i]>=ot+g*(j-1))
                            {
                                t.append(y[i]);
                            }
                        }


                    //t.append(i);
                    }
                    v.append(t.length());
                    t.clear();
                    }
                    */
                    for (int i=0;i<=ticks.length();i++)
                    {
                        for (int j=0; j<kolvo; j++)
                        {
                            /*if (y[j]<=ticks[i])
                            {
                                t.append(y[j]);
                            }*/
                            if (i!=ticks.length())
                            {
                                if (y[j]>=ot+g*i && y[j]<ot+g*(i+1))
                                {
                                    t.append(y[j]);
                                }
                            }
                            else
                            {
                                if (y[j]>=ot+g*i && y[j]<=ot+g*(i+1)+1)
                                {
                                    t.append(y[j]);
                                }
                            }
                        }
                       // t.remove();
                        v.append(t.length());
                       // for (int k=t.length(); k>0;k--)
                       // {
                       //   t.remove(k);
                       // }
                       t.clear();
                    }
                    for (int i=0; i<v.length(); i++)
                    {
                        v[i]=v[i];//kolvo;
                    }
                    QString toStr2 = QString::number(v.length());

                    ui->label_7->setText(toStr2);
                    QVector<double> vn(0);
                  //  vn.append(v[0]);
                    vn=v;
                    //for (int i=1; i<v.length(); i++)
                    //{
                    //    vn.append(vn[i-1]+v[i]);
                    //}


                  // std::vector<double> stdvect = y.toStdVector();
                   // for(int i=0; i < stdvect.size(); i++)
                   // std::cout << stdvect.at(i) << ' ';
                    for (int i=0;i<=numticks;i++)
                    {
                       qDebug() << ticks[i];
                    }
                    bars->setData(ticks,v);
                    //bars->setData(y,ticks);
                    //(double)rand()/(RAND_MAX)
                    //for (int i=0; i<ticks.length(); i++)
                   // {
                   //     for
                   // }
                   /* int k,l;
                    double nu,g;
                   // double h;
                    nu=0.0; g=0; l=0; k=sqrt(kolvo); h=(doo-ot)/k;

                    QVector<double> x(k), y(k);
                    double max=0.0;
                    for (double i=ot; i<=doo-h; i=i+h)
                    {
                        for (int j=0; j<kolvo; j++)
                        {
                            if (mas[j]>i && mas[j]<=i+h)
                            {
                             //std::cout<<massiv<<std::endl;
                             g=g+1;
                            }
                        }
                        nu=g/(kolvo*h);
                        g=0;
                        x[l]=(i+(i+h))/2;
                        y[l]=nu;
                        if (y[l]>max) {max=y[l];}
                        l++;
                        nu=0;
                    }
                    bars->setData(x,y);
                    */
                    QFile file("out.txt");
                         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                             return;

                         QTextStream out(&file);
                         for (int i=0; i<kolvo; i++)
                         {
                         out << y[i] << "\n";
                   }

    ui->widget->replot();
    ui->widget->removePlottable(bars);
}


