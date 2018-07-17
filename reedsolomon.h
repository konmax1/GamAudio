#ifndef RS_H
#define RS_H
#include <stdint.h>
#include <array.h>
#include <rsparameters.h>

class RS
{
public:
    RS();
    void init();
    void MsgEnc(uint16_t* msg, uint16_t& nBytesMsg, uint16_t* parityBytes, uint16_t& nBytesSpr);
    int MsgDec(uint16_t* msg, uint16_t& nBytesMsg, uint16_t* parityBytes, uint16_t& nBytesSpr);

    //void pipelinedDivision(uint8_t* msg, uint8_t* rem);

private:
    void sortFldElm();
    void generateFldElm();
    void polyProductGF(Array* poly1,  Array* poly2, Array * polyRes);
    uint16_t multGF(uint16_t value1, uint16_t value2);
    uint16_t findIndElm(uint16_t value);
    void polyDivisionGF(Array* poly1,  Array* poly2, Array* quot,Array* rem);
    uint16_t inversElm(uint16_t value);
    void polyAddition(Array* poly1, Array* poly2, Array* polyRes);
    void generatePolyGenerator();
    void calcSyndroms(Array* msgEnc);
    bool isZero(uint16_t* mass, uint16_t l);
    bool polyErrLocator();
    uint16_t detGF(uint16_t* Mat,uint16_t dim);
    uint16_t powGF(uint16_t value,uint16_t pow);//, Array* fld
    void msgCorrection(uint16_t* msg, uint16_t* parityBytes);









//    void printMass(uint8_t* mass, uint8_t l);


public:

private:
    uint16_t nElm;
    uint16_t  lenMsg;
    uint16_t indFldElm[(1<<DEG_PLY)-1];
    uint16_t synd[2*(ERR_CPBL)];
    uint16_t MatSynd[ERR_CPBL][ERR_CPBL];
    uint16_t nErrDtc;
    uint16_t sigma[ERR_CPBL+1];
    uint16_t errInd[ERR_CPBL];
    uint16_t errValue[ERR_CPBL];
    /*
    uint8_t m;

    uint8_t k;
    uint8_t t;
    uint8_t biasDegree;







//    Array primPoly;//[degreeField+1]
//    uint8_t fldElm[255];
//    uint8_t polyGen[9];

//    uint8_t fldElmGF1[1];

//    uint8_t elm_a[9];
//    uint8_t la;
//    uint8_t elm_A[9];
//    uint8_t lA;
    */
};



#endif // POLY_H
