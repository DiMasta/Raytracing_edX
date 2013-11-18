#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "Vertex.h"
#include "Scene.h"


class Triangle : public SceneObject
{
public:
	Triangle();
	Triangle(int vertIdx0, int vertIdx1, int vertIdx2, Scene scene);
	~Triangle();
private:
	Vertex vertex0;
	Vertex vertex1;
	Vertex vertex2;
};

#endif