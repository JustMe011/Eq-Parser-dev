#include "wid.h"
#include "ui_wid.h"
#include <iostream>

wid::wid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wid)
{
    ui->setupUi(this);
    //setTokenSample();


}

wid::~wid()
{
    delete ui;
}


void wid::on_getEqBtn_clicked()
{

    QString eq;
    eq = ui->insertedTxt->text();
    parser.reset();

    //ui->getEqBtn->setDisabled(true);

    std::cout << "str: " << eq.toStdString() << std::endl;
}

void wid::on_getEqBtn_released()
{
    //ui->getEqBtn->setDisabled(false);
}
