// Neuronal.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "CNeuron.h"
#include <iostream>


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double t1 = 1;
	double t2 = 0;
	double w = 0;
	double n = 0.1;

	CNeuron *n1 = new CNeuron();
	n1->setInputValue(0, 1, -1);
	n1->setInputValue(1,-1,1);
	n1->setFactor(n);
	CNeuron *n2 = new CNeuron();
	n2->setInputValue(0, 1, 1);
	n2->setInputValue(1, -1, 1);
	n2->setFactor(n);

	for (int i = 0; i < 1000; i++){
		double y1 = n1->calculateOutput();
		n1->setRelError(y1*(1 - y1)*(t1 - y1));
		n1->UpdateWeights();
		n1->printAll();
		double y2 = n2->calculateOutput();
		n2->setRelError(y2*(1 - y2)*(t2 - y2));
		n2->UpdateWeights();
		n2->printAll();
	}
	return 0;
}

