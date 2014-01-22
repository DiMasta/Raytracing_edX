#include "Vector.h"

Vector::Vector()
{

}

Vector::Vector(float x, float y, float z) : m_x(x), m_y(y), m_z(z)
{

}

Vector::Vector(Vector &vector)
{
	this->m_x = vector.m_x;
	this->m_y = vector.m_y;
	this->m_z = vector.m_z;
}

Vector Vector::operator*(float scalar)
{
	Vector newVector;
	newVector.m_x *= scalar;
	newVector.m_y *= scalar;
	newVector.m_z *= scalar;

	return newVector;
}

Vector Vector::operator*(const Vector &vector)
{
	Vector newVector;
	newVector.m_x = (this->m_y * vector.m_z) - (this->m_z * vector.m_y);
	newVector.m_y = (this->m_z * vector.m_x) - (this->m_x * vector.m_z);
	newVector.m_z = (this->m_x * vector.m_y) - (this->m_y * vector.m_x);

	return newVector;
}

Vector Vector::operator+(const Vector &vector)
{
	Vector newVector;
	newVector.m_x += vector.m_x;
	newVector.m_y += vector.m_y;
	newVector.m_z += vector.m_z;

	return newVector;
}

Vector Vector::operator-(const Vector &vector)
{
	Vector newVector;
	newVector.m_x -= vector.m_x;
	newVector.m_y -= vector.m_y;
	newVector.m_z -= vector.m_z;

	return newVector;
}

float Vector::operator^(const Vector &vector)
{
	float dotProduct;

	dotProduct = (this->m_x * vector.m_x) + (this->m_y * vector.m_y) + (this->m_z * vector.m_z);

	return dotProduct;
}

Vector::~Vector()
{
}