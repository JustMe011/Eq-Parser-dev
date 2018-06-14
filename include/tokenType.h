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
        NUMBER = 0,
        OPERATOR = 1,
        FUNCTION = 2,
        BRACKET = 3,
        OTHER = 4
        /* Add other types */
    };
    enum associativityType
    {
        NON_ASSOCIATIVE = 0,
        LEFT_ASSOCIATIVE = 1,
        RIGHT_ASSOCIATIVE = 2
    };

    int getTokenCode();
    int setTokenCode(int code);

    void setTokenStr(QString opcode);
    QString getTokenStr();

    void setTokenType(tokenTypes tokType);
    tokenTypes getTokenType();

    void setTokenAssociativity(associativityType AssocType);
    associativityType getTokenAssociativity();

private:

    /* properties of a single token */
    int tokenCode;
    QString tokenStr;
    // need to add pointer to the func
    tokenTypes tokenTypeCode;
    associativityType tokenAssociativity;

    /* end token properties */

};

#endif // TOKENTYPE_H
