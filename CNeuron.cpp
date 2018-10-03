#include "stdafx.h"
#include "CNeuron.h"
#include <iostream>
#include <Array>

using namespace std;

CNeuron::CNeuron()
{
	output = 0.0;
	state = 1;
	this->thisId = id;
	id++;
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

void CNeuron::setNrOfInputs(){
}

void CNeuron::setInputs(vector <CInput*> inputs){
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

int CNeuron::getId()
{
	return this->thisId;
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
int CNeuron::id = 0;