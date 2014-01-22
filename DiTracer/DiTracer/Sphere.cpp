#include "Sphere.h"

Sphere::Sphere()
{

}

Sphere::Sphere(float x, float y, float z, int radius) :
	m_center(x, y, z), m_radius(radius)
{
}

Sphere::~Sphere()
{
}