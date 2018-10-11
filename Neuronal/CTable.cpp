#include "pch.h"
#include "CTable.h"


CTable::CTable()
{

}

void CTable::addRow(CRow *_row)
{
	this->rows.push_back(_row);
}

CRow * CTable::getRow(int i)
{
	return this->rows.at(i);
}


CTable::~CTable()
{
}
