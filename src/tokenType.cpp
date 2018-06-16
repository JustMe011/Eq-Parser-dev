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

void tokenType::str(QString opcode)
{
    this->tokenStr = opcode;
}

void tokenType::type(tokenTypes tokType)
{
    this->tokenTypeCode = tokType;
}

void tokenType::associativity(associativityType AssocType)
{
    this->tokenAssociativity = AssocType;
}

void tokenType::priority (order opOrder)
{
    this->opPriority = opOrder;
}

/* getter methods */

int tokenType::getCode()
{
    return tokenCode;
}

QString tokenType::getStr()
{
    return tokenStr;
}

tokenType::tokenCodes tokenType::getType()
{
    return tokenCode;
}

tokenType::associativityType tokenType::getAssociativity()
{
    return tokenAssociativity;
}

tokenType::order tokenType::getPriority()
{
    return opPriority;
}

void tokenType::clear()
{
    tokenCode = EMPTY;
    tokenStr = tokenStr.clear();
    tokenAssociativity = NON_ASSOCIATIVE;
}

