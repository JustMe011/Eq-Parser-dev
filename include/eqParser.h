#ifndef EQPARSER_H
#define EQPARSER_H

#include <QObject>
#include <QList>
#include <tokenType.h>

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
    QList<tokenType> tokenList;

    void tokenize();
    QString cleanChars(QString str);
    QString toUpper(QString str);
    bool isLetter(QChar currentChar);
    void printEquation();

};

#endif // EQPARSER_H
