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
        //QStringList::iterator pos = qFind(blank.begin(),blank.end(),currentChar);
            if (std::find(blank.begin(),blank.end(),currentChar) != blank.end())
                outStr.append(str.at(i));
        //        pos = qFind(blank,end, currentChar);
        //outStr.append(str.at(i));if (pos != blank.end())

    }
    return outStr;
}

QString eqParser::toUpper (QString str)
{
    QString outStr;
    foreach (QChar currentChar, str) {
       if (isLetter(currentChar))
           toUpper(currentChar);
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
