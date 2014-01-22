#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Vector.h"

class Camera
{
public:
	Camera();
	Camera(float lookfromx, float lookfromy, float lookfromz, float lookatx, float lookaty, float lookatz, float upx, float upy, float upz, int fov);
	~Camera();

	inline Vector GetlookfromPoint(void) {return m_lookfromPoint;}
	inline Vector GetlookatPoint(void) {return m_lookatPoint;}
	inline Vector GetupVector(void) {return m_upVector;}
	inline int Getfov(void) {return m_fov;}

	inline void SetlookfromPoint(Vector lookfromPoint) {this->m_lookfromPoint = lookfromPoint;}
	inline void SetlookatPoint(Vector lookatPoint) {this->m_lookatPoint = lookatPoint;}
	inline void Setupx(Vector upVector) {this->m_upVector = upVector;}
	inline void Setfov(int fov) {this->m_fov;}

private:
	Vector m_lookfromPoint;
	Vector m_lookatPoint;
	Vector m_upVector;
	int m_fov;
};

#endif