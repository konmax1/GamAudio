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
	freqDiskr = 300000;
    freqSignal = 6000;
	freqval.resize(2);
	freqval[0].freqWave = 36000;
    freqval[0].delayLine.resize(freqDiskr/freqSignal);
    freqval[1].freqWave = 39000;
    freqval[1].delayLine.resize(freqDiskr/freqSignal);
	counterThinning = 0;
	delayLine.resize(GILBERT_POR + 1, 0);
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

void RecieverData::addNewData(QVector<double> _vec) {
    double sample;
	complex_double analit_signal;
	complex_double cmplx;
	complex_double res[2];
	double average;
	double resD[2];
	debugDataFile fileData;
	for (volatile int i = 0; i < _vec.size(); i++) {
		sample = _vec[i];

		

		analit_signal.im = Gilbert(sample);
		analit_signal.re = sample;
		
		fileData.analitIm = analit_signal.im;
		fileData.analitRe = analit_signal.re;

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
			average = 0;
		//average = resD[1] - resD[0];

		fileData.adc = average;

		counterThinning++;
		if (counterThinning == 25) {
			thinningSignal.append(average);
		}
		if (counterThinning >= 50) {
			thinningSignal.append(average);
			counterThinning = 0;
		}
		debugFileData.append(fileData);
		//cmplx = complexMult(analit_signal);
	}

}









