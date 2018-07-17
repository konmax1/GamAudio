#include "reedsolomon.h"
#include <QDebug>
//#include "func.h"

//extern QElapsedTimer timerPrfl;

extern double timeSyndrome;
extern double timeErrLocator;
extern double timeErrLocator;
extern double timeMsgCorrection;

extern Array fldElm;
extern Array polyPrim;
extern Array polyGen;

RS::RS()
{
    nElm = (1<<DEG_PLY)-1;
    lenMsg = nElm-2*ERR_CPBL;
    nErrDtc = 0;
    uint16_t poly;
    switch (DEG_PLY) {
    case 4:
        poly = 19;
        break;
    case 5:
        poly = 37;
        break;
    case 6:
        poly = 67;
        break;
    case 7:
        poly = 137;
        break;
    case 8:
        poly = 285;
        break;
    case 9:
        poly = 529;
        break;
    default:
        break;
    }

    for(uint16_t i(0);i<DEG_PLY+1;i++)
    {
        if (poly & 1<<i)
            *(polyPrim.mass+DEG_PLY-i) = 1;
        else
            *(polyPrim.mass+DEG_PLY-i) = 0;
    }
    polyPrim.len = DEG_PLY+1;

    *fldElm.mass = 1;
    fldElm.len = 1;

}

void RS::init()
{
    sortFldElm();
    generateFldElm();
    sortFldElm();
    generatePolyGenerator();
}


void RS::sortFldElm()
{
    for(uint16_t i(1);i<=fldElm.len;i++)
    {
//        qDebug()<<i;
        for(uint16_t iElm(0);iElm<fldElm.len;iElm++)
        {
            if (*(fldElm.mass+iElm)==i )
            {
                indFldElm[i-1] = iElm;
                break;
            }
        }
    }
}

void RS::generateFldElm()
{
    Array primElm;
    *(primElm.mass) = 1;
    primElm.len = DEG_PRIM_ELM+1;

    Array polyTmp;
    *(polyTmp.mass) = 1;
    polyTmp.len = 1;

    Array quat;

    for (uint16_t iElm(1);iElm<nElm;iElm++)
    {
//        qDebug()<<"iElm"<<iElm;
//        polyTmp.printPoly();
        polyProductGF(&polyTmp, &primElm, &polyTmp);
//        qDebug()<<"A Interm";
//        polyTmp.printPoly();
        polyDivisionGF(&polyTmp, &polyPrim,&quat,&polyTmp);
//        qDebug()<<"A End";
//        polyTmp.printPoly();
//        quat.printPoly();
        *(fldElm.mass+iElm) = polyTmp.poly2Dec();
//        qDebug()<<"ElmDecDec"<<polyTmp.poly2Dec();
//        qDebug()<<""<<endl;
    }
    fldElm.len = nElm;

}




void RS:: polyProductGF(Array* poly1,  Array* poly2,  Array * polyRes)
{
    uint16_t value1,value2;
    Array polyMult;

    for(uint16_t i(0);i<poly1->len+poly2->len-1;i++)
    {
        for(uint16_t m(0);m<poly1->len;m++)
        {
            value1 = *(poly1->mass+m);

            if ( (i-m)<0 )
            {
                break;
            }else if((i-m)>=poly2->len){
                continue;
            }else
                value2 = *(poly2->mass+i-m);

            *(polyMult.mass+i) ^= multGF(value1,value2);

        }

    }
    polyMult.len = poly1->len+poly2->len-1;
    polyRes->len = poly1->len+poly2->len-1;
    memcpy(polyRes->mass,polyMult.mass,2*polyRes->len);

    polyRes->deleteZeroElm();
}

uint16_t RS::multGF(uint16_t value1, uint16_t value2)
{
    if ( (!value1) || (!value2) )
        return (uint16_t)0;

    uint16_t indVal1 = findIndElm(value1);
    uint16_t indVal2 = findIndElm(value2);
    uint16_t valueRes = *( fldElm.mass+(indVal1+indVal2)%(fldElm.len) );
    return valueRes;

}

uint16_t RS::findIndElm(uint16_t value)
{
        return indFldElm[value-1];
}


void RS::polyDivisionGF(Array* poly1,  Array* poly2, Array* quot,Array* rem)
{
    uint16_t value;
    uint16_t elem;
    uint16_t divider = inversElm(*poly2->mass);
    for(uint16_t iElm(0);iElm<poly1->len-poly2->len+1;iElm++)
    {
        *(quot->mass+iElm) = 0;
        value = 0;
        for(uint16_t m(0);m<iElm;m++)
        {
            if ( (iElm-m)<0 )
            {
                break;
            }else if ( (iElm-m)>=poly2->len )
                continue;
            else
                elem = *(poly2->mass+iElm-m);

            value ^= multGF( *(quot->mass+m),elem);

        }

        *(quot->mass+iElm) = multGF(*(poly1->mass+iElm)^value,divider);
    }
    quot->len = poly1->len - poly2->len+1;
    if (  (poly1->len - poly2->len) < 0)
    {
        *(quot->mass) = 0;
        quot->len = 1;
    }
    quot->deleteZeroElm();
    Array polyInterm;
    polyProductGF(quot,poly2,&polyInterm);
    polyAddition(poly1,&polyInterm,rem);
}

uint16_t RS::inversElm(uint16_t value)
{
    uint16_t indValue = findIndElm(value);
    uint16_t inversInd = (-indValue+nElm)%nElm;
    return *(fldElm.mass+inversInd);
}

void RS::polyAddition(Array* poly1, Array* poly2, Array* polyRes)
{
    uint16_t lenMin;
    Array polyInterm;

    if (poly1->len>=poly2->len)
    {
        lenMin = poly2->len;
        polyInterm.len = poly1->len;
        memcpy(polyInterm.mass,poly1->mass,2*polyInterm.len);
    }
    else{
        lenMin = poly1->len;
        polyInterm.len = poly2->len;
        memcpy(polyInterm.mass,poly2->mass,2*polyInterm.len);
    }

    for(uint16_t iElm(0);iElm<lenMin;iElm++)
    {
        *(polyInterm.mass+polyInterm.len-1-iElm) = *(poly1->mass+poly1->len-1-iElm)^*(poly2->mass+poly2->len-1-iElm);
    }
    memcpy(polyRes->mass,polyInterm.mass,2*polyInterm.len);

    polyRes->deleteZeroElm();
}



void RS::generatePolyGenerator()
{
    uint16_t  biasDegree = (DEG_BIAS)%nElm;

    *(polyGen.mass) = 1;
    *(polyGen.mass+1) = *(fldElm.mass+biasDegree);
    polyGen.len = 2;

    Array polyIntrm;
    *(polyIntrm.mass) = 1;
    polyIntrm.len = 2;

    for(uint16_t g(0);g<2*ERR_CPBL-1;g++)
    {
        *(polyIntrm.mass+1) = *(fldElm.mass+(biasDegree+g+1)%nElm ) ;
        polyProductGF(&polyGen,&polyIntrm,&polyGen);
    }
}

/*
void RS::pipelinedDivision(uint8_t *msg, uint8_t *spear)
{
    *(polyGen.mass+0) = 3;
    *(polyGen.mass+1) = 7;
    *(polyGen.mass+2) = 9;
    *(polyGen.mass+3) = 5;
    *(polyGen.mass+4) = 8;

    uint8_t rem[2*ERR_CPBL];
    memset(rem,0,2*ERR_CPBL);
    uint8_t coeff = inversElm(*polyGen.mass);//, &fldElm
    uint8_t factor;
    uint8_t tmp;
    for(uint8_t iElm(0);iElm<k;iElm++)
    {
        factor = multGF(coeff,rem[0]^*(msg+iElm));//,&fldElm
        memcpy(rem,rem+1,2*ERR_CPBL-1);
        rem[(2*ERR_CPBL)-1] = 0;
        for(uint8_t i(0);i<2*ERR_CPBL;i++)
        {
            tmp = *(polyGen.mass+i+1);
            rem[i] ^= multGF(factor, *(polyGen.mass+i+1) );//,&fldElm
        }
    }
    memcpy(spear,rem,2*ERR_CPBL);
}
*/






void RS::MsgEnc(uint16_t *msg, uint16_t &nBytesMsg, uint16_t *parityBytes, uint16_t &nBytesSpr)
{
    ////---------------------
    /// Method1
    /// --------------------
    /*
    Array quot;
    Array rem;

    Array msgFull;
    msgFull.initZero();
    memcpy(msgFull.mass,msg,k);
    //    polyProductGF(&polyMsg,&polyPrelim,&fldElm,&msgFull);

    polyDivisionGF(&msgFull,&polyGen,&fldElm,&quot,&rem);

    if (rem.len!=2*t)
    {
        uint8_t temp[2*(ERR_CPBL)];
        memcpy(temp,rem.mass,rem.len);
        for(uint8_t iElm(0);iElm<2*t-rem.len;iElm++)
            *(rem.mass+iElm) = 0;
        memcpy(rem.mass+2*t-rem.len,temp,rem.len) ;
        rem.len = 2*t;
    }
    memcpy(parityBytes,rem.mass,rem.len);
    nBytesMsg = k;
    nBytesSpr = 2*t;
    */
    ////---------------------
    /// End Method1
    /// --------------------


    ////---------------------
    /// Method2
    /// --------------------
    uint16_t rem[2*ERR_CPBL];
    memset(rem,0,2*ERR_CPBL*2);
    uint16_t coeff = inversElm(*polyGen.mass);
    uint16_t factor;
    uint16_t tmp;
    for(uint16_t iElm(0);iElm<lenMsg;iElm++)
    {
        factor = multGF(coeff,rem[0]^*(msg+iElm));
        memcpy( rem,rem+1, 2*(2*ERR_CPBL-1) );
        rem[(2*ERR_CPBL)-1] = 0;
        for(uint16_t i(0);i<2*ERR_CPBL;i++)
        {
            tmp = *(polyGen.mass+i+1);
            rem[i] ^= multGF(factor, *(polyGen.mass+i+1));
        }
    }
    memcpy(parityBytes,rem,2*ERR_CPBL*2);
    nBytesMsg = lenMsg;
    nBytesSpr = 2*ERR_CPBL;
    ////---------------------
    /// End Method2
    /// ---------------------
}


int RS::MsgDec(uint16_t *msg, uint16_t &nBytesMsg, uint16_t *parityBytes, uint16_t &nBytesSpr)
{
   // int t1,t2;

    Array msgEnc;
    memcpy(msgEnc.mass,msg,lenMsg*2);
    memcpy(msgEnc.mass+lenMsg,parityBytes,2*ERR_CPBL*2);
    msgEnc.len = nElm;
 //   t1 = timerPrfl.elapsed();
    calcSyndroms(&msgEnc);
  //  t2 = timerPrfl.elapsed();
    //timeSyndrome += double(t2-t1)/1000;

//    qDebug()<<"Syndeome";
//    printPoly(synd,2*ERR_CPBL);

    if (isZero(synd,2*ERR_CPBL))
        return 1;

    if ( polyErrLocator() )
    {
        msgCorrection(msg,parityBytes);
        return 2;
    }else
        return 0;



}


void RS::calcSyndroms(Array *msgEnc)
{
    uint16_t value,elem;
    for(uint16_t iSynd(0);iSynd<2*ERR_CPBL;iSynd++)
    {
        elem = *(fldElm.mass+(DEG_BIAS+iSynd)%nElm);
        synd[iSynd] = 0;
        for(uint16_t iElm(0);iElm<nElm;iElm++)
        {
            value = multGF(synd[iSynd],elem);
            synd[iSynd] = value^*(msgEnc->mass+iElm);
        }
    }
    for(uint16_t iRow(0);iRow<ERR_CPBL;iRow++)
    {
        for(uint16_t iColumn(0);iColumn<ERR_CPBL;iColumn++)
        {
            MatSynd[iRow][iColumn] = synd[iRow+iColumn];
        }
    }
}

bool RS::isZero(uint16_t *mass, uint16_t l)
{
    for(uint16_t iElm(0);iElm<l;iElm++)
    {
        if (*(mass+iElm) )
            return false;
    }
    return true;
}

bool RS::polyErrLocator()
{
    //int t1,t2;



    uint16_t det;
    for(uint16_t iT(ERR_CPBL);iT>0;iT--)
    {
        det = detGF(&MatSynd[0][0],iT);
        if (det)
        {
            nErrDtc = iT;
            break;
        }


    }



    uint16_t mat[ERR_CPBL][ERR_CPBL];
    uint16_t detErr;
    uint16_t invDet = inversElm(det);

    for(uint16_t iT(0);iT<nErrDtc;iT++)
    {
        memcpy(&mat[0][0],&MatSynd[0][0],ERR_CPBL*ERR_CPBL*2);
        for(uint16_t jT(0);jT<nErrDtc;jT++)
        {
            mat[jT][iT] = synd[nErrDtc+jT];
        }
//        t1 = timerPrfl.elapsed();
        detErr = detGF(&mat[0][0],nErrDtc);
//        t2 = timerPrfl.elapsed();
//        timeErrLocator += double(t2-t1)/1000;
        sigma[nErrDtc-iT] = multGF(detErr,invDet);
    }
    sigma[0] =1;

    //    qDebug()<<"Sigma";
    //    printPoly(sigma,nErr+1);

    uint16_t value;
    uint16_t errLoc = 0;
    int16_t counter = 0;
    for(uint16_t iElm(0);iElm<nElm;iElm++)
    {
        errLoc = 0;
        for(uint16_t iSig(0);iSig<nErrDtc+1;iSig++)
        {
            value = powGF( *(fldElm.mass+iElm),nErrDtc-iSig);
            errLoc ^= multGF(sigma[iSig],value);
        }
        if ( !errLoc )
        {
            errInd[counter] = iElm;
            counter++;
        }
    }
    if (counter!=nErrDtc)
        return false;

    uint16_t matErr[ERR_CPBL][ERR_CPBL];
    uint16_t elem;
    for(uint16_t i(0);i<nErrDtc;i++)
    {
        for(uint16_t j(0);j<nErrDtc;j++)
        {
            elem = *(fldElm.mass+errInd[j]);
            matErr[i][j] = powGF(elem,DEG_BIAS+i);//,&fldElm
        }
    }

    det = detGF(&matErr[0][0],nErrDtc);
    invDet = inversElm(det);//,&fldElm
    uint16_t matErrVal[ERR_CPBL][ERR_CPBL];
    for(uint16_t iErr(0);iErr<nErrDtc;iErr++)
    {
        memcpy(&matErrVal[0][0],&matErr[0][0],ERR_CPBL*ERR_CPBL*2);
        for(uint16_t iElm(0);iElm<nErrDtc;iElm++)
        {
            matErrVal[iElm][iErr] = synd[iElm];
        }

        detErr = detGF(&matErrVal[0][0],nErrDtc);

        errValue[iErr] = multGF(detErr,invDet);//,&fldElm
    }
    //    qDebug()<<"indErr valErr";
    //    printPoly(errInd,nErr);
    //    printPoly(errValue,nErr);



    return true;
}


uint16_t RS::detGF(uint16_t* Mat, uint16_t dim)
{
   // int t1,t2;

    uint16_t M[ERR_CPBL][ERR_CPBL];
    memcpy(&M[0][0],Mat,ERR_CPBL*ERR_CPBL*2);

    uint16_t metka = 0;
//    t1 = timerPrfl.elapsed();

    for(uint16_t iDim(0);iDim<dim;iDim++)
    {
        if (!M[iDim][iDim] )
        {
            metka = 0;
            for(uint16_t iDim2(iDim+1);iDim2<dim;iDim2++)
            {
                if ( M[iDim2][iDim] )
                {
                    metka = 1;
                    for(uint16_t iColumn(iDim);iColumn<dim;iColumn++)
                    {
                        M[iDim][iColumn] ^= M[iDim2][iColumn];
                    }
                    break;
                }
            }
            if (!metka)
                return (uint16_t)0;
        }
//        t1 = timerPrfl.elapsed();
        uint16_t invValue;
        uint16_t value;
        uint16_t coeff;
        for(uint16_t iDim2(iDim+1);iDim2<dim;iDim2++)
        {
            invValue = inversElm( M[iDim][iDim]);
         //   t1 = timerPrfl.elapsed();
            coeff = multGF( M[iDim2][iDim],invValue);
          //  t2 = timerPrfl.elapsed();
           // timeErrLocator += double(t2-t1)/1000;
            for(uint16_t iColumn(iDim);iColumn<dim;iColumn++)
            {
             //   t1 = timerPrfl.elapsed();
                value =  multGF(coeff,M[iDim][iColumn]);
             //   t2 = timerPrfl.elapsed();
             //   timeErrLocator += double(t2-t1)/1000;
                M[iDim2][iColumn] ^= value;
            }

        }
//        t2 = timerPrfl.elapsed();
//        timeErrLocator += double(t2-t1)/1000;
    }

//    t2 = timerPrfl.elapsed();
//    timeErrLocator += double(t2-t1)/1000;

    uint16_t det = 1;
    for(uint16_t iDim(0);iDim<dim;iDim++)
    {
        det = multGF(det,M[iDim][iDim]);
    }

    return det;

}

void RS::msgCorrection(uint16_t *msg, uint16_t *parityBytes)
{
    //int t1,t2;
   // t1 = timerPrfl.elapsed();
    uint16_t ind;
    for(uint16_t iErr(0);iErr<nErrDtc;iErr++)
    {
        ind = nElm-errInd[iErr]-1;
        if (ind<lenMsg)
            *(msg+ind ) ^=  errValue[iErr];
        else
            *(parityBytes+ind-lenMsg) ^=  errValue[iErr];
    }
  //  t2 = timerPrfl.elapsed();
  //  timeMsgCorrection+= double(t2-t1)/1000;
}



uint16_t RS::powGF(uint16_t value,uint16_t pow)
{
    uint16_t indValue,ind,valuePow;
    indValue = findIndElm(value);
    ind = (indValue*pow)%nElm;
    valuePow = *(fldElm.mass+ind);
    return valuePow;
}
/*
void RS::printMass(uint8_t *mass, uint8_t l)
{
    QString strPoly;
    for(uint8_t iElm(0);iElm<l;iElm++)
    {
        strPoly.append(QString::number( *(mass+iElm) )+" ");
    }
    //    qDebug()<<"printPoly"<<strPoly;
}



*/
