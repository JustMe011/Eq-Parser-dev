#include "tokenType.h"

tokenType::tokenType()
{
    std::cout << "Created new token." << std::endl;
}

tokenType::~tokenType()
{

}
/* setter methods */

void tokenType::str(QString opcode)
{
    this->tokenStr = opcode;
}

void tokenType::type(tokenTypes tokType)
{
    this->tokenCode = tokType;
}

void tokenType::associativity(associativityType AssocType)
{
    this->tokenAssociativity = AssocType;
}

/* getter methods */

QString tokenType::getStr()
{
    return tokenStr;
}

tokenType::tokenTypes tokenType::getType()
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
    tokenStr.clear();
    tokenAssociativity = NON_ASSOCIATIVE;
}

/* END GETTER METHODS */

int tokenType::getPriority()
{
    return floor(tokenCode / 10);
}
