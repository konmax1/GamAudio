#include "recieverdata.h"
/*double GILBERT_COEFF[GILBERT_POR + 1] = { 4.54486433486115e-05, -0.0319136045611685, -3.31277815639291e-05,
-0.0260478358874455, -1.59427170179442e-06, -0.0373284021357407, 3.46942587567515e-06, -0.0531107459937533,
-1.03378562696214e-06, -0.0766995375013512, -5.96683448033596e-06, -0.116853826766850, 1.66624629076986e-05,
-0.205805810057242, -1.89302802971010e-05, -0.634472629392063, 0, 0.634472629392063, 1.89302802971010e-05,
0.205805810057242, -1.66624629076986e-05, 0.116853826766850, 5.96683448033596e-06, 0.0766995375013512,
1.03378562696214e-06, 0.0531107459937533, -3.46942587567515e-06, 0.0373284021357407, 1.59427170179442e-06,
0.0260478358874455, 3.31277815639291e-05, 0.0319136045611685, -4.54486433486115e-05 };*/

double GILBERT_COEFF[GILBERT_POR + 1] = { 1.12766257565378e-15, -0.000130476138946637, 1.08440643400614e-15, -0.000202974874492264,
1.30697021891335e-15, -0.000354719283426647, 2.46669069323428e-15, -0.000575250463727568, 2.80690169882469e-15, -0.000883857088375641,
4.33981913868786e-15, -0.00130330168977613, 4.55511698436463e-15, -0.00185939798324038, 7.19669940463062e-15, -0.00258167356074216,
7.48708480201243e-15, -0.00350379792006896, 8.76528269737490e-15, -0.00466413199499281, 9.63857434562979e-15, -0.00610684027599471, 
1.17297636440659e-14, -0.00788378504050172, 1.15212299759957e-14, -0.0100574770235473, 1.28212542532071e-14, -0.0127057846270374,
1.31705203848549e-14, -0.0159297427523464, 1.31626169983955e-14, -0.0198667595692114, 1.32911861084294e-14, -0.0247135142548792,
1.29403657015555e-14, -0.0307674767459450, 1.25408237791250e-14, -0.0385071038803095, 1.05838177775279e-14, -0.0487598745391298, 
9.65209562304999e-15, -0.0630945205179159, 8.68191076750970e-15, -0.0848854458812239, 6.02711729550647e-15, -0.122931145484905,
4.38622442320337e-15, -0.209544916583793, 2.00671932765079e-15, -0.635728180480659, 0, 0.635728180480659, -2.00671932765079e-15,
0.209544916583793, -4.38622442320337e-15, 0.122931145484905, -6.02711729550647e-15, 0.0848854458812239, -8.68191076750970e-15,
0.0630945205179159, -9.65209562304999e-15, 0.0487598745391298, -1.05838177775279e-14, 0.0385071038803095, -1.25408237791250e-14,
0.0307674767459450, -1.29403657015555e-14, 0.0247135142548792, -1.32911861084294e-14, 0.0198667595692114, -1.31626169983955e-14,
0.0159297427523464, -1.31705203848549e-14, 0.0127057846270374, -1.28212542532071e-14, 0.0100574770235473, -1.15212299759957e-14,
0.00788378504050172, -1.17297636440659e-14, 0.00610684027599471, -9.63857434562979e-15, 0.00466413199499281, -8.76528269737490e-15,
0.00350379792006896, -7.48708480201243e-15, 0.00258167356074216, -7.19669940463062e-15, 0.00185939798324038, -4.55511698436463e-15,
0.00130330168977613, -4.33981913868786e-15, 0.000883857088375641, -2.80690169882469e-15, 0.000575250463727568, -2.46669069323428e-15,
0.000354719283426647, -1.30697021891335e-15, 0.000202974874492264, -1.08440643400614e-15, 0.000130476138946637, -1.12766257565378e-15 };

double StartPSP_In_255[255] = { 1, -1, -1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, 1, -1, 1, -1, -1, -1, 1, 1,
-1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, -1, 1, -1, -1, 
-1, 1, 1, 1, -1, 1, -1, -1, 1, -1, 1, -1, -1, -1, 1, -1, 1, 1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 1, -1,
-1, -1, -1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1,
1, -1, -1, 1, -1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, 1, -1, -1, 1, 1, 1, 1, -1, 1, 1, -1, 1, 1, -1, -1, 1,
1, -1, -1, 1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, -1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, -1, 1, 1, -1, -1, -1,
1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, 
-1, -1, 1, -1, 1, 1, 1, -1, 1 };

quint32 RecieverData::getFreqDiskr()
{
    return freqDiskr;
}

void RecieverData::setFreqDiskr(quint32 value)
{
    freqDiskr = value;
}

void RecieverData::clearDebugData()
{
	debugFileData.resize(0);
}

RecieverData::RecieverData(QObject *parent)
    : QObject(parent)
{
	reedsolomon.init();
	freqDiskr = 300000;
    freqSignal = 6000;
	freqval.resize(2);
	freqval[0].freqWave = 36000;
    freqval[0].delayLine.resize(freqDiskr/freqSignal);
    freqval[1].freqWave = 39000;
    freqval[1].delayLine.resize(freqDiskr/freqSignal);
	counterThinning = 0;
	delayLine.resize(GILBERT_POR + 1, 0);

    audiocodec = codec2_create(CODEC2_MODE_1200);
}

RecieverData::~RecieverData()
{
}


double RecieverData::Gilbert(double & sample)
{
	double res = 0;
	double *p1 = &GILBERT_COEFF[0];
	double *p2 = &delayLine[0];
	memmove(&delayLine[1], &delayLine[0], (GILBERT_POR) * sizeof(double));
	delayLine[0] = sample;
	for (volatile int i = 0; i < GILBERT_POR + 1; i++) {
		//res += delayLine[i] * GILBERT_COEFF[i];
		res += *p1 * *p2;
		p1++;
		p2++;
	}
	//res = std::inner_product(delayLine.begin(), delayLine.end(), &GILBERT_COEFF[0], (double)0.0);
	sample = delayLine[GILBERT_POR2]; // +1 ????
	return res;
}

QVector<debugDataFile>& RecieverData::getDataToWrite()
{
	return debugFileData;
}

void RecieverData::setFreqSignal(const qint32 &value)
{
    freqSignal = value;
}

void RecieverData::getWave(int channel)
{
    if (channel >= freqval.size())
        return;
	freqVal * p;
	p = &freqval[channel];


	p->signal_freq.re =  cos(2 * M_PI * p->freqWave * p->count_freq / freqDiskr);
	p->signal_freq.im = -sin(2 * M_PI * p->freqWave * p->count_freq / freqDiskr);
	p->count_freq = (p->count_freq + 1) % freqDiskr;
	
}

void RecieverData::complexMult(complex_double &_in, complex_double &_in2, complex_double & _out)
{
	_out.re = _in.re * _in2.re - _in.im * _in2.im;
	_out.im = _in.re * _in2.im + _in.im * _in2.re;
}

complex_double RecieverData::complexSum(std::vector<complex_double>& _vect) {
	complex_double res = { 0,0 };
	for (volatile int i = 0; i < _vect.size(); i++) {
		res.im = res.im + _vect[i].im;
		res.re = res.re + _vect[i].re;
	}
	return res;
}

double RecieverData::complexAbs(complex_double & _cmplx)
{
	double res;
	res = sqrt(_cmplx.im * _cmplx.im + _cmplx.re * _cmplx.re);
	return res;
}

double RecieverData::scalar(double & in1, double & in2,int32_t size)
{
	double res = 0;
	double *p1 = &in1;
	double *p2 = &in2;
	for (volatile int i = 0; i < size; i++) {
		res += *p1 * *p2;
		p1++;
		p2++;
	}
	return res;
}

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))

uint16_t reedSolomonInput[8][63];


void RecieverData::processingThinData()
{
	static int stateProc = 0;
	static double maxscalar = 0;
	double scalar1, scalar2;
	std::vector<double> *p_thin;
	if (stateProc == 0) {
		for (volatile int i = 0; i < thinningSignal2.size(); i++) {//thinningSignal2 == thinningSignal1 
			scalar1 = scalar(*thinningSignal1.data(), StartPSP_In_255[0], 255);
			scalar2 = scalar(*thinningSignal2.data(), StartPSP_In_255[0], 255);
			if (scalar1 >= scalar2) {
				maxscalar = scalar1;
				if (maxscalar > 120) {
					stateProc = 1;
					p_thin = &thinningSignal1;
					break;
				}
			}
			else {
				maxscalar = scalar2;
				if (maxscalar > 120) {
					stateProc = 2;
					p_thin = &thinningSignal2;
					break;
				}
			}
			thinningSignal1.erase(thinningSignal1.begin());
			thinningSignal2.erase(thinningSignal2.begin());
		}
		thinningSignal1.erase(thinningSignal1.begin(), thinningSignal1.begin() + 20);
		thinningSignal2.erase(thinningSignal2.begin(), thinningSignal2.begin() + 20);
	}
	if (stateProc > 0) {
		//need 3024 bits
		if (stateProc == 1) {
			if (thinningSignal1.size() >= 3024) {
				for (volatile int i = 0; i < 3024; i++) {
					thinningSignal1[i] = (thinningSignal1[i] + 1) / 2;
				}
				volatile int cntRS = 0;
				for (volatile int i = 0; i < 8; i++) {
					for (volatile int j = 0; j < 63; j++) {
						for (volatile int k = 0; k < 6; k++) {
							cntRS++;
							if (thinningSignal1[cntRS/*i * 63 * 6 + j * 6 + k*/] == 1){
								SET_BIT(reedSolomonInput[i][j], k);
							}
							else {
								CLEAR_BIT(reedSolomonInput[i][j], k);
							}
						}
					}
				}
				int32_t rs_stat;
                uint16_t nBytesMsg = 15, nBytesPar = 48;
                uint8_t lin90[120];
				for (volatile int i = 0; i < 8; i++) {
					rs_stat = reedsolomon.MsgDec(&reedSolomonInput[i][0], nBytesMsg, &reedSolomonInput[i][15], nBytesPar);	// декодеруем
					for (volatile int j = 0; j < 15; j++) {
						lin90[i * 8 + j] = reedSolomonInput[i][j];
					}
				}
                uint8_t t1,t2,t3;
				for (volatile int i = 0; i < 30; i++) {
                    t1 = ((lin90[4 * i + 0] & 0x3F) << 2) + ((lin90[4 * i + 1] & 0x30) >> 4);
                    t2 = ((lin90[4 * i + 1] & 0x0F) << 4) + ((lin90[4 * i + 2] & 0x3C) >> 2);
                    t3 = ((lin90[4 * i + 2] & 0x03) << 6) + ((lin90[4 * i + 3] & 0x3F) >> 0);
					lin90[4 * i + 0] = t1;
					lin90[4 * i + 1] = t2;
					lin90[4 * i + 2] = t3;
                }
                QVector<int16_t> ba;
                ba.resize(8*320);
                for (volatile int i = 0; i < 15; i++) {
                    codec2_decode(audiocodec,&ba[320*i],&lin90[6*i]);
                }
                emit WriteAudioData(ba);
				thinningSignal1.erase(thinningSignal1.begin(), thinningSignal1.begin() + 3024);
				thinningSignal2.erase(thinningSignal2.begin(), thinningSignal2.begin() + 3024);
				stateProc = 0;
			}
		}
		else {

		}
		//stateProc = 0;

	}
}

void RecieverData::addNewData(QVector<double> _vec) {
    double sample;
	complex_double analit_signal;
	complex_double cmplx;
	complex_double res[2];
	double average;
	double resD[2];
	//debugDataFile fileData;
	for (volatile int i = 0; i < _vec.size(); i++) {
		sample = _vec[i];

		

		analit_signal.im = Gilbert(sample);
		analit_signal.re = sample;
		
		//fileData.analitIm = analit_signal.im;
		//fileData.analitRe = analit_signal.re;

		for (volatile int k = 0; k < freqval.size(); k++) {
			getWave(k);
			complexMult(analit_signal,freqval[k].signal_freq,cmplx);


			memmove(&freqval[k].delayLine[1], &freqval[k].delayLine[0], (freqval[k].delayLine.size() - 1) * sizeof(complex_double));
			freqval[k].delayLine[0] = cmplx;

			res[k] = complexSum(freqval[k].delayLine);
			resD[k] = complexAbs(res[k]);
		}
		if (resD[1] > resD[0])
			average = 1;
		else
			average = -1;
		//average = resD[1] - resD[0];

		//fileData.adc = average;

		counterThinning++;
		if (counterThinning == 25) {
			thinningSignal1.push_back(average);
		}
		if (counterThinning >= 50) {
			thinningSignal2.push_back(average);
			counterThinning = 0;
		}
		//debugFileData.append(fileData);
		//cmplx = complexMult(analit_signal);
	}
	if (thinningSignal2.size() > 300) {
		processingThinData();
	}

}









