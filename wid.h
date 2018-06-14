#ifndef WID_H
#define WID_H

#include <QWidget>
#include <tokenType.h>

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
    tokenType *token1 = new tokenType;

    void setTokenSample();
    void writeTokenSample();

};

#endif // WID_H
