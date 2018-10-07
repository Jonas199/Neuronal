#include "pch.h"
#include "CInput.h"


CInput::CInput()
{
	value = 0.0;
	number = 0;
	weight = 0.0;
}

CInput::CInput(double _val, int _num, double _weight)
{
	value = _val;
	number = _num;
	weight = _weight;
}

CInput::~CInput()
{
}


double CInput::getWeight()
{
	// TODO: Fügen Sie hier Ihren Implementierungscode ein..
	return this->weight;
}


void CInput::setWeight(double _weight)
{
	// TODO: Fügen Sie hier Ihren Implementierungscode ein..
	this->weight = _weight;
}

double CInput::getValue() {
	return value;
}

void CInput::setValue(double _value) {
	value = _value;
}

void CInput::setNumber(int _number)
{
	number = _number;
}

int CInput::getNumber() {
	return number;
}
