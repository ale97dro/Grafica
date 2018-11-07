#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "../glm/glm/mat3x3.hpp"
#include "../glm/glm/gtx/string_cast.hpp"


void serie2Esercizio1();
void serie2Esercizio2();
void serie2Esercizio3();
void serie2Esercizio4();
void esercizioConLibreriaEsterna();

int main()
{
	Vector a{ 1.0f, 0.0f,-1.0f };
	Vector b{ -0.5f, 1.5f, 0.5f };

	Vector somma{ a + b };
	Vector differenza{ a + b };


	std::cout << "Somma a+b: ";
	somma.print();

	std::cout << "Somma a-b";
	differenza.print();

	std::cout << "Dot: " << a.dot(b) << std::endl;

	Vector cross{ a.cross(b) };
	std::cout << "Cross: ";
	cross.print();

	//Lunghezza
	std::cout << "Lunghezza a: " << a.length() << std::endl;



	//Normalizza
	std::cout << "Lunghezza b: " << b.length() << std::endl;
	b.normalization();
	std::cout << "B normalizzato: ";
	b.print();



	////MATRIX TEST
	//std::cout << "\n\n\nMATRIX\n\n\n";

	//float temp[3][3] = { { 1,2,3}, {4,5,6}, {7,8,9} };

	////Matrix m{ temp };
	//Matrix m{ temp };
	//m.print();

	//std::cout << std::endl << "Transposed: " << std::endl << std::endl;
	//Matrix m_transpose{ m.transposed() };
	//m_transpose.print();


	//Vector c{ 1,1,0 };
	//
	//

	//std::cout << "\n\n\\n\n";

	//Matrix m2{ temp2 };
	//m2.print();

	//std::cout << "        ";
	//c.print();

	//std::cout << "\n\n\n\n";


	////Vector multiply{ m2.matrix_by_vector_mult(c) };

	//Vector multiply{ m2*c };

	//multiply.print();

	
	std::cout << "ESERICIZI SULLE MATRICI" << std::endl << std::endl;

	/*serie2Esercizio1();
	serie2Esercizio2();
	serie2Esercizio3();	
	serie2Esercizio4();*/

	esercizioConLibreriaEsterna();


	return 0;
}

void serie2Esercizio1()
{
	//TODO imolements
	//float 

	std::cout << std::endl;
}

void serie2Esercizio2()
{
	float temp[3][3] = { {0.5, -1, -2}, {1, 0.5, -1}, {2, 1, -0.5} };

	Matrix original{ temp };

	Matrix trans1{ original.transposed() };
	Matrix trans2{ trans1.transposed() };
	Matrix trans3{ trans2.transposed() };

	trans3.print();
	std::cout << std::endl;
}

void serie2Esercizio3()
{
	float temp[3][3] = { {1,0,30}, {0,1,15},{0,0,1} };
	Vector vector{ 1,1,0 };
	Matrix matrix{ temp };

	Vector result{ matrix*vector };
	result.print();
	std::cout << std::endl;
}

void serie2Esercizio4()
{
	float temp1[3][3] = { {1, -1, 0}, {-1, 1, 0}, {0, 0, 1} };
	float temp2[3][3] = { {1, 0, 30}, {0, 1, 15}, {0, 0, 1} };

	Matrix m1{ temp1 };
	Matrix m2{ temp2 };
	Matrix trans_m1{ m1.transposed() };

	Matrix product{ trans_m1 * m2 };

	product.print();
	std::cout << std::endl;
}

void esercizioConLibreriaEsterna()
{
	glm::mat3 mat { 0.5f };

	std::cout << glm::to_string(mat);
}
