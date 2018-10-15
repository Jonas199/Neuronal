#include "pch.h"
#include "CSample.h"



CSample::CSample()
{
	inputs = 0;
	targets = 0;
	values = 0;
}

CSample::CSample(int _inputs, int _targets)
{
	inputs = _inputs;
	targets = _targets;
	values = 0;
}

CSample::~CSample()
{
}

void CSample::setInput(CTable * _input)
{
	this->input = _input;
}

void CSample::setTarget(CTable * _target)
{
	this->target = _target;
}

int CSample::getValues()
{
	return this->input->getNrOfRows();
}

CTable *CSample::getInput()
{
	return this->input;
}

CTable *CSample::getTarget()
{
	return this->target;
}
