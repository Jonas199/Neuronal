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
	static int id;
	int thisId;
	double output;
	int state;
	int nrOfInputs;
	int layer;
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
	void setLayer(int _layer);
	int getLayer();
	//void setId(int _Id);
	int getId();


	void printAll();

};

