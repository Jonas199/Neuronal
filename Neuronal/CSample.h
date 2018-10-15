#pragma once
#include "CTable.h"

class CSample
{
public:
	CSample();
	CSample(int _inputs, int _targets);
	~CSample();
	void setInput(CTable * _input);
	void setTarget(CTable *_target);
	int getValues();
	CTable *getInput();
	CTable *getTarget();
private:
	int inputs;
	int targets;
	int values;
	CTable *input;
	CTable *target;
};

