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

    QString test = "ciao";
    token1->setTokenCode(0);
    token1->setTokenStr(test);
    token1->setTokenType(tokenType::OTHER);
    token1->setTokenAssociativity(tokenType::NON_ASSOCIATIVE);

    writeTokenSample();
}

void wid::writeTokenSample()
{

    std::cout << "token code " << token1->getTokenCode() << std::endl;
    std::cout << "token str " << token1->getTokenStr().toStdString() << std::endl;
    std::cout << "token type " << token1->getTokenType() << std::endl;
    std::cout << "token ass " << token1->getTokenAssociativity() << std::endl;


}

void wid::on_getEqBtn_pressed()
{
    QString eq;
    eq = ui->insertedTxt->text();
    //parser = new eqParser();
    parser->getRPN(eq);

    std::cout << "str: " << eq.toStdString() << std::endl;
}
