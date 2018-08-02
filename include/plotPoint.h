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
    //QVector<double> domain(pointNumber);
    //QVector<double> funcValues (QVector<double> pointNumber);
    QVector<double> domain;
    QVector<double> funcValues;

//    pointTypes storedData[STORED_LENGTH];
    void setDomain ();
    void initializeFunValues();

};

#endif // PLOTPOINT_H
