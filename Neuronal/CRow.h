#pragma once
#include "vector"

using namespace std;

class CRow
{
private:
	int id;
	vector <double> values;

	
public:
	CRow();
	CRow(vector <double>_values);
	~CRow();
	vector <double> getValues();
	int getNrOfCols();
};

