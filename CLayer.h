#include "CNeuron.h"
#include <iostream>
#include "vector"

#pragma once

using namespace std;

class CLayer
{
public:
	CLayer();
	~CLayer();
private:
	int layerId;
	int nrOfNeurons;
	int nrOfInputsPerNeuron; // = Number of Neurons in last Layer
	int layer;
	double **weights;
	vector <CNeuron*> neurons;
	vector <double> outputs;

public:
	int addNeuron(CNeuron *neuron);
	int deleteNeuron();
	void setLayerNr(int layerNr);
	int getLayerNr();
	void setNrOfInputsPerNeuron(int nr);
	int getNrOfInputsPerNeuron();
	int getNrOfNeurons();
	void setNrOfNeurons(int _nrOfNeurons);
	vector <CNeuron*> getNeurons();
	vector <double> getOutputs();
	void printOutputs();

};

