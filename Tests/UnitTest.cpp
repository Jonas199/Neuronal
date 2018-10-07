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

		TEST_METHOD(SetInputValue)
		{
			CNeuron *n = new CNeuron();
			n->setInputValue(0, 0.1, -1.1);
			Assert::AreEqual(-1.1,n->getWeight(0));
			Assert::AreEqual(0.1,n->getValue(0));
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
			n1->setInputValue(0,1.0,-1.0);
			n1->setInputValue(1,-1.0,1);
			n2->setInputValue(0,1.0,1.0);
			n2->setInputValue(1,-1.0,1);
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

	};

	TEST_CLASS(NetworkTests)
	{
	public:

		TEST_METHOD(CreateNetwork)
		{
			CNetwork *net = new CNetwork();
			Assert::IsNotNull(net);
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
			//TODO: Add Function to set Iterations
			Assert::IsFalse(true);
		}

		TEST_METHOD(AddLayer)
		{
			CNetwork *net = new CNetwork();
			CLayer *layer = new CLayer();
			net->addLayer(layer);
			Assert::IsFalse(net->getLayers().empty());
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



	};

}