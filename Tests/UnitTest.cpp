#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Neuronal\CMatrix.h"
#include "..\Neuronal\CMatrix.cpp"
#include "..\Neuronal\CNeuron.h"
#include "..\Neuronal\CNeuron.cpp"
#include "..\Neuronal\CInput.h"
#include "..\Neuronal\CInput.cpp"
#include "..\Neuronal\CLayer.h"
#include "..\Neuronal\CLayer.cpp"
#include "..\Neuronal\CNetwork.h"
#include "..\Neuronal\CNetwork.cpp"
#include "..\Neuronal\CRow.h"
#include "..\Neuronal\CRow.cpp"
#include "..\Neuronal\CTable.h"
#include "..\Neuronal\CTable.cpp"
#include "..\Neuronal\CSample.h"
#include "..\Neuronal\CSample.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(MatrixTests)
	{
	public:
		
		TEST_METHOD(CreateMatrix)
		{
			CMatrix *matrix = new CMatrix();
			Assert::IsNotNull(matrix);
		}

		TEST_METHOD(CreateMatrixWithColsAndRows)
		{
			CMatrix *matrix = new CMatrix(4,4);
			Assert::IsNotNull(matrix);
		}

		TEST_METHOD(getNrOfRows)
		{
			CMatrix *matrix = new CMatrix(2, 4);
			Assert::AreEqual(2,matrix->getNrOfRows());
		}

		TEST_METHOD(getNrOfCols)
		{
			CMatrix *matrix = new CMatrix(2, 4);
			Assert::AreEqual(4, matrix->getNrOfCols());
		}

		TEST_METHOD(SetMatrixToZero)
		{
			CMatrix *matrix = new CMatrix(4, 4);
			matrix->setMatrixToZero();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					Assert::AreEqual(0.0,matrix->getValue(i,j));
				}
			}
		}

		TEST_METHOD(AddMatrix)
		{
			CMatrix *matrix1 = new CMatrix(4, 4);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matrix1->setValue(i,j,1.0);
				}
			}
			CMatrix *matrix2 = new CMatrix(4, 4);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matrix2->setValue(i, j, 1.0);
				}
			}
			matrix1->addMatr(matrix2);

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					Assert::AreEqual(2.0, matrix1->getValue(i, j));
				}
			}
		}

		TEST_METHOD(MultMatrixWithFactor)
		{
			CMatrix *matrix1 = new CMatrix(4, 4);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matrix1->setValue(i, j, 1.0);
				}
			}
			
			matrix1->multWithFactor(1.5);

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					Assert::AreEqual(1.5, matrix1->getValue(i, j));
				}
			}
		}

	};

	TEST_CLASS(NeuronTests)
	{
	public:

		TEST_METHOD(CreateNeuron)
		{
			CNeuron *n = new CNeuron();
			Assert::IsNotNull(n);
		}

		TEST_METHOD(CheckIds)
		{
			CNeuron *n1 = new CNeuron();
			CNeuron *n2 = new CNeuron();
			CNeuron *n3 = new CNeuron();
			Assert::AreEqual(2, n1->getId());
			Assert::AreEqual(3, n2->getId());
			Assert::AreEqual(4, n3->getId());
		}

		TEST_METHOD(SetFactor)
		{
			CNeuron *n = new CNeuron();
			n->setFactor(0.1);
			Assert::AreEqual(0.1,n->getFactor());
		}


		TEST_METHOD(SetNrOfInputs)
		{
			CNeuron *n = new CNeuron();
			n->setNrOfInputs(2);
			Assert::AreEqual(2,n->getNrOfInputs());
		}

		TEST_METHOD(addInputValue)
		{
			CNeuron *n = new CNeuron();
			n->addInputValue(0, 0.1, -1.1);
			Assert::AreEqual(-1.1,n->getWeight(0));
			Assert::AreEqual(0.1,n->getValue(0));
		}

		TEST_METHOD(SetInput)
		{
			CNeuron *n = new CNeuron();
			n->setInput(0,20.5);
			Assert::AreEqual(20.5, n->getInput().at(0)->getValue());
			n->setInput(0, 20.4);
			Assert::AreEqual(20.4, n->getInput().at(0)->getValue());
			n->setInput(1, 2.4);
			Assert::AreEqual(2.4, n->getInput().at(1)->getValue());
			n->setInput(7, 2.6);
			Assert::AreEqual(2.6, n->getInput().at(2)->getValue());
		}


		TEST_METHOD(SetRelError)
		{
			CNeuron *n = new CNeuron();
			n->setRelError(0.2);
			Assert::AreEqual(0.2, n->getRelError());
		}

		TEST_METHOD(SetLayer)
		{
			CNeuron *n = new CNeuron();
			n->setLayer(5);
			Assert::AreEqual(5, n->getLayer());
		}

		TEST_METHOD(calculateOutput)
		{
			CNeuron *n1 = new CNeuron();
			CNeuron *n2 = new CNeuron();
			n1->addInputValue(0,1.0,-1.0);
			n1->addInputValue(1,-1.0,1);
			n2->addInputValue(0,1.0,1.0);
			n2->addInputValue(1,-1.0,1);
			Assert::AreEqual(0.12, (round(n1->calculateOutput() * 100) / 100) );
			Assert::AreEqual(0.5, (round(n2->calculateOutput() * 100) / 100));
		}

		TEST_METHOD(SetDelta)
		{
			CNeuron *n = new CNeuron();
			n->setDelta(0.2);
			Assert::AreEqual(0.2, n->getDelta());
		}
	};

	TEST_CLASS(LayerTests)
	{
	public:

		TEST_METHOD(CreateLayer)
		{
			CLayer *l = new CLayer();
			Assert::IsNotNull(l);
		}

		TEST_METHOD(AddNeuron)
		{
			CLayer *l = new CLayer();
			CNeuron *n = new CNeuron();
			l->addNeuron(n);
			Assert::AreEqual(n->getId(), l->getNeurons().at(0)->getId());
		}

		TEST_METHOD(CHeckId)
		{
			CLayer *l1 = new CLayer();
			CLayer *l2 = new CLayer();
			Assert::AreEqual(2, l1->getId());
			Assert::AreEqual(3, l2->getId());
		}

		TEST_METHOD(InputsPerNeuron)
		{
			CLayer *l1 = new CLayer();
			Assert::AreEqual(-1,l1->getNrOfInputsPerNeuron());
		}

		TEST_METHOD(SetInputs)
		{
			vector <double> output = {0.2,0.5};
			CLayer *l1 = new CLayer();
			auto *n1 = new CNeuron();
			auto *n2 = new CNeuron();
			l1->addNeuron(n1);
			l1->addNeuron(n2);
			l1->setInputs(output);
			for (int i = 0; i < output.size();i++) {
				Assert::AreEqual(output.at(i),l1->getNeurons().at(0)->getValue(i));
			}
			for (int i = 0; i < output.size(); i++) {
				Assert::AreEqual(output.at(i), l1->getNeurons().at(1)->getValue(i));
			}
		}

		TEST_METHOD(GetOutputs)
		{
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
			Assert::AreEqual(0.12, (round(outputs1.at(0) * 100) / 100));
			Assert::AreEqual(0.5, (round(outputs1.at(1) * 100) / 100));
			CLayer *l2 = new CLayer();
			auto *n3 = new CNeuron();
			auto *n4 = new CNeuron();
			n3->addInputValue(0, outputs1.at(0), 1.0);
			n3->addInputValue(1, outputs1.at(1), 1);
			n4->addInputValue(0, outputs1.at(0), -1.0);
			n4->addInputValue(1, outputs1.at(1), 1);
			l2->addNeuron(n3);
			l2->addNeuron(n4);
//			vector <double> outputs2 = l2->getOutputs();
//			Assert::AreEqual(size_t(2),outputs2.size());
			/*Assert::AreEqual(0.65, (round(outputs2.at(0) * 100) / 100));
			Assert::AreEqual(0.59, (round(outputs2.at(1) * 100) / 100));*/
			Assert::AreEqual(0.65, (round(l2->getOutputs().at(0) * 100) / 100));
			Assert::AreEqual(0.59, (round(l2->getOutputs().at(1) * 100) / 100));
		}

		TEST_METHOD(CalculateRelErrOfLayer)
		{
			auto *net = new CNetwork();
			vector <double> target = { 1,0 };
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
			//n3->setRelError(0.0796);
			//n4->setRelError(-0.1427);
			l2->addNeuron(n3);
			l2->addNeuron(n4);
			vector <double> outputs2 = l2->getOutputs();
			net->addLayer(l1);
			net->addLayer(l2);
			net->calculateRelError(1);
			net->calculateRelError(0);
			Assert::AreEqual(-0.02, (round(net->getLayers().at(0)->getNeurons().at(0)->getRelError() * 100) / 100));
			Assert::AreEqual(0.02, (round(net->getLayers().at(0)->getNeurons().at(1)->getRelError() * 100) / 100));
		}



	};

	TEST_CLASS(NetworkTests)
	{
	public:

		TEST_METHOD(CreateNetwork)
		{
			CNetwork *net = new CNetwork();
			Assert::IsNotNull(net);
		}

		TEST_METHOD(CreateTestNetwork)
		{
			CNetwork *net = new CNetwork();
			net->setNumberOfLayers(4);
			net->setNumberOfNeuronsPerLayer(4);
			vector <double> inputs = {0.9,3.2,-3.3,8.7};
			for (int i = 0; i < net->getNumberOfLayers(); i++) {
				net->addLayer(new CLayer());
			}
			for (int i = 0; i < net->getNumberOfLayers(); i++) {
				for (int j = 0; j < net->getNumberOfNeuronsPerLayer(); j++) {
					net->getLayers().at(i)->addNeuron(new CNeuron());
				}
			}
			net->getLayers().at(0)->setInputs(inputs);
			for (int i = 1; i < net->getNumberOfLayers(); i++) {
				vector <double> out = net->getLayers().at(i-1)->getOutputs();
				net->getLayers().at(i)->setInputs(out);
			}

		}

		TEST_METHOD(SetNumberOfInputs)
		{
			CNetwork *net = new CNetwork();
			net->setNumberOfInputs(3);
			Assert::AreEqual(3,net->getNumberOfInputs());
		}

		TEST_METHOD(SetNumberOfTargets)
		{
			CNetwork *net = new CNetwork();
			net->setNumberOfTargets(3);
			Assert::AreEqual(3, net->getNumberOfTargets());
		}

		TEST_METHOD(SetNumberOfLayers)
		{
			CNetwork *net = new CNetwork();
			net->setNumberOfLayers(3);
			Assert::AreEqual(3, net->getNumberOfLayers());
		}

		TEST_METHOD(SetNumberOfNeuronsPerLayer)
		{
			CNetwork *net = new CNetwork();
			net->setNumberOfNeuronsPerLayer(3);
			Assert::AreEqual(3, net->getNumberOfNeuronsPerLayer());
		}

		TEST_METHOD(SetNumberOfIterations)
		{
			CNetwork *net = new CNetwork();
			net->setNumberOfIterations(100);
			Assert::AreEqual(100,net->getNumberOfIterations());
		}

		TEST_METHOD(AddLayer)
		{
			CNetwork *net = new CNetwork();
			CLayer *layer = new CLayer();
			net->addLayer(layer);
			Assert::IsFalse(net->getLayers().empty());
		}

		TEST_METHOD(DeleteLayer)
		{
			CNetwork *net = new CNetwork();
			CLayer *layer = new CLayer();
			net->addLayer(layer);
			net->deleteLayer(0);
			Assert::IsTrue(net->getLayers().empty());
		}

		TEST_METHOD(CreateWeightMatrixforLayer)
		{
			CNetwork *net = new CNetwork();
			CLayer *l1 = new CLayer();
			CNeuron *n1 = new CNeuron();
			CNeuron *n2 = new CNeuron();
			l1->addNeuron(n1);
			l1->addNeuron(n2);
			CLayer *l2 = new CLayer();
			CNeuron *n3 = new CNeuron();
			CNeuron *n4 = new CNeuron();
			l2->addNeuron(n3);
			l2->addNeuron(n4);
			net->addLayer(l1);
			net->addLayer(l2);
			net->createWeightMatrix(2);
			Assert::IsFalse(true);
		}

		TEST_METHOD(UpdateWeights)
		{
			CNetwork *net = new CNetwork();
			//TODO: Add Function to calculate weight of a layer 
			Assert::IsFalse(true);
		}

		TEST_METHOD(CalculateRelErrors)
		{
			CNetwork *net = new CNetwork();
			//TODO: Add Function to calculate rel. Error of a layer 
			Assert::IsFalse(true);
		}

		TEST_METHOD(CalculateDelta)
		{
			CNetwork *net = new CNetwork();
			//TODO: Add Function to calculate Delta of a layer 
			Assert::IsFalse(true);
		}

		TEST_METHOD(CalculateOutputOfLayer)
		{
			CNetwork *net = new CNetwork();
			//TODO: Add Function to calculate Output of a layer into a vector 
			Assert::IsFalse(true);
		}

		TEST_METHOD(CalculateAccuracy)
		{
			CNetwork *net = new CNetwork();
			//TODO: Add Function to calculate Accuracy of the network by comparing prediction and target 
			Assert::IsFalse(true);
		}

		TEST_METHOD(GenerateTestNetwork)
		{
			auto net = new CNetwork();
			auto testNet = net->generateTestNetwork();
			Assert::AreEqual(size_t(2), testNet->getLayers().size());
		}

		TEST_METHOD(StartTrainingTest)
		{
			auto net = new CNetwork();
			for (int l = 0; l < 2; l++) {
				auto layer = new CLayer();
				for (int i = 0; i < 2; i++) {
					auto neuron = new CNeuron();
					layer->addNeuron(neuron);
				}
				net->addLayer(layer);
			}
			CSample *sample = net->generateTestSample();
			net->setTrainingSamples(sample);
			net->startTraining();
			Assert::IsFalse(true);
		}

		TEST_METHOD(ImportFromCSV)
		{
			auto net = new CNetwork();
			net->getSampleFromCSV();
			Assert::IsFalse(true);
		}

	};
	TEST_CLASS(SampleTests)
	{
	public:
		TEST_METHOD(CreateSample)
		{
			auto sampl = new CSample();
			Assert::IsNotNull(sampl);
		}

		TEST_METHOD(CreateTestSample)
		{
			auto net = new CNetwork();
			CSample *sample = net->generateTestSample();
			auto row = sample->getInput()->getRow(10);
			Assert::IsNotNull(row);
			Assert::AreEqual(10.0,row->getValues().at(0));
			row = sample->getTarget()->getRow(10);
			Assert::AreEqual(40.0, row->getValues().at(0));
		}
	};

}