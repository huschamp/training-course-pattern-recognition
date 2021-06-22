#include "widget.h"
#include "ui_widget.h"
#include "QtGui"
#include "QFileDialog"
#include "QPixmap"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    int in=32;
    int jn=36;
    //QVector<QRgb> QImage::colorTable() const;
    QImage *img= new QImage;
    //img->load("/c1","BMP");
    QString filter = QString("Supported Files (*.shp *.kml *.jpg *.png *.bmp );;All files (*)");
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Select File(s)"), QDir::homePath(), filter);
    for(int idx =0; idx < fileNames.size(); ++idx)
    {
        //QImage image ;
        bool success = img->load(fileNames.at(idx));
        qDebug() << "File loaded succesfully " << success ;
        qDebug() << fileNames.at(idx);
    }
    img->save("C:/QTpr/geometry/sloy1.bmp");
    QImage img4;
    img4=*img;
    QImage img1;
    QImage img2;
    QImage img3;
    img1=*img;
    img2=*img;
    img3=*img;
    //QRgb pixelData = img2->pixel(i,j);
  //  for (int i=0; i<in;i++)
  //  {
   //     for (int j=0; j<jn; j++)
   //     {
   //         img4.setPixel(i,j,1);
            //img2->setPixel(i,j,qRgb(255,255,255));
   //     }
  //  }
    img4.scaled(256,256,Qt::IgnoreAspectRatio, Qt::FastTransformation);
    QGraphicsScene *scene = new QGraphicsScene(this);
    QPixmap *pmap=new QPixmap;
    pmap->convertFromImage(img4,Qt::AutoColor);
    QSize graphSize=ui->graphicsView->size();
    QPixmap scaled=pmap->scaled((graphSize),Qt::IgnoreAspectRatio, Qt::FastTransformation);
    QSize imageSize=pmap->size();
    imageSize.scale((graphSize),Qt::KeepAspectRatio);
    pmap->scaled((graphSize),Qt::KeepAspectRatio);
    //scene->addPixmap(pmap->fromImage(*img2));
    //scene->addPixmap(*pmap);
    scene->addPixmap(scaled);
        // scene->addPixmap(QPixmap::fromImage(img2));
         ui->graphicsView->setScene(scene);
    //img2->setPixel(5,5,4278190080);
    img4.save("C:/QTpr/geometry/ss.bmp", "BMP");
    QVector <QRgb> mas_color;
    mas_color=img->colorTable();
    //qDebug() << img->pixel(0,31);//massiv_color;
    double **mas = new double*[in];
    for (int count = 0; count < in; count++)
    {
        mas[count] = new double[jn];
    }
    double **sl1 = new double*[in];
    for (int count = 0; count < in; count++)
    {
        sl1[count] = new double[jn];
    }
    double **sl2 = new double*[in];
    for (int count = 0; count < in; count++)
    {
        sl2[count] = new double[jn];
    }
    double **sl3 = new double*[in];
    for (int count = 0; count < in; count++)
    {
        sl3[count] = new double[jn];
    }
    for (int i=0;i<in;i++)
    {
        for (int j=0;j<jn;j++)
        {
            sl2[i][j]=0;
        }
    }
    for (int i=0; i<in;i++)
    {
        for (int j=0; j<jn; j++)
        {
            qDebug() << img->pixel(i,j);
            if (img->pixel(i,j) ==4294967295)
            {
                mas[i][j]=0;
            }
            else
            {
                //qDebug() << "BIT";
                mas[i][j]=1;
            }
        }
    }

    for (int i=0; i<in;i++)
    {
        for (int j=0; j<jn; j++)
        {
            if (mas[i][j]==1)
            {
            if (i==0 && j==0)
            {
                if (mas[i+1][j]==mas[i][j+1] && mas[i+1][j]==mas[i+1][j+1])
                {
                    sl1[i][j]=0;
                }
                else
                {
                    sl1[i][j]=1;
                }
            }
            if (i==0 && j>0 && j<jn-1)
            {
                if (mas[i][j+1]==mas[i][j-1] && mas[i][j+1]==mas[i+1][j] && mas[i+1][j]==mas[i+1][j-1] && mas[i+1][j]==mas[i+1][j+1])
                {
                    sl1[i][j]=0;
                }
                else
                {
                    sl1[i][j]=1;
                }
            }
            if (i==0 && j==jn-1)
            {
                if (mas[i+1][j]==mas[i][j-1] && mas[i+1][j]==mas[i+1][j-1])
                {
                    sl1[i][j]=0;
                }
                else
                {
                    sl1[i][j]=1;
                }
            }
            if (i>0 && j==jn-1 && i<in-1)
            {
                if (mas[i-1][j]==mas[i-1][j-1] && mas[i][j-1]==mas[i-1][j] && mas[i][j-1]==mas[i+1][j-1] && mas[i][j-1]==mas[i+1][j])
                {
                    sl1[i][j]=0;
                }
                else
                {
                    sl1[i][j]=1;
                }
            }
            if (i==in-1 && j==jn-1)
            {
                if (mas[i-1][j]==mas[i][j-1] && mas[i-1][j]==mas[i-1][j-1])
                {
                    sl1[i][j]=0;
                }
                else
                {
                    sl1[i][j]=1;
                }
            }
            if (i==in-1 && j<jn-1 && j>0)
            {
                if (mas[i][j+1]==mas[i-1][j+1] && mas[i][j+1]==mas[i-1][j] && mas[i][j+1]==mas[i-1][j-1] && mas[i-1][j-1]==mas[i][j-1])
                {
                    sl1[i][j]=0;
                }
                else
                {
                    sl1[i][j]=1;
                }
            }
            if (i==in-1 && j==0)
            {
                if (mas[i-1][j]==mas[i][j+1] && mas[i-1][j]==mas[i-1][j+1])
                {
                    sl1[i][j]=0;
                }
                else
                {
                    sl1[i][j]=1;
                }
            }
            if (i>0 && j==0 && i<in-1)
            {
                if (mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j]==mas[i][j+1] && mas[i-1][j]==mas[i+1][j+1] && mas[i+1][j+1]==mas[i+1][j])
                {
                    sl1[i][j]=0;
                }
                else
                {
                    sl1[i][j]=1;
                }
            }
            if (i>0 && j>0 && i<in-1 && j<jn-1)
            {
                if (mas[i-1][j-1]==mas[i][j-1] && mas[i-1][j-1]==mas[i+1][j-1] && mas[i+1][j-1]==mas[i+1][j] && mas[i+1][j]==mas[i+1][j+1] && mas[i+1][j+1]==mas[i][j+1] && mas[i][j+1]==mas[i-1][j+1] && mas[i-1][j+1]==mas[i-1][j])
                {
                    sl1[i][j]=0;
                }
                else
                {
                    sl1[i][j]=1;
                }
            }
            }
        }
    }
    for (int i=0; i<in;i++)
    {
        for (int j=0; j<jn; j++)
        {
            if (sl1[i][j]==1)
            {
                img1.setPixel(i,j,1);
                //qDebug() << "BBBBBBBBBBBBBBBBAM";
            }
            else
            {
            img1.setPixel(i,j,0);
            }
            //img2->setPixel(i,j,qRgb(255,255,255));
        }
    }
    //img2->scaled(256,256,Qt::IgnoreAspectRatio, Qt::FastTransformation);
    QGraphicsScene *scene1 = new QGraphicsScene(this);
    QPixmap *pmap1=new QPixmap;
    pmap1->convertFromImage(img1,Qt::AutoColor);
    //QSize graphSize=ui->graphicsView->size();
    QPixmap scaled1=pmap1->scaled((graphSize),Qt::IgnoreAspectRatio, Qt::FastTransformation);
    //QSize imageSize=pmap->size();
    //imageSize.scale((graphSize),Qt::KeepAspectRatio);
    //pmap->scaled((graphSize),Qt::KeepAspectRatio);
    //scene->addPixmap(pmap->fromImage(*img2));
    //scene->addPixmap(*pmap);
    scene1->addPixmap(scaled1);
        // scene->addPixmap(QPixmap::fromImage(img2));
         ui->graphicsView_2->setScene(scene1);
  //  for (int i=0; i<32;i++)
   // {
   //     for (int j=0; j<32; j++)
   //     {
   //         qDebug() << sl1[i][j];
   //     }
   // }
         if (mas[0][0]==1)
         {
  // qDebug() << "mas is ok";
    }
             //sloy nomer 2
    /*for (int i=0; i<in;i++)
    {
        for (int j=0; j<jn; j++)
        {
            if (mas[i][j]==1)
            {
            if (i==0 && j==0)
            {
                if (mas[i][j]!=mas[i+1][j]){qDebug() << "mast be ok";
                    if (mas[i+1][j]==mas[i][j+1]){
                        if (mas[i+1][j]==mas[i+1][j+1])
                {
                    sl2[i][j]=1;
                  //  qDebug() << "mast be ok";
                } }}
                if (mas[i][j]!=mas[i+1][j] && mas[i+1][j]==mas[i][j+1] && mas[i+1][j]==mas[i+1][j+1])
                {
                    sl2[i][j]=1;
                  //  qDebug() << "mast be ok";
                }
                else
                {
                    sl2[i][j]=0;
                }
            }
            //qDebug() << j;
            if (i==0 && j>0 && j<jn-1)
            {
                 if (mas[i][j]!=mas[i][j-1] && mas[i+1][j-1]==mas[i][j-1] && mas[i][j-1]==mas[i+1][j])
                    {
                        sl2[i][j]=1;
                    }
                 else if (mas[i][j]!=mas[i][j+1] && mas[i][j+1]==mas[i+1][j+1] && mas[i][j+1]==mas[i+1][j])
                 {
                     sl2[i][j]=1;
                 }
                 else
                 {
                     sl2[i][j]=0;
                 }
            }
            if (i==in-1 && j==0)
            {
                if (mas[i][j]!=mas[i-1][j] && mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j+1]==mas[i][j+1])
                {
                    sl2[i][j]=1;
                }
                else
                {
                    sl2[i][j]=0;
                }
            }
            if (i==in-1 && j>0 && j<jn-1)
            {
                if (mas[i][j]!=mas[i][j-1] && mas[i][j-1]==mas[i-1][j-1] && mas[i][j-1]==mas[i-1][j])
                {
                    sl2[i][j]=1;
                }
                else if (mas[i][j]!=mas[i-1][j] && mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j+1]==mas[i][j+1])
                {
                    sl2[i][j]=1;
                }
                else
                {
                    sl2[i][j]=0;
                }
            }
            if (i==in-1 && j==jn-1)
            {
                if (mas[i][j]!=mas[i][j-1] && mas[i][j-1]==mas[i-1][j-1] && mas[i-1][j-1]==mas[i-1][j])
                {
                    sl2[i][j]=1;
                }
                else
                {
                    sl2[i][j]=0;
                }
            }
            if (j==jn-1 && i>0 && i<in-1)
            {
                if (mas[i][j]!=mas[i+1][j] && mas[i+1][j]==mas[i+1][j-1] && mas[i+1][j-1]==mas[i][j-1])
                {
                    sl2[i][j]=1;
                }
                else if (mas[i][j]!=mas[i][j-1] && mas[i][j-1]==mas[i-1][j-1] && mas[i-1][j-1]==mas[i-1][j])
                {
                    sl2[i][j]=1;
                }
                else
                {
                    sl2[i][j]=0;
                }
            }
            if (i==0 && j==jn-1)
            {
                if (mas[i][j]!=mas[i][j-1] && mas[i+1][j-1]==mas[i][j-1] && mas[i][j-1]==mas[i+1][j])
                {
                    sl2[i][j]=1;
                }
                else
                {
                    sl2[i][j]=0;
                }
            }
            if (j==0 && i>0 && i<in-1)
            {
                if (mas[i][j]!=mas[i-1][j] && mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j]==mas[i][j+1])
                   {
                       sl2[i][j]=1;
                   }
                else if (mas[i][j]!=mas[i+1][j] && mas[i+1][j]==mas[i+1][j+1] && mas[i+1][j+1]==mas[i][j+1])
                {
                    sl2[i][j]=1;
                }
                else
                {
                    sl2[i][j]=0;
                }
            }
            if (j>0 && j<jn-1 && i>0 && i<in-1)
            {
                if (mas[i][j]!=mas[i-1][j] && mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j]==mas[i][j+1])
                {
                    sl2[i][j]=1;
                }
                else if(mas[i][j]!=mas[i][j+1] && mas[i][j+1]==mas[i+1][j+1] && mas[i][j+1]==mas[i+1][j])
                {
                    sl2[i][j]=1;
                }
                else if(mas[i][j]!=mas[i+1][j] && mas[i+1][j]==mas[i+1][j-1] && mas[i+1][j]==mas[i][j-1])
                {
                    sl2[i][j]=1;
                }
                else if(mas[i][j]!=mas[i][j-1] && mas[i][j-1]==mas[i-1][j-1] && mas[i][j-1]==mas[i-1][j])
                {
                    sl2[i][j]=1;
                }
                else
                {
                    sl2[i][j]=0;
                }
            }
}
       }
    }*/

         for (int i=0; i<in;i++)
             {
                 for (int j=0; j<jn; j++)
                 {
                     if (mas[i][j]==0)
                     {
                     if (i==0 && j==0)
                     {
                         if (mas[i][j]!=mas[i+1][j]){qDebug() << "must be ok";
                             if (mas[i+1][j]==mas[i][j+1]){
                                 if (mas[i+1][j]==mas[i+1][j+1])
                         {

                             sl2[i+1][j]=1;
                             sl2[i][j+1]=1;
                             sl2[i+1][j+1]=1;
                           //  qDebug() << "mast be ok";
                         } }}
                         if (mas[i][j]!=mas[i+1][j] && mas[i+1][j]==mas[i][j+1] && mas[i+1][j]==mas[i+1][j+1])
                         {
                             sl2[i+1][j]=1;
                             sl2[i][j+1]=1;
                             sl2[i+1][j+1]=1;
                           //  qDebug() << "mast be ok";
                         }
                         else
                         {
                             //sl2[i+1][j]=0;
                             //sl2[i][j+1]=0;
                             //sl2[i+1][j+1]=0;
                         }
                     }
                     //qDebug() << j;
                     if (i==0 && j>0 && j<jn-1)
                     {
                          if (mas[i][j]!=mas[i][j-1] && mas[i+1][j-1]==mas[i][j-1] && mas[i][j-1]==mas[i+1][j])
                             {
                              sl2[i][j-1]=1;
                              sl2[i+1][j-1]=1;
                              sl2[i+1][j]=1;
                             }
                          else if (mas[i][j]!=mas[i][j+1] && mas[i][j+1]==mas[i+1][j+1] && mas[i][j+1]==mas[i+1][j])
                          {
                              sl2[i][j+1]=1;
                              sl2[i+1][j+1]=1;
                              sl2[i+1][j]=1;
                          }
                          else
                          {
                              //sl2[i][j+1]=0;
                              //sl2[i+1][j+1]=0;
                              //sl2[i+1][j]=0;
                              //sl2[i][j-1]=0;
                              //sl2[i+1][j-1]=0;
                              //sl2[i+1][j]=0;
                          }
                     }
                     if (i==in-1 && j==0)
                     {
                         if (mas[i][j]!=mas[i-1][j] && mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j+1]==mas[i][j+1])
                         {
                             sl2[i-1][j]=1;
                             sl2[i-1][j+1]=1;
                             sl2[i][j+1]=1;
                         }
                         else
                         {
                             //sl2[i-1][j]=0;
                             //sl2[i-1][j+1]=0;
                             //sl2[i][j+1]=0;
                         }
                     }
                     if (i==in-1 && j>0 && j<jn-1)
                     {
                         if (mas[i][j]!=mas[i][j-1] && mas[i][j-1]==mas[i-1][j-1] && mas[i][j-1]==mas[i-1][j])
                         {
                             sl2[i][j-1]=1;
                             sl2[i-1][j-1]=1;
                             sl2[i-1][j]=1;
                         }
                         if (mas[i][j]!=mas[i-1][j] && mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j+1]==mas[i][j+1])
                         {
                             sl2[i-1][j]=1;
                             sl2[i-1][j+1]=1;
                             sl2[i][j+1]=1;
                         }
                         else
                         {
                             //sl2[i][j-1]=0;
                             //sl2[i-1][j-1]=0;
                             //sl2[i-1][j]=0;
                             //sl2[i-1][j]=0;
                             //sl2[i-1][j+1]=0;
                             //sl2[i][j+1]=0;
                         }
                     }
                     if (i==in-1 && j==jn-1)
                     {
                         if (mas[i][j]!=mas[i][j-1] && mas[i][j-1]==mas[i-1][j-1] && mas[i-1][j-1]==mas[i-1][j])
                         {
                             sl2[i][j-1]=1;
                             sl2[i-1][j-1]=1;
                             sl2[i-1][j]=1;
                         }
                         else
                         {
                            // sl2[i][j-1]=0;
                            // sl2[i-1][j-1]=0;
                            // sl2[i-1][j]=0;
                         }
                     }
                     if (j==jn-1 && i>0 && i<in-1)
                     {
                         if (mas[i][j]!=mas[i+1][j] && mas[i+1][j]==mas[i+1][j-1] && mas[i+1][j-1]==mas[i][j-1])
                         {
                             sl2[i+1][j]=1;
                             sl2[i+1][j-1]=1;
                             sl2[i][j-1]=1;
                         }
                         else if (mas[i][j]!=mas[i][j-1] && mas[i][j-1]==mas[i-1][j-1] && mas[i-1][j-1]==mas[i-1][j])
                         {
                             sl2[i][j-1]=1;
                             sl2[i-1][j-1]=1;
                             sl2[i-1][j]=1;
                         }
                         else
                         {
                           //  sl2[i+1][j]=0;
                            // sl2[i+1][j-1]=0;
                            // sl2[i][j-1]=0;
                            // sl2[i][j-1]=0;
                            // sl2[i-1][j-1]=0;
                            // sl2[i-1][j]=0;
                         }
                     }
                     if (i==0 && j==jn-1)
                     {
                         if (mas[i][j]!=mas[i][j-1] && mas[i+1][j-1]==mas[i][j-1] && mas[i][j-1]==mas[i+1][j])
                         {
                             sl2[i][j-1]=1;
                             sl2[i+1][j-1]=1;
                             sl2[i+1][j]=1;
                         }
                         else
                         {
                             //sl2[i][j-1]=0;
                            // sl2[i+1][j-1]=0;
                            // sl2[i+1][j]=0;
                         }
                     }
                     if (j==0 && i>0 && i<in-1)
                     {
                         if (mas[i][j]!=mas[i-1][j] && mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j]==mas[i][j+1])
                            {
                             sl2[i-1][j]=1;
                             sl2[i-1][j+1]=1;
                             sl2[i][j+1]=1;
                            }
                         else if (mas[i][j]!=mas[i+1][j] && mas[i+1][j]==mas[i+1][j+1] && mas[i+1][j+1]==mas[i][j+1])
                         {
                             sl2[i+1][j]=1;
                             sl2[i+1][j+1]=1;
                             sl2[i][j+1]=1;
                         }
                         else
                         {
                             //sl2[i-1][j]=0;
                             //sl2[i-1][j+1]=0;
                            // sl2[i][j+1]=0;
                            // sl2[i+1][j]=0;
                             //sl2[i+1][j+1]=0;
                             //sl2[i][j+1]=0;
                         }
                     }
                     if (j>0 && j<jn-1 && i>0 && i<in-1)
                     {
                         int z=0;
                         if (mas[i][j]!=mas[i-1][j] && mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j]==mas[i][j+1])
                         {
                             sl2[i-1][j]=1;
                             sl2[i-1][j+1]=1;
                             sl2[i][j+1]=1;
                             z=1;
                         }
                         if(mas[i][j]!=mas[i][j+1] && mas[i][j+1]==mas[i+1][j+1] && mas[i][j+1]==mas[i+1][j])
                         {
                             sl2[i][j+1]=1;
                             sl2[i+1][j+1]=1;
                             sl2[i+1][j]=1;
                             z=1;
                         }
                         if(mas[i][j]!=mas[i+1][j] && mas[i+1][j]==mas[i+1][j-1] && mas[i+1][j]==mas[i][j-1])
                         {
                             sl2[i+1][j]=1;
                             sl2[i+1][j-1]=1;
                             sl2[i][j-1]=1;
                             z=1;
                         }
                         if(mas[i][j]!=mas[i][j-1] && mas[i][j-1]==mas[i-1][j-1] && mas[i][j-1]==mas[i-1][j])
                         {
                             sl2[i][j-1]=1;
                             sl2[i-1][j-1]=1;
                             sl2[i-1][j]=1;
                             z=1;
                         }
                         if (z==0)
                         {
                             //sl2[i-1][j]=0;
                             //sl2[i-1][j+1]=0;
                             //sl2[i][j+1]=0;
                             //sl2[i][j+1]=0;
                             //sl2[i+1][j+1]=0;
                             //sl2[i+1][j]=0;
                             //sl2[i+1][j]=0;
                             //sl2[i+1][j-1]=0;
                             //sl2[i][j-1]=0;
                             //sl2[i][j-1]=0;
                             //sl2[i-1][j-1]=0;
                             //sl2[i-1][j]=0;
                         }
                     }
         }
                }
             }

    for (int i=0; i<in;i++)
    {
        for (int j=0; j<jn; j++)
        {
            if (sl2[i][j]==1)
            {
                img2.setPixel(i,j,1);
               // qDebug() << "BBBBBBBBBBBBBBBBAM";
            }
            else
            {
            img2.setPixel(i,j,0);
            }
            //img2->setPixel(i,j,qRgb(255,255,255));
        }
    }
    //img2->scaled(256,256,Qt::IgnoreAspectRatio, Qt::FastTransformation);
    QGraphicsScene *scene2 = new QGraphicsScene(this);
    QPixmap *pmap2=new QPixmap;
    pmap2->convertFromImage(img2,Qt::AutoColor);
    //QSize graphSize=ui->graphicsView->size();
    QPixmap scaled2=pmap2->scaled((graphSize),Qt::IgnoreAspectRatio, Qt::FastTransformation);
    //QSize imageSize=pmap->size();
    //imageSize.scale((graphSize),Qt::KeepAspectRatio);
    //pmap->scaled((graphSize),Qt::KeepAspectRatio);
    //scene->addPixmap(pmap->fromImage(*img2));
    //scene->addPixmap(*pmap);
    scene2->addPixmap(scaled2);
        // scene->addPixmap(QPixmap::fromImage(img2));
         ui->graphicsView_3->setScene(scene2);
    // esli chto problema vo 2 sloe
// q
    //sloy nomer 3
    for (int i=0; i<in;i++)
    {
        for (int j=0; j<jn-1; j++)
        {
            if (i==0 && j==0)
            {
                if (mas[i+1][j]==mas[i][j+1] && mas[i+1][j]==mas[i+1][j+1] && mas[i][j]==1 && mas[i+1][j]==0)
                {
                    sl3[i][j]=1-mas[i][j];
                }
                else
                {
                    sl3[i][j]=mas[i][j];
                }
            }
            if (i==0 && j>0 && j<jn-1)
            {
                if (mas[i][j+1]==mas[i][j-1] && mas[i][j+1]==mas[i+1][j] && mas[i+1][j]==mas[i+1][j-1] && mas[i+1][j]==mas[i+1][j+1] && mas[i][j]==1 && mas[i][j+1]==0)
                {
                    sl3[i][j]=1-mas[i][j];;
                }
                else
                {
                    sl3[i][j]=mas[i][j];
                }
            }
            if (i==0 && j==jn-1)
            {
                if (mas[i+1][j]==mas[i][j-1] && mas[i+1][j]==mas[i+1][j-1] && mas[i][j]==1 && mas[i+1][j]==0)
                {
                    sl3[i][j]=1-mas[i][j];
                }
                else
                {
                    sl3[i][j]=mas[i][j];
                }
            }
            if (i>0 && j==jn-1 && i<in-1)
            {
                if (mas[i-1][j]==mas[i-1][j-1] && mas[i][j-1]==mas[i-1][j] && mas[i][j-1]==mas[i+1][j-1] && mas[i][j-1]==mas[i+1][j] && mas[i][j]==1 && mas[i-1][j]==0)
                {
                    sl3[i][j]=1-mas[i][j];
                }
                else
                {
                    sl3[i][j]=mas[i][j];
                }
            }
            if (i==in-1 && j==jn-1)
            {
                if (mas[i-1][j]==mas[i][j-1] && mas[i-1][j]==mas[i-1][j-1] && mas[i][j]==1 && mas[i-1][j]==0)
                {
                    sl3[i][j]=1-mas[i][j];
                }
                else
                {
                    sl3[i][j]=mas[i][j];
                }
            }
            if (i==in-1 && j<jn-1 && j>0)
            {
                if (mas[i][j+1]==mas[i-1][j+1] && mas[i][j+1]==mas[i-1][j] && mas[i][j+1]==mas[i-1][j-1] && mas[i-1][j-1]==mas[i][j-1] && mas[i][j]==1 && mas[i][j+1]==0)
                {
                    sl3[i][j]=1-mas[i][j];
                }
                else
                {
                    sl3[i][j]=mas[i][j];
                }
            }
            if (i==jn-1 && j==0)
            {
                if (mas[i-1][j]==mas[i][j+1] && mas[i-1][j]==mas[i-1][j+1] && mas[i][j]==1 && mas[i-1][j]==0)
                {
                    sl3[i][j]=1-mas[i][j];
                }
                else
                {
                    sl3[i][j]=mas[i][j];
                }
            }
            if (i>0 && j==0 && i<in-1)
            {
                if (mas[i-1][j]==mas[i-1][j+1] && mas[i-1][j]==mas[i][j+1] && mas[i-1][j]==mas[i+1][j+1] && mas[i+1][j+1]==mas[i+1][j] && mas[i][j]==1 && mas[i-1][j]==0)
                {
                    sl3[i][j]=1-mas[i][j];
                }
                else
                {
                    sl3[i][j]=mas[i][j];
                }
            }
            if (i>0 && j>0 && i<in-1 && j<jn-1)
            {
                if (mas[i-1][j-1]==mas[i][j-1] && mas[i-1][j-1]==mas[i+1][j-1] && mas[i+1][j-1]==mas[i+1][j] && mas[i+1][j]==mas[i+1][j+1] && mas[i+1][j+1]==mas[i][j+1] && mas[i][j+1]==mas[i-1][j+1] && mas[i-1][j+1]==mas[i-1][j] && mas[i-1][j]!=mas[i][j])//mas[i-1][j]==0 && mas[i][j]==1)// && mas[i][j]==1)// && mas[i-1][j-1]==0)
                {
                    sl3[i][j]=1-mas[i][j];
                }
                else
                {
                    sl3[i][j]=mas[i][j];
                }
            }
        }
    }
    for (int i=0; i<in;i++)
    {
        for (int j=0; j<jn; j++)
        {
            if (sl3[i][j]==1)
            {
                img3.setPixel(i,j,1);
               // qDebug() << "BBBBBBBBBBBBBBBBAM";
            }
            else
            {
            img3.setPixel(i,j,0);
            }
            //img2->setPixel(i,j,qRgb(255,255,255));
        }
    }
    //img2->scaled(256,256,Qt::IgnoreAspectRatio, Qt::FastTransformation);
    QGraphicsScene *scene3 = new QGraphicsScene(this);
    QPixmap *pmap3=new QPixmap;
    pmap3->convertFromImage(img3,Qt::AutoColor);
    //QSize graphSize=ui->graphicsView->size();
    QPixmap scaled3=pmap3->scaled((graphSize),Qt::IgnoreAspectRatio, Qt::FastTransformation);
    //QSize imageSize=pmap->size();
    //imageSize.scale((graphSize),Qt::KeepAspectRatio);
    //pmap->scaled((graphSize),Qt::KeepAspectRatio);
    //scene->addPixmap(pmap->fromImage(*img2));
    //scene->addPixmap(*pmap);
    scene3->addPixmap(scaled3);
        // scene->addPixmap(QPixmap::fromImage(img2));
         ui->graphicsView_4->setScene(scene3);

    //QString toStr = QString::number(massiv_color.length());
    //ui->label->setText(toStr);
img1.save("C:/QTpr/geometry/sloy2.bmp", "BMP");
img2.save("C:/QTpr/geometry/sloy3.bmp", "BMP");
img3.save("C:/QTpr/geometry/sloy4.bmp", "BMP");

}

Widget::~Widget()
{
    delete ui;
}
