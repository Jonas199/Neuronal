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
	double **matrix;
public:
	void setValue(int row, int col, double value);
	double getValue(int row, int col);
	void printMatrix();
	void setMatrixToZero();
	void multWithFactor(double factor);
	void addMatr(CMatrix *m);
};

