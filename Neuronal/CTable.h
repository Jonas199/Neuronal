#pragma once
#include "CRow.h"
#include "CTable.h"
#include "vector"

using namespace std;

class CTable
{
public:
	CTable();
	void addRow(CRow *_row);
	CRow *getRow(int i);
	~CTable();
private:
	vector <CRow*> rows;
};

