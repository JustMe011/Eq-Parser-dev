#ifndef PLOTPOINT_H
#define PLOTPOINT_H
#include <QVector>
#include <QList>

/* Object of plotted point */

class plotPoint
{
public:
    plotPoint();
    ~plotPoint();

    enum type{
        DOM = 0,
        FUNC = 1,
        ALL = 2
    };

    int addData (double value, type typeVector);
    int clearData (type typeVector = ALL);
    QVector<double> getValues (type typeVector, bool endAtShortest = true);
    int getLenght (type typeVector);

private:
    int status;
    bool foundData;
    const int UNKNOWN_VEC_TYPE = -1;
    static const int STORED_LENGTH = 2;
    struct pointType{
        int idType;
        QList<double> listData;
        QVector<double> VectorData;

    };
    typedef struct pointType pointTypes;
    pointTypes storedData[STORED_LENGTH];
    int getShortestLength ();


};

#endif // PLOTPOINT_H