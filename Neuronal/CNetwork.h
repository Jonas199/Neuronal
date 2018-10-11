#include "CLayer.h"
#include "vector"
#pragma once

using namespace std;

class CNetwork
{
private:
	vector <CLayer*> layer;
	int nrOfLayers;
	int nrOfNeuronsPerLayer;
	int inputs;
	int targets;
	int nrOfIterations;
	double accuracy;
	int test_targets;
	vector <double> *target;
public:
	CNetwork();
	~CNetwork();
	void addLayer(CLayer *layer);
	void deleteLayer(int layerNr);
	vector<CLayer*> getLayers();
	double calculateOutput(int _layerNr);
	void setLayerInputs(CLayer* layer);
	void setNumberOfInputs(int inputs);
	void setNumberOfTargets(int targets);
	int getNumberOfInputs();
	int getNumberOfTargets();
	void setNumberOfLayers(int layer);
	void setNumberOfNeuronsPerLayer(int nrOfNeurons);
	int getNumberOfLayers();
	int getNumberOfNeuronsPerLayer();
	void setNumberOfIterations(int _nr);
	int getNumberOfIterations();
	vector <double> calculateOutputOfLayer(int layer);
	void setTarget(vector <double> *t);
	void calculateDeltas(int layer);
	void calculateRelError(int layer);
	void createWeightMatrix(int layerNr);
};

