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
    fillOps();
}

eqParser::~eqParser()
{

}


QQueue<struct eqParser::outStruct> eqParser::getRPN (QString eqString)
{

    /*****    algorithm to generate RPN    *****
     *
     * now wString is Clean... I need to work on it
     * I need to create a buffer in order to read from the string and "operate" on it.
     * My idea is: I red a char, if it's of a different type compared to the last readed
     * i can push on queue/stack,
     * if i read a number, a separator and a number again I have to compose a decimal number
     *
     *****                                 *****/
    tokenType   *lastEl,
                *currentEl;
    bool    expectingOp =false;

    std::cout << "getRPN called" << std::endl;
    std::cout << "eqString: " << eqString.toStdString() << std::endl;

    //wString = eqString;
    wString = eqString;
    tokenize();
    std::cout << "tokenized str: " << wString.toStdString() << std::endl;

    for (int strIndex=0; strIndex < wString.length(); ++strIndex){
        currentEl = getElement(wString.at(strIndex));

        if (0 == strIndex)
            lastEl = currentEl;

        if (tokenType::UNKNOWN == currentEl->getFamily())
        {
            if (!bufferingFunc)
            {
                /* starting to buffer a function opCode */
                bufferingFunc = true;
                readBuf.clear();
            }
            readBuf.append(wString.at(strIndex));

            if (notFound == compareFuncStr(readBuf)){
                std::cout << "Error: unknown token" << std::endl;
                bufferingFunc = false;
            }
        }
        else if (tokenType::OPERAND == currentEl->getFamily())
        {
            if (bufferingFunc)
                bufferingFunc ^= 1;
            if (expectingOp && tokenType::OPERAND != lastEl->getFamily())
                std::cout << "Error: two operators near" << std::endl;
            // push to queue
            //opOut->enqueue(currentEl);
            appendOut(currentEl);

            /*expectingOp = true; -> look at the beginning of the OPERATOR case */
        }
        else if (tokenType::SYNTAX == currentEl->getFamily())
        {
            if (tokenType::OPEN_BRACKET == currentEl->getType()){
                if (bufferingFunc)
                    bufferingFunc ^= 1;
                if (expectingOp)
                    std::cout << "Error: Need an operator before open bracket" << std::endl;
                opStack.push(currentEl);
                /* after open bracket he doesn't expect an op, so EO -> false,
                 * but for the previous if we know that EO is already false
                */
            }
            else if (tokenType::CLOSE_BRACKET == currentEl->getType()){
                if (bufferingFunc)
                    bufferingFunc ^= 1;
                if (tokenType::OPERATOR == lastEl->getFamily()  ||
                    tokenType::FUNCTION == lastEl->getFamily())
                    std::cout << "Error: you can't have an operator before or after a bracket"
                              << std::endl;
                // pop stack to queue until it founds a "("
                if (!opStack.empty()){
                    while ("(" != opStack.top()->getStr() && !opStack.empty()){
                        //opOut->enqueue(opStack->pop());
                        appendOut(opStack.pop());
                    }
                }

                // now I have to pop the open bracket
                if (opStack.empty())
                    std::cout << "Error: missing open bracket" << std::endl;
                appendOut(opStack.pop());
                expectingOp = true;
            }
        }
        else if (   tokenType::OPERATOR == currentEl->getFamily()    ||
                    tokenType::FUNCTION == currentEl->getFamily())
        {
            /* basic operators */
            /* move all element with higher precedence: */
            //if (!expectingOp)
            //    std::cout << "Error: Unexpected operator" << std::endl;
            if (tokenType::OPERAND == lastEl->getFamily())
                expectingOp = true;
            if (bufferingFunc)
                bufferingFunc ^= 1;
            if (!expectingOp)
                std::cout << "Error: Unexpected operator" << std::endl;
            if (!opStack.empty()){
                while ((opStack.top()->getPriority() < currentEl->getPriority() &&
                        opStack.top()->isOperator())                                &&
                        !opStack.empty()){
                    appendOut(opStack.pop());
                    if (opStack.empty())
                        break;
                }
            }
            opStack.push(currentEl);

            /* increment operator opCode */
            outIndex++;
            expectingOp = false;
        }

        /* END IF */
        lastEl = currentEl; /* Update lastEl */
 } /* END FOR */

    /* finish read tokens, now I have to push all the tack on the queue.
     * Now, if I read a open bracket (and I've finished to read tokens)
     * it means that I can't close that bracket -> ERROR
     */
    if (expectingOp)
        std::cout << "Error, can't end equation with an operator" << std::endl;
    while (!opStack.empty())
    {
        if (tokenType::OPEN_BRACKET == opStack.top()->getType())
            std::cout << "Error: Unbalanced bracket" << std::endl;
        //opOut->enqueue(opStack->pop());
        appendOut(opStack.pop());
    }
    return opOut;
}

/* END interface */

tokenType * eqParser::getElement (QString read)
{
    /* return a pointer to the corresponding element in tokenList  */

    tokenType   *element = NULL,
                *voidElement;
    for (int i=0; i<tokenList.length(); ++i){
        if (tokenList[i].getStr() == read){
            // Found element
            element = &tokenList[i];
        }
        if (tokenType::NO_TOKEN == tokenList[i].getType())
            voidElement = &tokenList[i];
    }
    if (!element)
    {
        /* if element is NULL: */
        element = voidElement;
        //element->str(read);
    }

    return element;
}

enum eqParser::foundFunc eqParser::compareFuncStr (QString buf)
{
    QString subStr;
    int     subStrPos,
            foundOccur = 0;
    enum foundFunc out;
    correspondingStrs = 0;

    for (int i=0; i<tokenList.length(); ++i)
    {
        subStrPos = tokenList[i].getStr().indexOf(buf,Qt::CaseInsensitive);
        if (0 == subStrPos)
            ++foundOccur;
    }
    out = (foundOccur > 0)? foundPartial : notFound;
    return out;
}

void eqParser::tokenize ()
{
    /* clean the inserted string in order to have only equation tokens
     * [x] remove blank spaces
     * [x] remove strange chars
     * [x] put all letters uppercase
     *
     */
    QString tmpString = wString;
    wString = cleanChars (tmpString);

    tmpString = wString;
    wString = toUpper (tmpString);

    tmpString = wString;
    wString = toBrackets (tmpString);
    /* to the next steps */
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
        //std::cout << "CurrentChar: " << currentChar.unicode() << std::endl;
        //QStringList::iterator pos = qFind(blank.begin(),blank.end(),currentChar);

        if (std::find(blank.begin(),blank.end(),currentChar) == blank.end())
            outStr.append(str.at(i));
    }
    return outStr;
}

QString eqParser::toBrackets (QString str)
{
    /* change curly brackets and square brackets into brackets */
    QString outStr;
    foreach (QChar currentChar, str) {
        if (QLatin1Char('[') == currentChar || QLatin1Char('{') == currentChar)
            currentChar = QLatin1Char('(');
        if (QLatin1Char(']') == currentChar || QLatin1Char('}') == currentChar)
            currentChar = QLatin1Char(')');
        outStr.append(currentChar);
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

int eqParser::pow10 (int n)
{
    static const int shift = 10;
    static double powsLUT[20]=
    {
        0.0000000001,
        0.000000001,
        0.00000001,
        0.0000001,
        0.000001,
        0.00001,
        0.0001,
        0.001,
        0.01,
        0.1,
        1,
        10,
        100,
        1000,
        10000,
        100000,
        1000000,
        10000000,
        100000000,
        1000000000
    };
    return powsLUT[n+shift];
}


void eqParser::fillOps()
{
    const int elements = 14;
    tokenType tmpEl;
    tokenType::tokenTypes opTypes[elements] =
    {
        tokenType::NO_TOKEN,
        tokenType::SUM,
        tokenType::SUBTRACTION,
        tokenType::MOLTIPLICATION,
        tokenType::DIVISION,
        tokenType::OPEN_BRACKET,
        tokenType::CLOSE_BRACKET,
        tokenType::POWER,
        tokenType::SEPARATOR,
        tokenType::SEPARATOR,
        tokenType::VARIABLE,
        tokenType::TRIGONOMETRIC_FUNCTION,
        tokenType::TRIGONOMETRIC_FUNCTION,
        tokenType::TRIGONOMETRIC_FUNCTION

    };
    QString opStr[elements]
    {
        "",
        "+",
        "-",
        "*",
        "/",
        "(",
        ")",
        "^",
        ".",
        ",",
        "x",
        "tan",
        "sin",
        "cos"
    };

    /* NUMBERS */
    for (int i=0; i < 10; ++i)
    {
        //tokenList.append(tokenType(tokenType::NUMBER,i));
        tmpEl.type(tokenType::NUMBER);
        tmpEl.str(QString::number(i));
        tmpEl.associativity(tokenType::NON_ASSOCIATIVE);
        tokenList.append(tmpEl);
    }
    for (int i=0; i < elements; ++i)
    {
        tmpEl.type(opTypes[i]);
        tmpEl.str(opStr[i]);
        tmpEl.associativity(tokenType::NON_ASSOCIATIVE);
        tokenList.append(tmpEl);
    }
}

void eqParser::appendOut (tokenType *toEnqueue)
{
    /* create struct element for output queue */
    if (tokenType::OPEN_BRACKET != toEnqueue->getType() &&
            tokenType::CLOSE_BRACKET != toEnqueue->getType()){
        tmpOut.tokenOut = toEnqueue;
        tmpOut.opCode =(tokenType::NUMBER == toEnqueue->getType()   ||
            tokenType::SEPARATOR == toEnqueue->getType()) ? outIndex : NON_NUMBER_OPCODE;
        opOut.enqueue(tmpOut);
    }
}

void eqParser::showRPN (QString eqString)
{
    reset();
    QQueue<struct outStruct> RPN = getRPN(eqString);
    std::cout << "RPN length: " << RPN.length() << std::endl;

    for (int i=0; i < RPN.length(); ++i){
        //std::cout << "element: " << RPN.at(i).tokenOut->getStr().toStdString() << std::endl;
        //std::cout << "op number: " << QString::number(RPN.at(i).opCode).toStdString() << std::endl;
        //std::cout << std::endl << std::endl;
        std::cout << RPN.at(i).tokenOut->getStr().toStdString() << " ";
    }
}

void eqParser::reset()
{
    /* clean all data structures before compute a new parsing */
    readBuf.clear();
    bufferingFunc = false;
    wString.clear();
    outIndex = 0;
    opStack.clear();
    opOut.clear();
}
