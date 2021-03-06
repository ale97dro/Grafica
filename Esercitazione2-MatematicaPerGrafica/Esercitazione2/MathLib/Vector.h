#pragma once

#include <iostream>
#include <math.h>

// Generic info:
#define LIB_NAME      "MathLib v1.0"  ///< Library credits
#define LIB_VERSION   10                              ///< Library version (divide by 10)

#ifdef _WINDOWS
   // Export API:
   // Specifies i/o linkage (VC++ spec): //TODO cambiare il nome sotto
#ifdef MATHLIB_EXPORTS
#define LIB_API __declspec(dllexport)
#else
#define LIB_API __declspec(dllimport)
#endif
#else // Under Linux
#define LIB_API  // Dummy declaration
#endif


class LIB_API Vector
{
public:

	Vector(float x, float y, float z)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}


//	Point(const Point &p2)

	Vector(const Vector& v)
		:m_x{ v.m_x }, m_y{ v.m_y }, m_z{ v.m_z }
	{

	}


	//Costruttore per interi
	Vector(int x, int y, int z);


	~Vector();


	Vector operator+(Vector o);
	Vector operator-(Vector o);
	float dot(Vector o);
	Vector cross(Vector o);
	float length();
	void normalization();

	float x();
	float y();
	float z();


	void print();

	float operator[](int i);
	


private:
	float m_x;
	float m_y;
	float m_z;

	//friend class Matrix;

};

