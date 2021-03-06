#pragma once
#include "Vector.h"

class LIB_API Matrix
{
public:

	//Const
	static const int DIMENSION = 3;

	Matrix();
	Matrix(float matrix[DIMENSION][DIMENSION]);
	Matrix(Matrix&& m);

	~Matrix();
	

	Matrix operator+(Matrix &m);
	Vector operator*(Vector &v);
	Matrix operator*(Matrix &m);

	Matrix transposed();

	void print();

	
private:
	float m_matrix[3][3];
	int m_row;
	int m_column;

	float mult_row(const float row[DIMENSION], Vector v) const;
	float mult_row(const float row[DIMENSION], const float row2[DIMENSION]) const;
};

