#include "eqParser.h"
#include <QtAlgorithms>

//void eqParser::getEquation (QString equation)
//{
//    this->eqString = equation;
//    wString = eqString;
//    eqInserted = true;
//    tokenize();
//}

/* START interface */



void eqParser::solveEq (QString equation)
{
   QList<tokenType> * RPN = getRPN(equation);

   /* algorithm to solve equation
    * It as to return 2 arrays:
    * xp,yp -> I think I can use an object to treat these
    * for the domain look into tokenList List -> it has an another property which say the
    * density point
    */

}

QList<tokenType> * eqParser::getRPN (QString equation)
{
    eqString = equation;
    wString = eqString;
    eqInserted = true;
    tokenize();

    /* algorithm to generate RPN */

}

/* END interface */


void eqParser::tokenize ()
{
    /* clean the inserted string in order to have only equation tokens
     * [x] remove blank spaces
     * [x] remove strange chars
     * [x] put all letters uppercase
     *
     */
    std::cout << "wString: " << wString.toStdString() << std::endl;
    QString tmpString = wString;
    wString = cleanChars(tmpString);

    std::cout << "toupper\nwString: " << wString.toStdString() << std::endl;
    tmpString = wString;
    wString = toUpper(tmpString);
    std::cout << "wString: " << wString.toStdString() << std::endl;

    /* to the next steps */
    printEquation();
}

QString eqParser::cleanChars (QString str)
{
    QString outStr = QString();
    QStringList blank;
    blank.append("\n");
    blank.append(" ");
    blank.append("\t");
    QChar currentChar = QChar(),
          pos;
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

QString eqParser::toUpper (QString str)
{
    QString outStr;
    foreach (QChar currentChar, str) {
       if (isLetter(currentChar))
           currentChar = currentChar.toUpper();
       outStr.append(currentChar);
    }
    return outStr;
}

bool eqParser::isLetter(QChar currentChar)
{
    return  (('a' <= currentChar) && (currentChar <= 'z')) ||
            (('A' <= currentChar) && (currentChar <= 'Z')) ;
}

void eqParser::printEquation()
{
    std::cout << "eq: " << wString.toStdString() << std::endl;
}
