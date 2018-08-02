#ifndef EQPARSER_H
#define EQPARSER_H

#include <QObject>
#include <QList>
#include <QStack>
#include <QQueue>
#include <plotPoint.h>

/* problem: check how to compile evaluator.c using gcc not qmake */
extern "C" {
#include <evaluator.h>
}

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


    /*
     * the C funcs (parser) will return 2 vectors containing dom_vec and fun_vec,
     * you'll need a func (using a stream) that take the data from the 2 arrays and store
     * them into the plotPoint obj
     */


};

#endif // EQPARSER_H
