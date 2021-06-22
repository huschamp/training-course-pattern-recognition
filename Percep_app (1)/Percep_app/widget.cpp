#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    srand(time(NULL));

    int kolvo=ui->lineEdit->text().toInt();
    int ot =ui->lineEdit_2->text().toInt();
    int doo =ui->lineEdit_3->text().toInt();
    // double *mas=new double[kolvo][2];
    double **mas = new double*[kolvo];
    for (int count = 0; count < kolvo; count++)
    {
        mas[count] = new double[2];
    }
    for (int i = 0; i < kolvo; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            //massiv[i] = first + static_cast <double> (rand())( static_cast <double> (RAND_MAX/(last - first)));
            mas[i][j] = rand() % (doo - ot + 1) + ot;
            // std::cout<<massiv[i]<<std::endl;
        }
    }
    /*	for (int i = 0; i < kolvo; ++i) {  // Выводим на экран строку i
            for (int j = 0; j < 2; ++j)
                cout << mas[i][j] << " ";
            cout << endl; // Строка завершается символом перехода на новую строку
        }
    */
    /*  double *mas2=new double[kolvo];
    for (int i = 0; i < kolvo ; i++)
    {
    //massiv[i] = first + static_cast <double> (rand())( static_cast <double> (RAND_MAX/(last - first)));
    mas2[i] = rand() % (doo-ot+1) + ot;
    // std::cout<<massiv[i]<<std::endl;
    }
    */
    for (int i = 0; i < kolvo; i++)
    {
        for (int l = i + 1; l < kolvo; l++)
        {
            if (mas[i][0] > mas[l][0])
            {               //сравнение
                double *tmp = mas[i];        //перестановка
                mas[i] = mas[l];
                //cout << tmp[0] << " ";
                mas[l] = tmp;
                //cout << mas[l][0] << " ";
            }
        }
    }
/*	for (int i = 0; i < kolvo; ++i) {  // Выводим на экран строку i
        for (int j = 0; j < 2; ++j)
            cout << mas[i][j] << " ";
        cout << endl; // Строка завершается символом перехода на новую строку
    }
*/
    //int k = 1 + qrand() % 10;
    int k = 1 + rand() % 10;
  //  cout << "k:  " << k << " ";
    int b = rand() % 10;
  //  cout << b << " ";
    double **t = new double*[kolvo];
    for (int count = 0; count < kolvo; count++)
    {
        t[count] = new double[2];
    }
    for (int i = 0; i < kolvo; i++)
    {
        //for (int j=0; j<2;j++)
        //{
        t[i][0] = mas[i][0];
        t[i][1] = k*mas[i][0] + b;
        //}
    }
    /*	for (int i = 0; i < kolvo; ++i) {  // Выводим на экран строку i
            for (int j = 0; j < 2; ++j)
                cout << t[i][j] << " ";
            cout << endl; // Строка завершается символом перехода на новую строку
        }
    */
    int n1 = 0, n2 = 0;
    for (int i = 0; i < kolvo; i++)
    {
        if (mas[i][1] >= t[i][1])
        {
            n1++;
        }
        if (mas[i][1] < t[i][1])
        {
            n2++;
        }
    }
   // cout << n1 << " ";
   // cout << n2 << " ";
    double **cl1 = new double*[n1];
    for (int count = 0; count < n1; count++)
    {
        cl1[count] = new double[2];
    }
    double **cl2 = new double*[n2];
    for (int count = 0; count < n2; count++)
    {
        cl2[count] = new double[2];
    }
    int g1 = 0, g2 = 0;
    //int gg = 0;
    for (int i = 0; i < n1 + n2; i++)
    {
        if (mas[i][1] >= t[i][1])
        {
            //gg = i - g2;
            for (int j = 0; j < 2; j++)
            {
                cl1[i - g2][j] = mas[i][j];
            }
            //cout << "this_cl1: \n" << endl;
            //cout << cl1[i-g2][0] << " " << cl1[i-g2][1] << endl;
            g1++;
        }
        if (mas[i][1] < t[i][1])
        {
            for (int j = 0; j < 2; j++)
            {
                cl2[i - g1][j] = mas[i][j];
            }
            //cout << "this_cl2: \n" << endl;
            //cout << cl2[i - g1][0] << " " << cl2[i - g1][1] << endl;
            g2++;
        }
    }
    /*	for (int i = 0; i < n1; ++i) {  // Выводим на экран строку i
            for (int j = 0; j < 2; ++j)
                cout << cl1[i][j] << " ";
            cout << endl; // Строка завершается символом перехода на новую строку
        }
    */
    int N = n1 + n2;
    double **cl = new double*[N];
    for (int count = 0; count < N; count++)
    {
        cl[count] = new double[2];
    }
    for (int i = 0; i < n1; i++)
    {
        cl[i] = cl1[i];
    }
    for (int i = n1; i < n1 + n2; i++)
    {
        cl[i] = cl2[i - n1];
    }
     //   for (int i = 0; i < n1+n2; ++i) {  // Выводим на экран строку i
     //       for (int j = 0; j < 2; ++j)
           //     cout << cl[i][j] << " ";
           // cout << endl; // Строка завершается символом перехода на новую строку
    //    }

    W0 = 0.01;
    //W[2] = { -100,100 };
    double S0;
    double S;
    int f;
    double res;
    for (int z = 0; z < 10; z++)
    {
        for (int i = 0; i < n1 + n2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    S0 = W[j] * cl[i][j];
                }
                else
                {
                    S = S0 + W[j] * cl[i][j] + W0;
                }
            }
            if (S < 0)
            {
                f = 0;
            }
            if (S > 0)
            {
                f = 1;
            }
            res = 0;
            for (int j = 0; j < 2; j++)
            {
                res += W[j] * cl[i][j];
            }
                if (res > 0 && i > n1) //<
                {
                    // W=W;
                }
                if (f == 0 && i > n1) //<
                {
                    for (int j = 0; j < 2; j++)
                    {
                        double tmp;
                        tmp = W[j] + cl[i][j];
                        W[j] = tmp;
                    }
                    //W=W+cl[i];
                }
                if (res < 0 && i < n1)
                {
                    // W=W;
                }
                if (f == 1 && i < n1)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        double tmp;
                        tmp = W[j] - cl[i][j];//++++++
                        W[j] = tmp;
                    }
                    //W=W+cl[i];
                }
         /*   if (res < 0 && i > n1) //<
            {
                // W=W;
            }
            if (res >= 0 && i > n1) //<
            {
                for (int j = 0; j < 2; j++)
                {
                    double tmp;
                    tmp = W[j] + cl[i][j];
                    W[j] = tmp;
                }
                //W=W+cl[i];
            }
            if (res > 0 && i < n1)
            {
                // W=W;
            }
            if (res <= 0 && i < n1)
            {
                for (int j = 0; j < 2; j++)
                {
                    double tmp;
                    tmp = W[j] + cl[i][j];
                    W[j] = tmp;
                }
                //W=W+cl[i];
            }
            */
        }
    }
    ////////
    int tr[2] = { 20,2 };
    for (int j = 0; j < 2; j++)
    {
        if (j == 0)
        {
            S0 = W[j] * tr[j];
        }
        else
        {
            S = S0 + W[j] * tr[j] + W0;
        }
    }
    if (S < 0)
    {
        f = 0;
    }
    if (S > 0)
    {
        f = 1;
    }
 //   cout << "class: " << f << endl;


    //int A[n][m];
    //for (int i = 0; i < n1; ++i) {  // Выводим на экран строку i
    //	for (int j = 0; j < 2; ++j)
 //   cout << cl1[0][0] << " " << cl1[0][1] << " ";
  //  cout << W[0] << " " << W[1] << " ";
    //	cout << endl; // Строка завершается символом перехода на новую строку
    //}
    //
    //
    //
    //
   // double a = -1; //Начало интервала, где рисуем график по оси Ox
     //   double b =  1; //Конец интервала, где рисуем график по оси Ox
      //  double h = 0.01; //Шаг, с которым будем пробегать по оси Ox

        //int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать
        QVector<double> x(kolvo), y(kolvo); //Массивы координат точек

        //Вычисляем наши данные
       // int i=0;
        for (int i=0; i<kolvo;i++)//Пробегаем по всем точкам
        {
            x[i] = t[i][0];
            y[i] = t[i][1];//Формула нашей функции
            //i++;
        }

       // ui->widget->clearGraphs();//Если нужно, но очищаем все графики
        //Добавляем один график в widget
        ui->widget->addGraph();
        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        ui->widget->graph(0)->setData(x, y);

        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(ot, doo);//Для оси Ox

        //Для показа границ по оси Oy сложнее, так как надо по правильному
        //вычислить минимальное и максимальное значение в векторах
        double minY = mas[0][1], maxY = mas[0][1];
        for (int i=1; i<kolvo; i++)
        {
            if (mas[i][1]<minY) minY = mas[i][1];
            if (mas[i][1]>maxY) maxY = mas[i][1];
        }
        ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

        //И перерисуем график на нашем widget
        ui->widget->replot();



        //Рисуем точки

          //  int N=5; //Допустим, что у нас пять точек
            QVector<double> x1(n1), y1(n1); //Массивы координат точек

            //Зададим наши точки
            for (int i=0; i<n1;i++)//Пробегаем по всем точкам
            {
                x1[i] = cl1[i][0];
                y1[i] = cl1[i][1];//Формула нашей функции
                //i++;
            }

           // ui->widget->clearGraphs();//Если нужно, но очищаем все графики
            //Добавляем один график в widget
            ui->widget->addGraph();
            //Говорим, что отрисовать нужно график по нашим двум массивам x и y
            ui->widget->graph(1)->setData(x1, y1);

            ui->widget->graph(1)->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
            ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);//убираем линии
            //формируем вид точек
            ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));

            QVector<double> x2(n2), y2(n2); //Массивы координат точек

            //Зададим наши точки
            for (int i=0; i<n2;i++)//Пробегаем по всем точкам
            {
                x2[i] = cl2[i][0];
                y2[i] = cl2[i][1];//Формула нашей функции
                //i++;
            }

           // ui->widget->clearGraphs();//Если нужно, но очищаем все графики
            //Добавляем один график в widget
            ui->widget->addGraph();
            //Говорим, что отрисовать нужно график по нашим двум массивам x и y
            ui->widget->graph(2)->setData(x2, y2);

            ui->widget->graph(2)->setPen(QColor(255, 0, 0, 255));//задаем цвет точки
            ui->widget->graph(2)->setLineStyle(QCPGraph::lsNone);//убираем линии
            //формируем вид точек
            ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));

            //Подписываем оси Ox и Oy
          //  ui->widget->xAxis->setLabel("x");
           // ui->widget->yAxis->setLabel("y");

            //Установим область, которая будет показываться на графике
            //ui->widget->xAxis->setRange(-1, 5);//Для оси Ox
            //ui->widget->yAxis->setRange(-1, 3);//Для оси Oy

            //И перерисуем график на нашем widget
            ui->widget->replot();
            Dialog *dlg = new Dialog; //( this );
            dlg->show();
           //connect(this,SIGNAL))
            connect(dlg,SIGNAL(DlgFunc(int,int)), this, SLOT(take(int,int)));
           // connect(ui->pushButtonDialog, SIGNAL(clicked()), this, SLOT(DlgFunc()));
         //   if (dlg->z==11)
           // {
            //int p1=dlg->pp1;
            //int p2=dlg->pp2;



    /*
            bool bOk;
            bool ok;
            int p1 = QInputDialog::getInt(this, QString::fromUtf8("Введите процент"),
                                     QString::fromUtf8("Процент:"), -25, -1000, 1000, 1, &ok);

            int p2 = QInputDialog::getInt(this, QString::fromUtf8("Введите процент"),
                                     QString::fromUtf8("Процент:"), -25, -1000, 1000, 1, &bOk);
            int indx;

            //


            //for (int j = 0; j < 2; j++)
            //{
                SS=W[0]*p1+W[1]*p2+W0;
          //  }
            if (SS < 0)
            {
                ff = 0;
            }
            if (SS > 0)
            {
                ff = 1;
            }
            //

            if (ff==0)//(p2>t[indx][1])
            {
                QMessageBox* pmbx =
                                    new QMessageBox("MessageBox",
                                    "It is class 1",
                                    QMessageBox::Information,
                                    QMessageBox::Yes,
                                    QMessageBox::No,
                                    QMessageBox::Cancel | QMessageBox::Escape);
                int n = pmbx->exec();
                delete pmbx;
                if (n == QMessageBox::Yes)
                {
                  //Нажата кнопка Yes
                }
            }
            else if (ff==1)//(p2<t[indx][1])
            {
                QMessageBox* pmbxx1 =
                                    new QMessageBox("MessageBox2",
                                    "It is class 2",
                                    QMessageBox::Information,
                                    QMessageBox::Yes,
                                    QMessageBox::No,
                                    QMessageBox::Cancel | QMessageBox::Escape);
                int nn = pmbxx1->exec();
                delete pmbxx1;
                if (nn == QMessageBox::Yes)
                {
                  //Нажата кнопка Yes
                }
            }

            }
            */
}

void Widget::take(int p1,int p2)
{
    //if (dlg->z==11)
    //{
   // int p1=dlg->pp1;
    //int p2=dlg->pp2;



/*
    bool bOk;
    bool ok;
    int p1 = QInputDialog::getInt(this, QString::fromUtf8("Введите процент"),
                             QString::fromUtf8("Процент:"), -25, -1000, 1000, 1, &ok);

    int p2 = QInputDialog::getInt(this, QString::fromUtf8("Введите процент"),
                             QString::fromUtf8("Процент:"), -25, -1000, 1000, 1, &bOk);
    int indx;

    //
    */

    //for (int j = 0; j < 2; j++)
    //{
        SS=W[0]*p1+W[1]*p2+W0;
  //  }
    if (SS < 0)
    {
        ff = 0;
    }
    if (SS > 0)
    {
        ff = 1;
    }
    //

    if (ff==0)//(p2>t[indx][1])
    {
        QMessageBox* pmbx =
                            new QMessageBox("MessageBox",
                            "It is class 1",
                            QMessageBox::Information,
                            QMessageBox::Yes,
                            QMessageBox::No,
                            QMessageBox::Cancel | QMessageBox::Escape);
        int n = pmbx->exec();
        delete pmbx;
        if (n == QMessageBox::Yes)
        {
          //Нажата кнопка Yes
        }
    }
    else if (ff==1)//(p2<t[indx][1])
    {
        QMessageBox* pmbxx1 =
                            new QMessageBox("MessageBox2",
                            "It is class 2",
                            QMessageBox::Information,
                            QMessageBox::Yes,
                            QMessageBox::No,
                            QMessageBox::Cancel | QMessageBox::Escape);
        int nn = pmbxx1->exec();
        delete pmbxx1;
        if (nn == QMessageBox::Yes)
        {
          //Нажата кнопка Yes
        }
    }

   // }
}
