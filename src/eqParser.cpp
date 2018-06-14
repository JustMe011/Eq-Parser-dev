#include "eqParser.h"
#include <QtAlgorithms>

eqParser::eqParser (QString equation)
{
    getEquation(equation);
}

void eqParser::getEquation (QString equation)
{
    this->eqString = equation;
    wString = eqString;
    eqInserted = true;
    tokenize();
}

void eqParser::tokenize ()
{
    /* clean the inserted string in order to have only equation tokens
     * [x] remove blank spaces
     * [x] remove strange chars
     * [x] put all letters uppercase
     *
     */
    QString tmpString = QString();
    tmpString = cleanChars(wString);
    tmpString = toUpper(tmpString);
    wString = tmpString;

    //printEquation();
}

QString eqParser::cleanChars (QString str)
{
    QString outStr = QString();
    QChar   blank[] = {' ', '\n', '\t'},
            currentChar = QChar(),
            pos;
    QChar* end = blank + sizeof(blank) / sizeof(blank[0]);
    for (int i=0; i < str.length(); ++i)
    {
        currentChar = str.at(i);
        pos = qFind(blank,end, currentChar);
        if (pos != end)
            outStr.append(str.at(i));
    }
    return outStr;
}

void eqParser::printEquation()
{
    std::cout << "eq: " << wString.toStdString() << std::endl;
}
