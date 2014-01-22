#include "Camera.h"

Camera::Camera()
{
	m_fov = 0;
}

Camera::Camera(float lookfromx, float lookfromy, float lookfromz, float lookatx, float lookaty, float lookatz, float upx, float upy, float upz, int fov) :
	m_lookfromPoint(lookfromx, lookfromy, lookfromz), m_lookatPoint(lookatx, lookaty, lookatz), m_upVector(upx, upy, upz), m_fov(fov) 
{
}

Camera::~Camera()
{
}