#include "pch.h"
#include "CNetwork.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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
	for (double i = 1; i < 100; i+=5) {
		//auto inputValues = new CRow({i*0.01,i*0.01 +0.1,i*0.01 +0.2});
		auto inputValues = new CRow({ i/1000+0.01,0.01 + 0.1,0.01 +0.2 });
		auto targetValues = new CRow({1,0});
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
	n1->addInputValue(0, 1.0, -1.0);
	n1->addInputValue(1, -1.0, 1);
	n2->addInputValue(0, 1.0, 1.0);
	n2->addInputValue(1, -1.0, 1);
	l1->addNeuron(n1);
	l1->addNeuron(n2);
	vector <double> outputs1 = l1->getOutputs();
	CLayer *l2 = new CLayer();
	auto *n3 = new CNeuron();
	auto *n4 = new CNeuron();
	n3->addInputValue(0, outputs1.at(0), 1.0);
	n3->addInputValue(1, outputs1.at(1), 1);
	n4->addInputValue(0, outputs1.at(0), -1.0);
	n4->addInputValue(1, outputs1.at(1), 1);
	l2->addNeuron(n3);
	l2->addNeuron(n4);
	vector <double> outputs2 = l2->getOutputs();
	net->addLayer(l1);
	net->addLayer(l2);
	return net;
}

void CNetwork::setTestSamples(CSample * sampl)
{
	this->test_samples = sampl;
}

void CNetwork::setTrainingSamples(CSample * sampl)
{
	this->training_samples = sampl;
}

CSample * CNetwork::getTestSamples()
{
	return this->test_samples;
}

CSample * CNetwork::getTrainingSamples()
{
	return this->training_samples;
}

void CNetwork::startTraining(int cycles)
{
	CTable *inputTable = this->getTrainingSamples()->getInput();
	int iterations = inputTable->getNrOfRows();
	for (int p = 0; p < cycles; p++) {
		for (int i = 0; i < iterations; i++) {
			int nrOfInp = this->training_samples->getInput()->getRow(0)->getNrOfCols();
			vector <double> inp; inp.resize(nrOfInp);
			inp = this->training_samples->getInput()->getRow(i)->getValues();
			this->getLayers().at(0)->setInputs(inp);
			int nrOfTar = this->training_samples->getTarget()->getRow(0)->getNrOfCols();
			vector <double> tar; tar.resize(nrOfTar);
			tar = this->training_samples->getTarget()->getRow(i)->getValues();
			this->setTarget(&tar);
			for (int i = 0; i < this->getLayers().size(); i++) {
				vector <double> out = this->getLayers().at(i)->getOutputs();
				//for (int n = 0; n < out.size(); n++) {
				//	cout << out.at(n) << " , ";
				//}
				//cout << endl;
				if (i < this->getLayers().size() - 1) {
					this->getLayers().at(i + 1)->setInputs(out);
				}
			}
			for (int j = this->getLayers().size(); j > 0; j--) {
				this->calculateRelError(j - 1);
				for (int n = 0; n < this->getLayers().at(j - 1)->getNeurons().size(); n++) {
					this->getLayers().at(j - 1)->getNeurons().at(n)->UpdateWeights();
				}
			}
		}
		cout << ".";
	/*	cout<< "example weight_1: " << this->layer.at(1)->getNeurons().at(0)->getInput().at(0)->getWeight()<<endl;
		cout <<	"example weight_2: " << this->layer.at(0)->getNeurons().at(1)->getInput().at(1)->getWeight() << endl;*/
	}
}

void CNetwork::startTesting()
{
	double vals = 0;
	double errors = 0;
	double success = 0;
	CTable *inputTable = this->test_samples->getInput();
	int iterations = inputTable->getNrOfRows();
			for (int i = 0; i < iterations; i++) {
			int nrOfInp = this->test_samples->getInput()->getRow(0)->getNrOfCols();
			vector <double> inp; inp.resize(nrOfInp);
			inp = this->test_samples->getInput()->getRow(i)->getValues();
			this->getLayers().at(0)->setInputs(inp);
			int nrOfTar = this->test_samples->getTarget()->getRow(0)->getNrOfCols();
			vector <double> tar; tar.resize(nrOfTar);
			tar = this->test_samples->getTarget()->getRow(i)->getValues();
			this->setTarget(&tar);
			for (int i = 0; i < this->getLayers().size(); i++) {
				vector <double> out = this->getLayers().at(i)->getOutputs();
				if (i < this->getLayers().size() - 1) {
					this->getLayers().at(i + 1)->setInputs(out);
				}
				if (i == this->getLayers().size()-1) {
					for (int n = 0; n < this->getLayers().at(i)->getNeurons().size(); n++) {
						vals++;
						double out_rounded = (round(out.at(n) * 10)) / 10;
						if (out_rounded == round(target->at(n)*10)/10) {
							success++;
						}
						else {
							errors++;
						}
					}
				}
			}
	}
			this->accuracy = success / vals;
			cout << "suc: " << success << endl;
			cout << "vals: " << vals << endl;
}

double CNetwork::getAccuracy()
{
	//Compare output of test samples and targets
	return this->accuracy;
}

CSample * CNetwork::getSampleFromCSV(const char *filename)
{
	int nrOfInputs = 0;
	int nrOfTargets = 0;
	int lines = 0;
	auto result = new CSample();
	auto inputs = new CTable();
	auto targets = new CTable();
	vector<double> in;
	vector <double> ou;
	ifstream csvread;
	csvread.open(filename,ios::in);
	if (csvread) {
		//Datei bis Ende einlesen und bei ';' strings trennen
		string line;
		while(getline(csvread, line))
		{
			if (lines < 1) {
				//cout << line << endl; //print line
				istringstream s(line);
				string f = "";
				while (getline(s, f, ';')) {
					char identifier = f.at(0);
					if ((identifier > 64) && (identifier < 91)) {
						nrOfInputs++;
					}
					if ((identifier > 96) && (identifier < 123)) {
						nrOfTargets++;
					}
				}
				lines++;
				in.resize(nrOfInputs);
				ou.resize(nrOfTargets);
			}
			else {
				istringstream s(line);
				string f = "";
				for (int i = 0; i < nrOfInputs; i++) {
					getline(s, f, ';');
					in.at(i) = stod(f);
				}
				for (int i = 0; i < nrOfTargets; i++) {
					getline(s, f, ';');
					ou.at(i) = stod(f);
				}
				auto ip = new CRow(in);
				auto op = new CRow(ou);
				inputs->addRow(ip);
				targets->addRow(op);
			}
			//Todo:  Wenn s -> char im ASCII Bereich von A bis Z liegt nrOfInputs++
			//Wenn s im Bereich a z liegt nrOfTargets++
			//vector<double> inputs
			//vector <double> outputs
			//inputs.resize(nrOfInputs); outputs.resize(nrOfOutputs);
			//for(int i = 0 ; i<nrOfInputs){input table -> addRow()}
			//for(int i = 0; i < nrOfOutputs;i++){target table -> addRow()}
		}

		csvread.close();
	}
	else {
		cerr << "Fehler beim Lesen!" << endl;
	}
	result->setInput(inputs);
	result->setTarget(targets);
	return result;
}

