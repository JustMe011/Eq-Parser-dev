#include "eqParser.h"
#include <QtAlgorithms>
#include <QString>
#include <iostream>

//void eqParser::getEquation (QString equation)
//{
//    this->eqString = equation;
//    wString = eqString;
//    eqInserted = true;
//    tokenize();
//}

/* START interface */



//void eqParser::solveEq (QString eqString)
//{
//   //QList<tokenType> * RPN = getRPN(equation);

//   /* algorithm to solve equation
//    * It as to return 2 arrays:
//    * xp,yp -> I think I can use an object to treat these
//    * for the domain look into tokenList List -> it has an another property which say the
//    * density point
//    */
//  reset();

//}
eqParser::eqParser()
{
    reset();
}

eqParser::~eqParser()
{
    std::cout << "Adios" << std::endl;
}


QString eqParser::cleanChars (QString str)
{
    QString outStr = QString();
    QStringList blank;
    blank.append("\n");
    blank.append(" ");
    blank.append("\t");
    QChar currentChar = QChar();

//    QChar* end = blank + sizeof(blank) / sizeof(blank[0]);
    for (int i=0; i < str.length(); ++i)
    {
        currentChar = str.at(i);
        //std::cout << "CurrentChar: " << currentChar.unicode() << std::endl;
        //QStringList::iterator pos = qFind(blank.begin(),blank.end(),currentChar);

        if (std::find(blank.begin(),blank.end(),currentChar) == blank.end())
            outStr.append(str.at(i));
    }
    return outStr;
}





void eqParser::printEquation(QString wString)
{
    std::cout << "eq: " << wString.toStdString() << std::endl;
}

void eqParser::reset()
{
    /* clean all data structures before compute a new parsing */

}
