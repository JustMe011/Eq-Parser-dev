#include "wid.h"
#include "ui_wid.h"
#include <tokenType.h>

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


void wid::setTokenSample()
{
   // tokenType::tokenTypes types = tokenType::OTHER;
    //tokenType::associativityType ass = NON_ASSOCIATIVE;

    QString test = "A";
    token1->str(test);
    token1->type(tokenType::OTHER);
    token1->associativity(tokenType::NON_ASSOCIATIVE);

    writeTokenSample();
}

void wid::writeTokenSample()
{

    std::cout << "token str " << token1->getStr().toStdString() << std::endl;
    std::cout << "token type " << token1->getType() << std::endl;
    std::cout << "token ass " << token1->getAssociativity() << std::endl;


}

void wid::on_getEqBtn_clicked()
{

    QString eq;
    eq = ui->insertedTxt->text();
    //parser = new eqParser();
    //parser->getRPN(eq);
    //parser->showRPN(eq);
    parser.showRPN(eq);
    //ui->getEqBtn->setDisabled(true);

    std::cout << "str: " << eq.toStdString() << std::endl;
}

void wid::on_getEqBtn_released()
{
    //ui->getEqBtn->setDisabled(false);
}
