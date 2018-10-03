#pragma once
class CMatrix
{
public:
	CMatrix();
	CMatrix(int rows, int cols);
	~CMatrix();
private:
	int rows;
	int cols;
};

