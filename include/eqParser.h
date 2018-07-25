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
        int opCode;
    }; 
    struct outStruct tmpOut;

    struct passToken
    {
        tokenType * currTok;
        tokenType * lastTok;
    };
    //struct passToken passedTok;

    QString wString;
    QChar readChar;
    int outIndex = 0;
    const int NON_NUMBER_OPCODE = -1;
    QList<tokenType> tokenList; /* List of operators */
    QStack<tokenType*> opStack;
    QQueue<struct outStruct> opOut;

    // tokenize
    void tokenize();
    QString cleanChars(QString str);
    QString toUpper(QString str);
    QString toBrackets(QString str);
    bool isLetter(QChar currentChar);

    /* init */
    void fillOps();
    tokenType * getElement (QString read);

    /* output calculations */
    double pow10 (int n); /* power of 10 calculator based on LUT */
    void appendOut (tokenType * toEnqueue);
    void appendOp (tokenType * toPush);
    void printEquation();
    //double toNumber (QQueue<tokenType>  buf);

    QString readBuf;
    bool bufferingFunc = false;
    int correspondingStrs;

    bool compareFuncStr (QString buf);
   // bool doThingsWithTok (tokenType * currTok);
    bool doThingsWithTok (passToken passedTok);
    double evaluatePostfix (QQueue<struct outStruct> RPN);

public:
    eqParser();
    ~eqParser();


    //void getEquation (QString equation);
    QQueue<struct outStruct>  getRPN(QString eqString);
    void showRPN(QString eqString);
    void solveEq (QString eqString);
    double solveEq(QQueue<struct outStruct> RPN);
    void reset();

};

#endif // EQPARSER_H
