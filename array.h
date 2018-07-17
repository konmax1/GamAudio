#ifndef ARRAY_H
#define ARRAY_H

#include "rsparameters.h"
#include <QString>
#include <QDebug>
/*#define DEG_FLD  (uint8_t)(4)
#define ERR_CPBL (uint8_t)(2)
#define DEG_PRIM (uint8_t)(1)
#define DEG_BIAS (uint8_t)(0)*/

//#include <QtCore>

class Array
{
public:
    Array();
    void printPoly();
    void deleteZeroElm();
    uint16_t poly2Dec();

public:

//


//    void fliplr();
//    bool isZero();

private:
    void initZero();


public:
    uint16_t mass[(1<<DEG_PLY)-1];//
    uint16_t len;
};

extern Array fldElm, polyPrim, polyGen;

#endif // ARRAY_H
