#include "pch.h"
#include "CLayer.h"


CLayer::CLayer()
{
	static int anzahl = 0;
	nrOfNeurons = 0;
	nrOfInputsPerNeuron = 0;
	this->id = anzahl;
	anzahl++;
}


CLayer::~CLayer()
{
}


int CLayer::addNeuron(CNeuron *neuron)
{
	this->neurons.push_back(neuron);
	this->nrOfNeurons++;
	return 0;
}


int CLayer::deleteNeuron()
{
	// TODO: F�gen Sie hier Ihren Implementierungscode ein..
	return 0;
}

void CLayer::setLayerNr(int _layerNr)
{
	this->layerNr = _layerNr;
}

int CLayer::getLayerNr()
{
	return this->layerNr;
}

void CLayer::setNrOfInputsPerNeuron(int nr)
{
	this->nrOfInputsPerNeuron = nr;
}

int CLayer::getNrOfInputsPerNeuron() {
	return this->nrOfInputsPerNeuron;
}

int CLayer::getNrOfNeurons() {
	return this->nrOfNeurons;
}

void CLayer::setNrOfNeurons(int _nrOfNeurons) {
	this->nrOfNeurons = _nrOfNeurons;
}

vector<CNeuron*> CLayer::getNeurons()
{
	return this->neurons;
}

vector<double> CLayer::getOutputs()
{
	vector<double> out;
	for (int i = 0; i < this->getNeurons().size(); i++) {
		out.push_back(this->getNeurons().at(i)->calculateOutput());
	}
	this->outputs = out;
	return out;
}

void CLayer::setInputs(vector<double> inputs)
{
	for (int i = 0; i < this->getNeurons().size();i++) {
		//this->getNeurons().at(i)->setNrOfInputs(inputs.size());
		for (int j = 0; j < inputs.size(); j++) {
			this->getNeurons().at(i)->setInput(j,inputs.at(j));
		}
	}
}

void CLayer::printOutputs() {
	cout << "Layer Nr: "<<this->getLayerNr()<<endl;
	cout << "Nr of Inputs / Neuron: " << this->getNrOfInputsPerNeuron() << endl;
	cout << "Nr of Neurons in this layer: " << this->getNrOfNeurons() << endl;
	int i = 1;
	vector<CNeuron*>::iterator pos;
	
	//Loop for each Neuron
	for (pos = this->getNeurons().begin(); pos != this->getNeurons().end(); pos++) {
		cout<<"Output Nr. "<<i<<": "<<(*pos)->calculateOutput()<<endl;
		i++;
	}
	
}

int CLayer::getId()
{
	return  this->id;
}
