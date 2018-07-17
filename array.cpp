#include "array.h"

Array::Array()
{
    len = (1<<DEG_PLY)-1;
    initZero();
}

void Array::initZero()
{
    for(uint16_t iElm(0);iElm<len;iElm++)
    {
        *(mass+iElm) = 0;
    }
}



void Array::deleteZeroElm()
{
    uint16_t counter = 0;
    for (uint16_t iElm(0);iElm<len;iElm++)
    {
        if (*(mass+iElm)==0)
        {
            counter++;
            continue;
        }else
            break;

    }
    if (counter==0)
        return;
    else if(counter==len)
    {
        *mass = 0;
        len = 1;
    }else{
        len -=counter;
        memcpy(mass,mass+counter,2*len);
    }
}

uint16_t Array::poly2Dec()
{
    uint16_t res = 0;
    for(uint16_t iElm(0);iElm<len;iElm++)
    {
        res += *(mass+iElm)*(1<<(len-iElm-1));
    }
    return res;
}
/*
void Array::fliplr()
{
    uint8_t temp[2*(ERR_CPBL)];
    memcpy(temp,mass,len);
    for(uint8_t iElm(0);iElm<2*(ERR_CPBL);iElm++)
    {
        *(mass+iElm) = temp[len-iElm-1];
    }
}

bool Array::isZero()
{
    for(uint8_t iElm(0);iElm<len;iElm++)
    {
        if (*(mass+iElm) )
            return false;
    }

    return true;
}
*/
void Array::printPoly()
{
    QString strPoly;
    for(uint8_t iElm(0);iElm<len;iElm++)
    {
        strPoly.append(QString::number( *(mass+iElm) )+" ");
    }
    qDebug()<<"printMass"<<strPoly;
}

Array fldElm;
Array polyPrim;
Array polyGen;
