#include "Matrix.h"
#include "Vector.h"


Matrix::Matrix()
{
	for (int r = 0; r < DIMENSION; r++)
		for (int c = 0; c < DIMENSION; c++)
			m_matrix[r][c] = 0;
}

Matrix::Matrix(float matrix[DIMENSION][DIMENSION])
{
	for (int r = 0; r < DIMENSION; r++)
		for (int c = 0; c < DIMENSION; c++)
			m_matrix[r][c] = matrix[r][c];
}

Matrix::Matrix(Matrix && m)
{
	for (int r = 0; r < DIMENSION; r++)
		for (int c = 0; c < DIMENSION; c++)
			m_matrix[r][c] = m.m_matrix[r][c];
}


Matrix::~Matrix()
{
}


Vector LIB_API Matrix::operator*(Vector v) const
{
	float x, y, z;

	x = y = z = 0;

	x = mult_row(m_matrix[0], v);
	y = mult_row(m_matrix[1], v);
	z = mult_row(m_matrix[2], v);

	return Vector{ x, y, z };
}

Matrix LIB_API Matrix::operator*(Matrix m) const
{
	return Matrix();
}

Matrix LIB_API Matrix::transposed()
{
	Matrix transpose;

	for (int r = 0; r < DIMENSION; r++)
		for (int c = 0; c < DIMENSION; c++)
			transpose.m_matrix[c][r] = m_matrix[r][c];
		
	return transpose;
}

void LIB_API Matrix::print()
{
	for (int r = 0; r < DIMENSION; r++)
	{
		for (int c = 0; c < DIMENSION; c++)
			std::cout << m_matrix[r][c] << "\t";
		std::cout << std::endl;
	}

}

float LIB_API Matrix::mult_row(const float row[DIMENSION], Vector v) const
{
	float sum = 0;

	for (int i = 0; i < DIMENSION; i++)
		sum += row[i] * v[i];

	return sum;
}
