#ifndef EQPARSER_H
#define EQPARSER_H

#include <QObject>
#include <QList>
#include <QStack>
#include <QQueue>
#include <plotPoint.h>

class eqParser
{

private:
   void printEquation(QString wString);
   QString cleanChars (QString wString);


public:
    eqParser();
    ~eqParser();

    void solveEq (QString eqString);
    void reset();



    //QQueue<struct outStruct>  getRPN(QString eqString);
    //void showRPN(QString eqString);
    //double solveEq(QQueue<struct outStruct> RPN);

};

#endif // EQPARSER_H
