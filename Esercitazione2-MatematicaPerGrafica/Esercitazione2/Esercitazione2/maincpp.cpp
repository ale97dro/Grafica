#include <iostream>
#include "Vector.h"


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


	return 0;
}
