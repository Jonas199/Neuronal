#include "pch.h"
#pragma once
class CInput
{
public:
	CInput();
	CInput(double _val, int num, double _weight);
	~CInput();
private:
	double value;
	int number;
	double weight;
public:
	double getWeight();
	double getValue();
	int getNumber();
	void setWeight(double _weight);
	void setValue(double _value);
	void setNumber(int _number);
};

