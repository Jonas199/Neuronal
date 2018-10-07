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
	int id;
	double output;
	int state;
	int nrOfInputs;
	int layer;
	double relError;
	double factor;
	double delta;
	vector <CInput*> inputList;
public:
	void activate();
	void deactivate();
	void setInputValue(int _inputNr, double _value, double _weight);
	double calculateOutput();
	int getNrOfInputs();
	void setNrOfInputs(int n);
	void setInputs(vector <CInput*> inputs);
	void UpdateWeights();
	void setRelError(double err);
	void setFactor(double f);
	vector <CInput*> getInput();
	double getRelError();
	double getFactor();
	double getWeight(int inputNr);
	void setLayer(int _layer);
	int getLayer();
	double getValue(int inputNr);
	double getDelta();
	void setDelta(double delta);
	int getId();


	void printAll();

};

