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
        NO_TOKEN,
        NUMBER,
        SEPARATOR,
        VARIABLE,
        OPEN_BRACKET, /* we think brackets as special token without priority */
        CLOSE_BRACKET,
        OTHER,
        TRIGONOMETRIC_FUNCTION = 10,
        POWER = 20,
        ROOT = 21,
        MOLTIPLICATION = 30,
        DIVISION = 31,
        SUM = 40,
        SUBTRACTION = 41
        /* add other types */
    };

    enum associativityType
    {
        NON_ASSOCIATIVE = 0,
        LEFT_ASSOCIATIVE = 1,
        RIGHT_ASSOCIATIVE = 2
    };
    enum tokenFamilies
    {
        OPERAND,
        OPERATOR,
        FUNCTION,
        SYNTAX,
        UNKNOWN
    };

    void str(QString opcode);
    QString getStr();

    void type (tokenTypes tokType);
    tokenTypes getType();

    bool isOperator();
    int getPriority ();


    void associativity(associativityType AssocType);
    associativityType getAssociativity();

    enum tokenFamilies getFamily();
    void clear();

private:

    /* aggiungere priorita' operatore */

    /**************************************/
    tokenTypes tokenCode;
    QString tokenStr;
    // need to add pointer to the func

    tokenFamilies tokenFamily;
    associativityType tokenAssociativity;

    /**************************************/
    void family (tokenFamilies family);

};

#endif // TOKENTYPE_H
