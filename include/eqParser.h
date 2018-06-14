#ifndef EQPARSER_H
#define EQPARSER_H

#include <QObject>
#include <tokenType.h>

class eqParser
{
public:
    eqParser();
    ~eqParser();

    /* clean the inserted string in order to have only equation tokens
     * remove blank spaces
     * remove strange chars
     * put all letters uppercase
     *
     */

    void tokenize(QString eqString);
private:
//    tokenType *token1 = new tokenType;
};

#endif // EQPARSER_H
