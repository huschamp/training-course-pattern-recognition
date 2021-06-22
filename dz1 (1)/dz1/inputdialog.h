#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>

class InputDialog : public QDialog
{
    Q_OBJECT
private:
 QLineEdit* m_ptxtFirstValue;
 QLineEdit* m_ptxtLastValue;
 QLineEdit* m_ptxtCount;
 QLabel* plblFirstValue;
 QLabel* plblLastValue;
 QLabel* plblCount;
 QPushButton* pcmdOk;
 QPushButton* pcmdCancel;
 QGridLayout* ptopLayout;

signals:
 void pushOk(int, double, double);

private slots:
 void slotOk();
 void createDialog1();

public:
 InputDialog(QWidget* pwgt = 0);
 double firstValue();
 double lastValue ();
 int count();
};

#endif // INPUTDIALOG_H
