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
	this->layer.push_back(layer);
}


void CNetwork::deleteLayer(int layerNr)
{
	this->layer.erase(this->layer.begin()+layerNr);
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

void CNetwork::setNumberOfIterations(int _nr)
{
	this->nrOfIterations = _nr;
}

int CNetwork::getNumberOfIterations()
{
	return this->nrOfIterations;
}

vector<double> CNetwork::calculateOutputOfLayer(int layer)
{
	vector <double> result;
	CLayer *l = this->layer.at(layer);
	for (int i = 0; i < l->getNrOfNeurons(); i++) {
		result.push_back(l->getNeurons().at(i)->calculateOutput());
	}
	return result;
}

void CNetwork::setTarget(vector<double> *t)
{
	this->target = t;
}

void CNetwork::calculateDeltas(int layer)
{

}

void CNetwork::calculateRelError(int layer)
{
	if (layer < this->getLayers().size()-1) {
		double h_n = 0;
		double relErrNext = 0;
		double relErr = 0;
		double w_rel_sum = 0;
		for (int n = 0; n < this->getLayers().at(layer)->getNeurons().size(); n++) {
		w_rel_sum = 0;
			for (int i = 0; i < this->getLayers().at(layer+1)->getNeurons().size(); i++) {
				relErrNext = this->getLayers().at(layer + 1)->getNeurons().at(i)->getRelError();
				w_rel_sum = w_rel_sum + (this->getLayers().at(layer+1)->getNeurons().at(i)->getWeight(n)*relErrNext);
			}
			h_n = this->getLayers().at(layer )->getNeurons().at(n)->calculateOutput();
			relErr = h_n * (h_n - 1)*w_rel_sum;
			this->getLayers().at(layer)->getNeurons().at(n)->setRelError(relErr);
		}
	}
	else {
		for (int i = 0; i < this->target->size(); i++) {
			double y = this->getLayers().at(layer)->getNeurons().at(i)->calculateOutput();
			double relErr = y * (1 - y)*(this->target->at(i)-y);
			this->getLayers().at(layer)->getNeurons().at(i)->setRelError(relErr);
		}
	}

}

void CNetwork::createWeightMatrix(int layerNr)
{

}

CSample* CNetwork::generateTestSample()
{
	auto sample = new CSample();
	auto input = new CTable();
	auto target = new CTable();
	for (double i = 0; i < 100; i++) {
		auto inputValues = new CRow({i,i+1,i+2});
		auto targetValues = new CRow({(i*4),(i*(i + 1)*(i + 2))});
		input->addRow(inputValues);
		target->addRow(targetValues);
	}
	sample->setInput(input);
	sample->setTarget(target);
	return sample;
}

CNetwork * CNetwork::generateTestNetwork()
{
	auto *net = new CNetwork();
	vector <double> target = { 0,1 };
	net->setTarget(&target);
	CLayer *l1 = new CLayer();
	auto *n1 = new CNeuron();
	auto *n2 = new CNeuron();
	n1->setInputValue(0, 1.0, -1.0);
	n1->setInputValue(1, -1.0, 1);
	n2->setInputValue(0, 1.0, 1.0);
	n2->setInputValue(1, -1.0, 1);
	l1->addNeuron(n1);
	l1->addNeuron(n2);
	vector <double> outputs1 = l1->getOutputs();
	CLayer *l2 = new CLayer();
	auto *n3 = new CNeuron();
	auto *n4 = new CNeuron();
	n3->setInputValue(0, outputs1.at(0), 1.0);
	n3->setInputValue(1, outputs1.at(1), 1);
	n4->setInputValue(0, outputs1.at(0), -1.0);
	n4->setInputValue(1, outputs1.at(1), 1);
	l2->addNeuron(n3);
	l2->addNeuron(n4);
	vector <double> outputs2 = l2->getOutputs();
	net->addLayer(l1);
	net->addLayer(l2);
	return net;
}
