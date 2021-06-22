//#ifndef DEMODIALOG_H
#define DEMODIALOG_H
#include "QDialog"
//#include "QWidget"


class DemoDialog : public QDialog {
    Q_OBJECT

public:
    DemoDialog( QWidget* parent = 0 );
    ~DemoDialog();

   // QString getInput() const;

signals:
    //void applied();

private:
   // QLineEdit* m_edit;
}
