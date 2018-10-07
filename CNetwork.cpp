#include "pch.h"
#include "CNetwork.h"


CNetwork::CNetwork()
{
	this->nrOfLayers = 0;

}


CNetwork::~CNetwork()
{
}


void CNetwork::addLayer(CLayer *layer)
{

}


int CNetwork::deleteLayer()
{
	// TODO: Fügen Sie hier Ihren Implementierungscode ein..
	return 0;
}

vector<CLayer*> CNetwork::getLayers() {
	return this->layer;
}

double CNetwork::calculateOutput(int _nr) {
	return 0;
}

void CNetwork::setLayerInputs(CLayer* layer) {
	
	
}

void CNetwork::setNumberOfInputs(int _inputs)
{
	this->inputs = _inputs;
}

void CNetwork::setNumberOfTargets(int _targets)
{
	this->targets = _targets;
}

int CNetwork::getNumberOfInputs()
{
	return this->inputs;
}

int CNetwork::getNumberOfTargets()
{
	return this->targets;
}

void CNetwork::setNumberOfLayers(int _layer)
{
	this->nrOfLayers = _layer;
}

void CNetwork::setNumberOfNeuronsPerLayer(int _nrOfNeur)
{
	this->nrOfNeuronsPerLayer = _nrOfNeur;
}

int CNetwork::getNumberOfLayers()
{
	return this ->nrOfLayers;
}

int CNetwork::getNumberOfNeuronsPerLayer()
{
	return this->nrOfNeuronsPerLayer;
}
