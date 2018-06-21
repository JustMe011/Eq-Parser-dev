#ifndef WID_H
#define WID_H

#include <QWidget>
#include <tokenType.h>
#include <eqParser.h>

namespace Ui {
class wid;
}

class wid : public QWidget
{
    Q_OBJECT

public:
    explicit wid(QWidget *parent = 0);
    ~wid();

private:
    Ui::wid *ui;
    tokenType *token1;
    eqParser parser;

    void setTokenSample();
    void writeTokenSample();
protected slots:
    void on_getEqBtn_clicked();
    void on_getEqBtn_released();

};

#endif // WID_H
