#include "pch.h"
#include "CRow.h" 




vector<double> CRow::getValues()
{
	return this->values;
}

CRow::CRow()
{
}

CRow::CRow(std::vector <double>_values)
{
	this->values = _values;
}


CRow::~CRow()
{
}
