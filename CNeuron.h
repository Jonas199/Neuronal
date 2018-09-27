#include "stdafx.h"
#include "vector"
#include "CInput.h"
#pragma once

using namespace std;

class CNeuron
{
public:
	CNeuron();
	~CNeuron();

private:
	double output;
	int state;
	int nrOfInputs;
	double relError;
	double factor;
	vector <CInput*> inputList;
public:
	void activate();
	void deactivate();
	void setInputValue(int _inputNr, double _value, double _weight);
	double calculateOutput();
	int getNrOfInputs();
	void setNrOfInputs();
	void setInputs(vector <CInput*> inputs);
	void UpdateWeights();
	void setRelError(double err);
	void setFactor(double f);
	double getRelError();
	double getFactor();
	double getWeight(int inputNr);
	void printAll();

};

