#include "plotPoint.h"

plotPoint::plotPoint(int nOfPoints)
{
    pointNumber = nOfPoints;
    domain.reserve(pointNumber);
    funcValues.reserve(pointNumber);

    setDomain();
    initializeFunValues();
}

void plotPoint::setDomain()
{
    int el=0;
    for (double i:domain)
    {
        i = el++;
    }
}

void plotPoint::initializeFunValues()
{
    for (double i:funcValues)
        i = 0;
}
