#include "plotPoint.h"

plotPoint::plotPoint()
{
    storedData[DOM].idType = DOM;
    storedData[DOM].idType = FUNC;
}

int plotPoint::addData (double value, type typeVector)
{
    foundData = false;
    status = EXIT_SUCCESS;

    for (int i=0; i < STORED_LENGTH; ++i )
    {
        pointTypes currEl = storedData[i];
        if (typeVector == currEl.idType){
            currEl.listData.append(vaue);
            foundData = true;
        }
    }
    if (!foundData)
        status = UNKNOWN_VEC_TYPE;
    return status;
}

int plotPoint::clearData (type typeVector = 2)
{
    status = EXIT_SUCCESS;

    for (int i=0; i < STORED_LENGTH; ++i )
    {
        pointTypes currEl = storedData[i];
        if (typeVector == currEl.idType || 2 == typeVector){
            currEl.listData.clear();
            foundData = true;
        }
    }
    if(!foundData)
        status = UNKNOWN_VEC_TYPE;
    return status;
}

QVector plotPoint::getValues (type typeVector, bool endAtShortest = true)
{
    /* At the moment you can get ONE vector at the time ->
     * ALL the vectors in a future implementation
     * right now the software force you to end at the shortest list
     */

    status = EXIT_SUCCESS;
    pointTypes tmpData[STORED_LENGTH] = storedData;

    /* look for the shortest list */

    for (int i=0; i < STORED_LENGTH; ++i )
    {
        pointTypes currEl = storedData[i];
        /* da rivedere e riscrivere con i puntatori */
        if (currEl.listData.length() > shortest){
            for (int j=1; j<currEl.listData.length(); ++j)
                currEl.listData.removeAt(j);
        }

        if (typeVector == currEl.idType){
            currEl.VectorData = currEl.listData.toVector();
            foundData = true;
        }
    }

}

int plotPoint::getShortestLength (pointType *points)
{
    int shortest = points[0].listData.length();
    for (int i=0; i < STORED_LENGTH; ++i )
    {
        if (shortest > points[i].listData.length())
            shortest = points[i].listData.length();
    }
    return shortest;
}

int plotPoint::getLenght (type typeVector)
{
    int listLength;
    int outVal;
    for (int i=0; i < STORED_LENGTH; ++i )
    {
        pointTypes currEl = storedData[i];
        if (typeVector == currEl.idType){
            listLength = currEl.listData.length();
            foundData = true;
        }
    }
    outVal = listLength;
    if (!foundData)
        outVal = UNKNOWN_VEC_TYPE;
    return outVal;
}
