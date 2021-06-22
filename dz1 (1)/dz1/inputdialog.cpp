#include "inputdialog.h"
#include <QLabel>
#include <QGridLayout>

InputDialog::InputDialog(QWidget* pwgt/*= 0*/)
 : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
 m_ptxtFirstValue = new QLineEdit;
 m_ptxtLastValue = new QLineEdit;
 m_ptxtCount = new QLineEdit;
 plblFirstValue = new QLabel("&First value");
 plblLastValue = new QLabel("&Last value");
 plblCount = new QLabel("Count");
 plblFirstValue->setBuddy(m_ptxtFirstValue);
 plblLastValue->setBuddy(m_ptxtLastValue);
 plblCount->setBuddy(m_ptxtCount);
 pcmdOk = new QPushButton("&Ok");
 pcmdCancel = new QPushButton("&Cancel");
 connect(pcmdOk, SIGNAL(clicked()), this, SLOT(slotOk()));
 connect(pcmdCancel, SIGNAL(clicked()), this, SLOT(reject()));
 ptopLayout = new QGridLayout;
 ptopLayout->addWidget(plblFirstValue, 0, 0);
 ptopLayout->addWidget(plblLastValue, 1, 0);
 ptopLayout->addWidget(plblCount, 2, 0);
 ptopLayout->addWidget(m_ptxtFirstValue, 0, 1);
 ptopLayout->addWidget(m_ptxtLastValue, 1, 1);
 ptopLayout->addWidget(m_ptxtCount, 2, 1);
 ptopLayout->addWidget(pcmdOk, 3,0);
 ptopLayout->addWidget(pcmdCancel, 3, 1);
 setLayout(ptopLayout);
}

void InputDialog::createDialog1()
{
    //emit pushBtn(pInputDialog);
   // if (pInputDialog->exec() == QDialog::Accepted){}
this->show();
}

void InputDialog::slotOk()
{
    emit pushOk(this->count(), this->firstValue(), this->lastValue());
    accept();
}

double InputDialog::firstValue()
{
 return m_ptxtFirstValue->text().toDouble();
}

double InputDialog::lastValue()
{
 return m_ptxtLastValue->text().toDouble();
}

int InputDialog::count()
{
 return m_ptxtCount->text().toInt();
}
