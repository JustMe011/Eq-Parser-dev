#include "eqParser.h"
#include <QtAlgorithms>
#include <QString>

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
    tokenType lastEl, currentEl;

    eqString = equation;
    wString = eqString;
    eqInserted = true;
    tokenize();

    /*****    algorithm to generate RPN    *****
     *
     * now wString is Clean... I need to work on it
     * I need to create a buffer in order to read from the string and "operate" on it.
     * My idea is: I red a char, if it's of a different type compared to the last readed
     * i can push on queue/stack,
     * if i read a number, a separator and a number again I have to compose a decimal number
     *
     *****                                 *****/

    for (int eqIndex=0; eqIndex < wString.length(); ++eqIndex)
    {
        readChar = wString.at(eqIndex);
        currentEl = getElement(readChar);
        if (0 == eqIndex)
            lastEl = getElement(readChar);
        if (lastEl.getTokenType() == currentEl || 0 == eqIndex)
        {
            readBuf->enqueue(currentEl);

        }
        /* ora che ho pushato sul buffer, quando poi trovo che currentEl e' diverso da lastEl
         * posso mandare readBuf su stack/coda in base a se e' operatore o numero (ed eliminare le
         * parentesi)
         */


    }
}

/* END interface */

tokenType * eqParser::getElement (QString read)
{
    tokenType * element;
    /* compare read with tokenType::getstr() to know which token we have */
    for (int i=0; i<tokenList.length(); ++i)
        if (tokenList.at(i).getStr() == read){
            // Found element
            element = &tokenList.at(i);
        }
    return element;
}
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

void eqParser::fillOps()
{
    tokenType tmpOp;

//    tokenType::tokenTypes type;
//    tokenType::associativityType ass;

    /* NUMBERS */
    // 0

    for (int i=0; i<10; ++i)
    {
        tmpOp.type(tmpOp.NUMBER);
        tmpOp.str(QString::number(i));
        tmpOp.priority(tmpOp.NONE);
        tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

        tokenList.append(tmpOp);
        tmpOp.clear();
    }

    // sum
    tmpOp.type(tmpOp.OPERATOR);
    tmpOp.str("+");
    tmpOp.priority(tmpOp.AS);
    tmpOp.associativity(tmpOp.LEFT_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // subtraction
    tmpOp.type(tmpOp.OPERATOR);
    tmpOp.str("-");
    tmpOp.priority(tmpOp.AS);
    tmpOp.associativity(tmpOp.LEFT_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // moltiplication
    tmpOp.type(tmpOp.OPERATOR);
    tmpOp.str("*");
    tmpOp.priority(tmpOp.MD);
    tmpOp.associativity(tmpOp.LEFT_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // Division
    tmpOp.type(tmpOp.OPERATOR);
    tmpOp.str("/");
    tmpOp.priority(tmpOp.MD);
    tmpOp.associativity(tmpOp.LEFT_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // power
    tmpOp.type(tmpOp.OPERATOR);
    tmpOp.str("^");
    tmpOp.priority(tmpOp.E);
    tmpOp.associativity(tmpOp.LEFT_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // square root
    tmpOp.type(tmpOp.FUNCTION);
    tmpOp.str("sqrt");
    tmpOp.priority(tmpOp.E);
    tmpOp.associativity(tmpOp.LEFT_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // open brackets
    tmpOp.type(tmpOp.BRACKETS);
    tmpOp.str("(");
    tmpOp.priority(tmpOp.BRACKETS);
    tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // close brackets
    tmpOp.type(tmpOp.BRACKETS);
    tmpOp.str(")");
    tmpOp.priority(tmpOp.BRACKETS);
    tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // Square brackets open
    tmpOp.type(tmpOp.BRACKETS);
    tmpOp.str("[");
    tmpOp.priority(tmpOp.SQUARE_BRACKETS);
    tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // Square brackets close
    tmpOp.type(tmpOp.BRACKETS);
    tmpOp.str("]");
    tmpOp.priority(tmpOp.SQUARE_BRACKETS);
    tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // Curly brackets open
    tmpOp.type(tmpOp.BRACKETS);
    tmpOp.str("{");
    tmpOp.priority(tmpOp.CURLY_BRACKETS);
    tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // Curly brackets close
    tmpOp.type(tmpOp.BRACKETS);
    tmpOp.str("}");
    tmpOp.priority(tmpOp.CURLY_BRACKETS);
    tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // Dot
    tmpOp.type(tmpOp.SEPARATOR);
    tmpOp.str(".");
    tmpOp.priority(tmpOp.NUMBER);
    tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // Comma
    tmpOp.type(tmpOp.SEPARATOR);
    tmpOp.str(",");
    tmpOp.priority(tmpOp.NUMBER);
    tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // x
    tmpOp.type(tmpOp.VARIABLE);
    tmpOp.str("x");
    tmpOp.priority(tmpOp.NONE);
    tmpOp.associativity(tmpOp.NON_ASSOCIATIVE);

    tokenList.append(tmpOp);
    tmpOp.clear();

    // other operators...
}
