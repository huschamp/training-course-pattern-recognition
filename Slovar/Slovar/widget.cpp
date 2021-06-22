#include "widget.h"
#include "QFile"
#include "QtGui"
#include "ui_widget.h"

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

    QFile file("C:/QTpr/Slovar/slovar.txt");
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        ui->textBrowser->setText(file.readAll());
        file.close();
    }
    QString r,t,ti,tcopy;
    int s,c=0;
    r=ui->lineEdit->text();
    t=ui->textBrowser->toPlainText();

    tcopy=t;
    qDebug() << t;
    int s1,s1id=0;
    s=t.indexOf('\n');
    qDebug() <<"s: " << s;
    int *ind =new int[t.count('\n')+1];
    int *oc =new int[t.count('\n')+1];
    QVector<int> ocV(0);
 /*   int **gr = new int*[r.length()];
    for (int count = 0; count < r.length(); count++)
    {
        gr[count] = new int[s];
    }
*/
    //qDebug() <<"r: " << r[4];
    //for (int i=0;i<s;i++)//t.length();i++)
    //{
    int id=0;
    while (s1id!=2)
    {
       /* if ((i!=0) && (t[i]=="\n"))
        {
            int **gr = new int*[r.length()];
            for (int count = 0; count < i; count++)
            {
                gr[count] = new int[2];
            }
        }
        */
        if (s1id==1)
        {
            ti=t;
            s=ti.length();
        }
        int **gr = new int*[r.length()];
        for (int count = 0; count < r.length(); count++)
        {
            gr[count] = new int[s];
        }
        //for (int y=0; y<s;y++)
        //{
        //    ti[y]=t[y]
        //}
        if (s1id==0)
        {
        ti=t.mid(c,s);
        qDebug() << ti;
        t=t.remove(c,s+1);
        qDebug() << t;
        }
        else
        {
            ti=t;
            s=ti.length();
        }
        for (int i=0; i<r.length();i++)
        {
            for (int j=0; j<s;j++)
            {
        //qDebug()<<"BBBFSFWEF";
                if (r[i]==ti[j])
                {
                    //qDebug()<<"If1";
                    gr[i][j]=0;
                }
                else
                {
                    //qDebug()<<"If2";
                    gr[i][j]=1;
                }
            }
        }
        ind[id]=s;
      //  id=id+1;
        s1=s;
      //  s=t.indexOf('\n');
      //  qDebug() << "sNew: "<<s;
      //    s=-1;

  //  }
qDebug() << "Dosel do B";
    int **B = new int*[r.length()+1];
    for (int count = 0; count < r.length()+1; count++)
    {
        B[count] = new int[s1+1];
    }
    for (int j=0; j<r.length()+1;j++)
    {
        for (int k=0; k<s1+1;k++)
        {
            if (j==0)
            {
                B[j][k]=0;
            }
            if (k==0)
            {
                B[j][k]=0;
            }
            if (j!=0 && k!=0)
            {


               if (B[j-1][k]<B[j][k-1])
                                {
                                    B[j][k]=B[j-1][k]+gr[j-1][k-1];
                                }
               else if (B[j-1][k]==B[j][k-1])
               {
                   B[j][k]=B[j-1][k-1]+gr[j-1][k-1];
               }
                                else
                                {
                                    B[j][k]=B[j][k-1]+gr[j-1][k-1];
                                }

            }

        }
    }
    oc[id]=B[r.length()][s1];
    id=id+1;
    s1=s;
    s=t.indexOf('\n');
    if (s==-1)
    {
        s1id=s1id+1;
    }
    delete gr,B;
    //qDebug() << "sNew: "<<s;
      //s=-1;
}
    int m=1000;
    for (int i=0;i<id;i++)
    {
        if (oc[i]<m)
        {
            m=oc[i];
        }
        //ocV.push_back(oc[i]);
        qDebug() << "Sovpadenie: " << oc[i];
    }
    qDebug() <<"m "<<m;
    for (int i=0;i<id;i++)
    {
        if (oc[i]==m)
        {
            ocV.append(i);
        }
    }
    QString text;
    qDebug() << "ocV " <<ocV;
    for (int i=0;i<ocV.length();i++)
    {
        t=tcopy;
        for (int j=0;j<ocV[i];j++)
        {
            t.remove(0,t.indexOf('\n')+1);

        }
        qDebug() << t;
        if (i==0)
        {
            text=t.left(t.indexOf('\n'));
        }
        else
        {
            text=text.append(t.left(t.indexOf('\n')));
        }
        qDebug() << text;
        text=text.append('\n');
    }
    ui->textBrowser_2->setText(text);
    //qDebug() << r;
  //  for (int j=0; j<r.length()+1;j++)
   // {
    //    for (int k=0; k<s1+1;k++)
     //   {
      //      qDebug() << B[j][k];
       // }
    //}

}
