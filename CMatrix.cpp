#include "stdafx.h"
#include "CMatrix.h"
#include <iostream>
#include <Array>

using namespace std;

CMatrix::CMatrix()
{
	rows = 0;
	cols = 0;
}

CMatrix::CMatrix(int _rows, int _cols){
	this->rows = _rows;
	this->cols = _cols;
	double** _matrix = new double*[rows];
	for (int i = 0; i < rows; ++i)
		_matrix[i] = new double[cols];
	this->matrix = _matrix;
	this->setMatrixToZero();
}

CMatrix::~CMatrix()
{
	for (int i = 0; i < rows; i++){
		delete matrix[i];
	}
}


void CMatrix::setValue(int row, int col, double value)
{
	this->matrix[row][col] = value;
}


double CMatrix::getValue(int row, int col)
{
	return this->matrix[row][col];
}

void CMatrix::printMatrix(){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			cout << "[" << this->getValue(i, j) << "]";
		}
		cout << endl;
	}
}

void CMatrix::setMatrixToZero(){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			this->setValue(i, j,0);
		}
	}
}



void CMatrix::multWithFactor(double factor)
{
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			this->setValue(i, j, this->getValue(i,j)*factor);
		}
	}
}
