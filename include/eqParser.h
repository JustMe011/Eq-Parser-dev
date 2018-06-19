#ifndef EQPARSER_H
#define EQPARSER_H

#include <QObject>
#include <QList>
#include <QStack>
#include <QQueue>
#include <tokenType.h>
#include <calcs.h>
#include <plotPoint.h>

class eqParser
{

private:
    struct outStruct
    {
        tokenType * tokenOut;
        unsigned int opCode;
    };

    QString wString;

    void tokenize();
    QString cleanChars(QString str);
    QString toUpper(QString str);
    QString toBrackets(QString str);
    bool isLetter(QChar currentChar);
    void printEquation();
    void fillOps();
    int pow10 (int n); /* power of 10 calculator based on LUT */
    double toNumber (QQueue<tokenType>  buf);
    tokenType * getElement (QString read); /* return the element from tokenList we're handling */

    // RPN


    QChar readChar;
    const int NON_NUMBER_OPCODE = -1;
    QList<tokenType> tokenList; /* List of operators */
    QStack<tokenType*> opStack;
    //QQueue<tokenType> * opOut;
    QQueue<struct outStruct> opOut;
    struct outStruct tmpOut;

    int outIndex = 0;



    void appendOut (tokenType * toEnqueue);

public:
    eqParser();
    ~eqParser();


    //void getEquation (QString equation);
    QQueue<struct outStruct>  getRPN(QString eqString);
    void solveEq (QString equation);
    void solveEq(QList<tokenType> * RPN);

};

#endif // EQPARSER_H
