#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "SceneObject.h"

class Sphere : public SceneObject
{
public:
	Sphere();
	Sphere(int x, int y, int z, int radius);
	~Sphere();

	inline int GetX(){return m_x;}
	inline int GetY(){return m_y;}
	inline int GetZ(){return m_z;}
	inline int GetRadius(){return m_radius;}

	inline int SetX(int x){m_x = x;}
	inline int SetY(int y){m_y = y;}
	inline int SetZ(int z){m_z = z;}
	inline int SetRadius(int radius){m_radius = radius;}
private:
	int m_x;
	int m_y;
	int m_z;
	int m_radius;
};

#endif