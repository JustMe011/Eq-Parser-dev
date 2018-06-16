#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <QObject>
#include <iostream>

class tokenType
{
public:
    tokenType();
    ~tokenType();

    enum tokenTypes
    {
        EMPTY = -1,
        NUMBER = 0,
        OPERATOR = 1,
        FUNCTION = 2,
        BRACKETS = 3,
        SEPARATOR = 4,
        VARIABLE = 5,
        OTHER = 6
        /* Add other types */
    };
    enum associativityType
    {
        NON_ASSOCIATIVE = 0,
        LEFT_ASSOCIATIVE = 1,
        RIGHT_ASSOCIATIVE = 2
    };

    /*
     * Parentheses,
     * Exponents Roots,
     * Multiplication/Division,
     * Addition/Subtraction
     */
    enum order
    {
      NONE = -1,
        CURLY_BRACKETS = 0,
        SQUARE_BRACKETS = 1,
        BRACKETS = 2,
        E = 3,
        MD = 4,
        AS = 5
    };

    void str(QString opcode);
    QString getStr();

    void type (tokenTypes tokType);
    tokenTypes getTokenType();

    void priority (order opOrder);
    order getPriority ();

    void associativity(associativityType AssocType);
    associativityType getAssociativity();

    void clear();

private:

    /* aggiungere priorita' operatore */

    /**************************************/
    tokenTypes tokenCode;
    QString tokenStr;
    order opPriority;
    // need to add pointer to the func
    associativityType tokenAssociativity;

    /**************************************/

};

#endif // TOKENTYPE_H
