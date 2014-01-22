#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector
{
public:
	Vector();
	Vector(float x, float y, float z);
	Vector(Vector &vector);
	~Vector();

	Vector operator*(float scalar);
	Vector operator*(const Vector &vector); // crossProduct
	float operator^(const Vector &vector); // dotProduct
	Vector operator+(const Vector &vector);
	Vector operator-(const Vector &vector);

	inline Vector Inverse() {return this->operator*(-1);}
	

private:
	float m_x;
	float m_y;
	float m_z;
};

#endif