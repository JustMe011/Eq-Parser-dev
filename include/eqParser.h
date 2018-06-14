#ifndef EQPARSER_H
#define EQPARSER_H

#include <QObject>
#include <tokenType.h>

class eqParser
{
public:
    eqParser();
    eqParser(QString equation);
    ~eqParser();


    void getEquation (QString equation);
private:
    bool eqInserted = false;
    QString eqString;
    QString wString;
    void tokenize();
    QString cleanChars(QString str);
    QString toUpper(QString str);
    void printEquation();

};

#endif // EQPARSER_H
