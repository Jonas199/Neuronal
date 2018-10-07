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
	int iterations;
public:
	CNetwork();
	~CNetwork();
	void addLayer(CLayer *layer);
	int deleteLayer();
	vector<CLayer*> getLayers();
	double calculateOutput(int _nr);
	void setLayerInputs(CLayer* layer);
	void setNumberOfInputs(int inputs);
	void setNumberOfTargets(int targets);
	int getNumberOfInputs();
	int getNumberOfTargets();
	void setNumberOfLayers(int layer);
	void setNumberOfNeuronsPerLayer(int nrOfNeurons);
	int getNumberOfLayers();
	int getNumberOfNeuronsPerLayer();
};

