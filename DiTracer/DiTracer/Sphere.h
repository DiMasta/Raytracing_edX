#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Vector.h"
#include "SceneObject.h"

class Sphere : public SceneObject
{
public:
	Sphere();
	Sphere(float x, float y, float z, int radius);
	~Sphere();

	inline Vector GetCenter(){return m_center;}
	inline int GetRadius(){return m_radius;}

	inline void SetCenter(Vector center){m_center = center;}
	inline void SetRadius(int radius){m_radius = radius;}
private:
	Vector m_center;
	int m_radius;
};

#endif