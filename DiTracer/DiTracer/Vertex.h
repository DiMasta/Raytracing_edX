#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex
{
public:
	Vertex();
	Vertex(float xCoord, float yCoord, float zCoord);
	~Vertex();

	inline float GetXCoord(void){return m_xCoord;}
	inline float GetYCoord(void){return m_yCoord;}
	inline float GetZCoord(void){return m_zCoord;}

	inline void SetXCoord(float xCoord){m_xCoord = xCoord;}
	inline void SetYCoord(float yCoord){m_yCoord = yCoord;}
	inline void SetZCoord(float zCoord){m_zCoord = zCoord;}
private:
	float m_xCoord;
	float m_yCoord;
	float m_zCoord;
};

#endif