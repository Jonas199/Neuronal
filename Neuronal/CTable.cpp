#include "pch.h"
#include "CTable.h"


CTable::CTable()
{

}

void CTable::addRow(CRow *_row)
{
	this->rows.push_back(_row);
	this->nrOfRows++;
}

CRow * CTable::getRow(int i)
{
	return this->rows.at(i);
}

int CTable::getNrOfRows()
{
	return this->rows.size();
}


CTable::~CTable()
{
}
