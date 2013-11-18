#include "Vertex.h"

Vertex::Vertex()
{
	m_xCoord = 0.0;
	m_yCoord = 0.0;
	m_zCoord = 0.0;
}

Vertex::Vertex(float xCoord, float yCoord, float zCoord) :
	m_xCoord(xCoord), m_yCoord(yCoord), m_zCoord(zCoord)
{
}

Vertex::~Vertex()
{
}