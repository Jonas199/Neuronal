#include "CLayer.h"
#include "vector"
#include "CSample.h"
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
	CSample* training_samples;
	CSample* test_samples;
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
	CSample* generateTestSample();
	CNetwork* generateTestNetwork();
	void setTestSamples(CSample *sampl);
	void setTrainingSamples(CSample *sampl);
	CSample *getTestSamples();
	CSample *getTrainingSamples();
	void startTraining(int cycles);
	void startTesting();
	double getAccuracy();
	CSample* getSampleFromCSV( const char *filename);
};

