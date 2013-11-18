#include "Triangle.h"

#include <vector>

using namespace std;

Triangle::Triangle()
{
	vertex0 = Vertex();
	vertex1 = Vertex();
	vertex2 = Vertex();
}

Triangle::Triangle(int vertIdx0, int vertIdx1, int vertIdx2, Scene scene)
{
	vector<Vertex> vertecies = scene.GetVertecies();

	vertex0 = vertecies[vertIdx0];
	vertex1 = vertecies[vertIdx1];
	vertex2 = vertecies[vertIdx2];
}

Triangle::~Triangle()
{
}