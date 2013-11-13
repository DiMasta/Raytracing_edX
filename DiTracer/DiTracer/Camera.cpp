#include "Camera.h"

Camera::Camera()
{
	m_lookfromx = 0;
	m_lookfromy = 0;
	m_lookfromz = 0;
	m_lookatx = 0;
	m_lookaty = 0;
	m_lookatz = 0;
	m_upx = 0;
	m_upy = 0;
	m_upz = 0;
	m_fov = 0;
}

Camera::Camera(int lookfromx, int lookfromy, int lookfromz,	int lookatx, int lookaty, int lookatz, int upx,	int upy, int upz, int fov) :
	m_lookfromx(lookfromx), m_lookfromy(lookfromy), m_lookfromz(lookfromz), m_lookatx(lookatx), m_lookaty(lookaty), m_lookatz(lookatz), m_upx(upx), m_upy(upy), m_upz(upz), m_fov(fov) 
{
}

Camera::~Camera()
{
}