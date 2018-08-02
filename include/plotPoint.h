#ifndef PLOTPOINT_H
#define PLOTPOINT_H
#include <QVector>
#include <QList>

class plotPoint
{
public:
    plotPoint(int nOfPoints);
    ~plotPoint();

private:
    //bool foundData;
    int pointNumber;
    QVector<int> domain;

//    pointTypes storedData[STORED_LENGTH];
    void setDomain ();


};

#endif // PLOTPOINT_H
