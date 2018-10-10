#include "Vector.h"

//////////////
// DLL MAIN //
//////////////


#ifdef _WINDOWS
#include <Windows.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * DLL entry point. Avoid to rely on it for easier code portability (Linux doesn't use this method).
 * @param instDLL handle
 * @param reason reason
 * @param _reserved reserved
 * @return true on success, false on failure
 */
int APIENTRY DllMain(HANDLE instDLL, DWORD reason, LPVOID _reserved)
{
	// Check use:
	switch (reason)
	{
		///////////////////////////
	case DLL_PROCESS_ATTACH: //
		break;


		///////////////////////////
	case DLL_PROCESS_DETACH: //
		break;
	}

	// Done:
	return true;
}
#endif



Vector::~Vector()
{
	
}

Vector LIB_API Vector::operator+(Vector o)
{
	return Vector { m_x + o.m_x, m_y + o.m_y, m_z + o.m_z };
}

Vector LIB_API Vector::operator-(Vector o)
{
	return Vector { m_x - o.m_x, m_y - o.m_y, m_z - o.m_z };
}

float LIB_API Vector::dot(Vector o)
{
	return m_x * o.m_x + m_y * o.m_y + m_z * o.m_z;
}

Vector LIB_API Vector::cross(Vector o)
{
	return Vector{ m_y*o.m_z - m_z * o.m_y, m_x*o.m_z - m_z * o.m_x, m_x*o.m_y - m_y * o.m_x };
}

float LIB_API Vector::length()
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
}

void LIB_API Vector::normalization()
{
	float _length = length();

	std::cout << "lunghezza funzione" << _length << std::endl;

	m_x /= _length;
	m_y /= _length;
	m_z /= _length;
}

float Vector::x()
{
	return m_x;
}

float Vector::y()
{
	return m_y;
}

float Vector::z()
{
	return m_z;
}

void LIB_API Vector::stampa()
{
	std::cout << m_x << ", " << m_y << ", " << m_z << std::endl;
}

float Vector::operator[](int i)
{
	switch (i)
	{
	case 0:
		return m_x;
	case 1:
		return m_y;
	case 2:
		return m_z;
	}
}

Vector::Vector(int x, int y, int z)
{
	m_x = (float)x;
	m_y = (float)y;
	m_z = (float)z;
}
