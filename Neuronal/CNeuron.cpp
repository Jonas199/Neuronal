#include "pch.h"
#include "CNeuron.h"
#include <iostream>
#include <Array>

using namespace std;

CNeuron::CNeuron()
{
	static int anzahl = 0;
	output = 0.0;
	factor = 0.1;
	state = 1;
	this->id = anzahl;
	anzahl++;
}


CNeuron::~CNeuron()
{
}


void CNeuron::activate()
{
	// TODO: Fügen Sie hier Ihren Implementierungscode ein..
	this->state = 1;

}


void CNeuron::deactivate()
{
	// TODO: Fügen Sie hier Ihren Implementierungscode ein..
	this->state = 0;

}

void CNeuron::setInputValue(int _inputNr, double _value, double _weight){
	this->inputList.push_back(new CInput(_value, _inputNr,_weight));
}

double CNeuron::calculateOutput(){
	double sum = 0.0;
	// Iterator anlegen
	vector<CInput*>::iterator pos;
	for (pos = inputList.begin(); pos != inputList.end(); pos++) {
		sum += (*pos)->getValue() * (*pos)->getWeight();
	}
	return 1 / (1 + exp(-1 * sum));
}

int CNeuron::getNrOfInputs(){
	return this->inputList.size();
}

void CNeuron::setNrOfInputs(int n){
	this->nrOfInputs = n;
	this->inputList.resize(n);
}

void CNeuron::setInputs(vector <CInput*> inputs){
	this->inputList = inputs;
}

void CNeuron::UpdateWeights(){
	for (int i = 0; i < this->inputList.size(); i++){
		double w = inputList.at(i)->getWeight();
		inputList.at(i)->setWeight(w + this->relError*factor*inputList.at(i)->getValue());
	}

}
void CNeuron::setRelError(double err){
	this->relError = err;
}

void CNeuron::setFactor(double f){
	this->factor = f;
}

vector<CInput*> CNeuron::getInput()
{
	return this->inputList;
}

double CNeuron::getRelError(){
	return this->relError;
}

double CNeuron::getFactor(){
	return this->factor;
}

double CNeuron::getWeight(int inputNr){
	return this->inputList.at(inputNr)->getWeight();
}

void CNeuron::setLayer(int _layer)
{
	this->layer = _layer;

}

int CNeuron::getLayer()
{
	return this->layer;
}

double CNeuron::getValue(int inputNr)
{
	return this->inputList.at(inputNr)->getValue();
}

double CNeuron::getDelta()
{
	return this->delta;
}
void CNeuron::setDelta(double delta)
{
	this->delta = delta;
}
int CNeuron::getId()
{
	return this->id;
}



void CNeuron::printAll(){
	cout << "\n---NEURON VALUES:---"  << endl;
	cout << "id: " << this->getId() << endl;
	cout << "layer: " << this->getLayer() << endl;
	cout << "factor: " << this->getFactor() << endl;
	cout << "nr of inputs: " << this->getNrOfInputs() << endl;
	cout << "rel. error: " << this->getRelError() << endl;
	cout << "output: " << this->calculateOutput() << endl;
	cout << "INPUTS: " << endl;
	for (int i = 0; i < this->inputList.size(); i++){
		cout << "nr: " << this->inputList.at(i)->getNumber()<<endl;
		cout << "value: " << this->inputList.at(i)->getValue() << endl;
		cout << "weight: " << this->inputList.at(i)->getWeight() << endl;
		cout << endl;
	}
}

void CNeuron::setInput(int inputNr, double in)
{
	this->inputList.at(inputNr)->setValue(in);
}
