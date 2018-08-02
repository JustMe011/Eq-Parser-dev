#include "plotPoint.h"

plotPoint::plotPoint(int nOfPoints)
{
    pointNumber = nOfPoints;

    // test:

    //storedData[DOM].idType = DOM;
    //storedData[DOM].idType = FUNC;
}

void plotPoint::setDomain()
{
    int el=0;
    for (int i:domain)
    {
        i = el++;
    }
}
