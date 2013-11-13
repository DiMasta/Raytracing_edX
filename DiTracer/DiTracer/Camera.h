#ifndef __CAMERA_H__
#define __CAMERA_H__

class Camera
{
public:
	Camera();
	Camera(int lookfromx, int lookfromy, int lookfromz,	int lookatx, int lookaty, int lookatz, int upx,	int upy, int upz, int fov);
	~Camera();

	inline int Getlookfromx(void) {return m_lookfromx;}
	inline int Getlookfromy(void) {return m_lookfromy;}
	inline int Getlookfromz(void) {return m_lookfromz;}
	inline int Getlookatx(void) {return m_lookatx;}
	inline int Getlookaty(void) {return m_lookaty;}
	inline int Getlookatz(void) {return m_lookatz;}
	inline int Getupx(void) {return m_upx;}
	inline int Getupy(void) {return m_upy;}
	inline int Getupz(void) {return m_upz;}
	inline int Getfov(void) {return m_fov;}

	inline void Setlookfromx(int lookfromx) {this->m_lookfromx;}
	inline void Setlookfromy(int lookfromy) {this->m_lookfromy;}
	inline void Setlookfromz(int lookfromz) {this->m_lookfromz;}
	inline void Setlookatx(int lookatx) {this->m_lookatx;}
	inline void Setlookaty(int lookaty) {this->m_lookaty;}
	inline void Setlookatz(int lookatz) {this->m_lookatz;}
	inline void Setupx(int upx) {this->m_upx;}
	inline void Setupy(int upy) {this->m_upy;}
	inline void Setupz(int upz) {this->m_upz;}
	inline void Setfov(int fov) {this->m_fov;}

private:
	int m_lookfromx;
	int m_lookfromy;
	int m_lookfromz;
	int m_lookatx;
	int m_lookaty;
	int m_lookatz;
	int m_upx;
	int m_upy;
	int m_upz;
	int m_fov;
};

#endif