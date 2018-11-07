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


Matrix LIB_API Matrix::operator+(Matrix &m)
{
	//TODO implements

	Matrix sum{};

	for (int r = 0; r < DIMENSION; r++)
		for (int c = 0; c < DIMENSION; c++)
			sum.m_matrix[r][c] = m_matrix[r][c] + m.m_matrix[r][c];

	return sum;
}

Vector LIB_API Matrix::operator*(Vector &v)
{
	float x, y, z;

	x = y = z = 0;

	x = mult_row(m_matrix[0], v);
	y = mult_row(m_matrix[1], v);
	z = mult_row(m_matrix[2], v);

	return Vector{ x, y, z };
}

Matrix LIB_API Matrix::operator*(Matrix& m)
{
	Matrix product;

	int i, j, r;

	for (i = 0; i < DIMENSION; i++) 
	{
		for (j = 0; j < DIMENSION; j++) 
		{
			product.m_matrix[i][j] = 0;
			for (r = 0; r < DIMENSION; r++) 
			{
				product.m_matrix[i][j] += m_matrix[i][r] * m.m_matrix[r][j];
			}
		}
	}

	return product;
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

float LIB_API Matrix::mult_row(const float row[DIMENSION], const float row2[DIMENSION]) const
{
	float sum = 0;

	for (int i = 0; i < DIMENSION; i++)
		sum += row[i] * row2[i];

	return sum;
}
