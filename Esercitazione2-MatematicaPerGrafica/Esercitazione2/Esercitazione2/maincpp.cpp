#include <iostream>
#include "Vector.h"
#include "Matrix.h"


int main()
{
	Vector a{ 1.0f, 0.0f,-1.0f };
	Vector b{ -0.5f, 1.5f, 0.5f };

	Vector somma{ a + b };
	Vector differenza{ a + b };


	std::cout << "Somma a+b: ";
	somma.stampa();

	std::cout << "Somma a-b";
	differenza.stampa();

	std::cout << "Dot: " << a.dot(b) << std::endl;

	Vector cross{ a.cross(b) };
	std::cout << "Cross: ";
	cross.stampa();

	//Lunghezza
	std::cout << "Lunghezza a: " << a.length() << std::endl;



	//Normalizza
	std::cout << "Lunghezza b: " << b.length() << std::endl;
	b.normalization();
	std::cout << "B normalizzato: ";
	b.stampa();



	//MATRIX TEST
	std::cout << "\n\n\nMATRIX\n\n\n";

	float temp[3][3] = { { 1,2,3}, {4,5,6}, {7,8,9} };

	//Matrix m{ temp };
	Matrix m{ temp };
	m.print();

	std::cout << std::endl << "Transposed: " << std::endl << std::endl;
	Matrix m_transpose{ m.transposed() };
	m_transpose.print();


	Vector c{ 1,1,0 };
	
	float temp2[3][3] = { {1,0,30}, {0,1,15},{0,0,1} };

	std::cout << "\n\n\\n\n";

	Matrix m2{ temp2 };
	m2.print();

	std::cout << "        ";
	c.stampa();

	std::cout << "\n\n\n\n";


	//Vector multiply{ m2.matrix_by_vector_mult(c) };

	Vector multiply{ m2*c };

	multiply.stampa();
	

	return 0;
}
