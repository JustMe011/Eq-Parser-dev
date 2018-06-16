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
public:
    eqParser();
    ~eqParser();


    //void getEquation (QString equation);
    QList<tokenType> * getRPN(QString equation);
    void solveEq (QString equation);
    void solveEq(QList<tokenType> * RPN);

private:
    bool eqInserted = false;
    QString eqString;
    QString wString;
    QList<tokenType> tokenList; /* List of operators */
    QStack<tokenType> * opStack;
    QQueue<tokenType> * opOut;

    void tokenize();
    QString cleanChars(QString str);
    QString toUpper(QString str);
    bool isLetter(QChar currentChar);
    void printEquation();
    void fillOps();

    // RPN
    QChar readChar;
    QQueue<tokenType> * readBuf;

    tokenType * getElement (QString read);
};

#endif // EQPARSER_H
