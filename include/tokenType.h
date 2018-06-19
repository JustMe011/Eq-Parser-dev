#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <QObject>
#include <iostream>
#include <cmath>

class tokenType
{
public:
    tokenType();
    ~tokenType();

    /* Numbers inside tokeTypes indicate the priority of the operator
     * if two operators have the same decimal digit it means that they have the same
     * priority.
     */
    enum tokenTypes
    {
        NUMBER,
        SEPARATOR,
        OPEN_BRACKET, /* we think brackets as special token without priority */
        CLOSE_BRACKET,
        OTHER,
        POWER = 10,
        ROOT = 11,
        MOLTIPLICATION = 20,
        DIVISION = 21,
        SUM = 30,
        SUBTRACTION = 31
        /* add other types */
    };

    enum associativityType
    {
        NON_ASSOCIATIVE = 0,
        LEFT_ASSOCIATIVE = 1,
        RIGHT_ASSOCIATIVE = 2
    };

    void str(QString opcode);
    QString getStr();

    void type (tokenTypes tokType);
    tokenTypes getType();

    bool isOperator();
    int getPriority ();


    void associativity(associativityType AssocType);
    associativityType getAssociativity();

    void clear();

private:

    /* aggiungere priorita' operatore */

    /**************************************/
    tokenTypes tokenCode;
    QString tokenStr;
    // need to add pointer to the func

    /* operators only */
    associativityType tokenAssociativity;

    /**************************************/



};

#endif // TOKENTYPE_H
