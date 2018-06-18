#include "tokenType.h"

tokenType::tokenType(tokenTypes type, QString opcode, associativityType ass)
{
    this->type(type);
    this->str(opcode);
    this->associativity(ass);
}



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

bool tokenType::isOperator()
{
    return (getPriority() > 0);
}

void tokenType::clear()
{
    tokenCode = EMPTY;
    tokenStr = tokenStr.clear();
    tokenAssociativity = NON_ASSOCIATIVE;
}

/* END GETTER METHODS */

tokenType::order tokenType::getPriority()
{
    return floor(tokenCode / 10);
}
