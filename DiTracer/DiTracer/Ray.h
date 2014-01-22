#ifndef __RAY_H__
#define __RAY_H__

#include "Vector.h"

class Ray
{
public:
	Ray();
	Ray(Vector origin, Vector direction);
	~Ray();

	inline Vector GetOrigin() { return m_origin; }
	inline Vector GetDirection() { return m_direction; }

	inline void SetOrigin(Vector origin) { m_origin = origin; }
	inline void SetDirection(Vector direction) { m_direction= direction; }

private:
	Vector m_origin;
	Vector m_direction;
};

#endif