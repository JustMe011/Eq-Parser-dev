#include "tokenType.h"

tokenType::tokenType()
{

}

//enum tokenType::tokenTypes
//{
//    NUMBER = 0,
//    OPERATOR = 1,
//    FUNCTION = 2,
//    BRACKET = 3,
//    OTHER = 4
//    /* Add other types */
//};

//enum tokenType::associativityType
//{
//    NON_ASSOCIATIVE = 0,
//    LEFT_ASSOCIATIVE = 1,
//    RIGHT_ASSOCIATIVE = 2
//};

/* setter methods */

int tokenType::setTokenCode(int code)
{
    /* It return 0 if success or !0 otherwise */
    if (code < 0)
        return 1;
    this->tokenCode = code;
    return 0;
}

void tokenType::setTokenStr(QString opcode)
{
    this->tokenStr = opcode;
}

void tokenType::setTokenType(tokenTypes tokType)
{
    this->tokenTypeCode = tokType;
}

void tokenType::setTokenAssociativity(associativityType AssocType)
{
    this->tokenAssociativity = AssocType;
}

/* getter methods */

int tokenType::getTokenCode()
{
    return tokenCode;
}

QString tokenType::getTokenStr()
{
    return tokenStr;
}

tokenType::tokenTypes tokenType::getTokenType()
{
    return tokenTypeCode;
}

tokenType::associativityType tokenType::getTokenAssociativity()
{
    return tokenAssociativity;
}
