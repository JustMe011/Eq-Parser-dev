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
    this->tokenStr = opcode.toUpper();

}

void tokenType::type(tokenTypes tokType)
{
    this->tokenCode = tokType;
    if (    NUMBER == tokType               ||
            SEPARATOR == tokType            ||
            VARIABLE == tokType)
        family(OPERAND);
    else if (   OPEN_BRACKET == tokType     ||
                CLOSE_BRACKET == tokType)
        family(SYNTAX);
    else if (   POWER == tokType            ||
                MOLTIPLICATION == tokType   ||
                DIVISION == tokType         ||
                ROOT == tokType             ||
                SUM == tokType              ||
                SUBTRACTION == tokType      ||
                FUNCTION == tokType)
        family(OPERATOR);
    else if (   NO_TOKEN == tokType)
        family(UNKNOWN);
}

void tokenType::family (tokenFamilies family)
{
    this->tokenFamily = family;
}

enum tokenType::tokenFamilies tokenType::getFamily()
{
    return tokenFamily;
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
