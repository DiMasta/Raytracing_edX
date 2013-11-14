#include "SceneParser.h"
#include "Sphere.h"
#include "Vertex.h"
#include "Triangle.h"

#include <fstream>
#include <string>

using namespace std;

SceneParser::SceneParser(const char* name)
{
	cgSceneName = name;
}

/// Reads the information for the scene from the specified file (cgSceneName)
Scene SceneParser::ReadScene(void)
{
	Scene cgScene;

	ifstream sceneFile(cgSceneName);

	string wordIdentifier;

	while(sceneFile >> wordIdentifier)
	{
		if(!wordIdentifier.compare(COMMENT_COMMAND))
			ReadComment(sceneFile);

		if(!wordIdentifier.compare(IMAGE_SIZE_COMMAND))
			ReadImageresolutionInfo(sceneFile, cgScene);

		if(!wordIdentifier.compare(MAX_DEPTH_COMMAND))
			ReadMaxDepth(sceneFile, cgScene);

		if(!wordIdentifier.compare(OUTPUT_COMMAND))
			ReadImageOutputPath(sceneFile, cgScene);

		if(!wordIdentifier.compare(CAMERA_COMMAND))
			ReadCameraParamters(sceneFile, cgScene);

		//Geometry
		if(!wordIdentifier.compare(SPHERE_COMMAND))
			ReadSphereParameters(sceneFile, cgScene);

		if(!wordIdentifier.compare(MAXVERTS_COMMAND))
			ReadMaxverts(sceneFile);

		if(!wordIdentifier.compare(MAXNORMALS_COMMAND))
			ReadMaxNormals(sceneFile);

		if(!wordIdentifier.compare(VERTEX_COMMAND))
			ReadVertex(sceneFile, cgScene);

		if(!wordIdentifier.compare(VERTNORMAL_COMMAND))
			ReadVertNormal(sceneFile);

		if(!wordIdentifier.compare(TRIANGLE_COMMAND))
			ReadTriangleParameters(sceneFile, cgScene);

		if(!wordIdentifier.compare(TRINORMAL_COMMAND))
			ReadTriNormal(sceneFile);
	}

	return cgScene;
}

void SceneParser::ReadComment(ifstream &sceneStream)
{
	//we read a comment and must ignore the rest of the line
	sceneStream.ignore(numeric_limits<streamsize>::max(),'\n');
}

void SceneParser::ReadImageresolutionInfo(ifstream &sceneStream, Scene &scene)
{
	int imageWidth;
	int imageHeight;

	sceneStream >> imageWidth;
	sceneStream >> imageHeight;

	scene.SetImageWidth(imageWidth);
	scene.SetImageHeight(imageHeight);
}

void SceneParser::ReadMaxDepth(ifstream &sceneStream, Scene &scene)
{
	int maxDepth;

	sceneStream >> maxDepth;

	scene.SetMaxDepth(maxDepth);
}

void SceneParser::ReadImageOutputPath(ifstream &sceneStream, Scene &scene)
{
	string outputImagePath;

	getline(sceneStream, outputImagePath);

	scene.SetOutputImagePath(outputImagePath);
}

void SceneParser::ReadCameraParamters(ifstream &sceneStream, Scene &scene)
{
	int lookfromx;
	int lookfromy;
	int lookfromz;
	int lookatx;
	int lookaty;
	int lookatz;
	int upx;
	int upy;
	int upz;
	int fov;

	sceneStream >> lookfromx;
	sceneStream >> lookfromy;
	sceneStream >> lookfromz;
	sceneStream >> lookatx;
	sceneStream >> lookaty;
	sceneStream >> lookatz;
	sceneStream >> upx;
	sceneStream >> upy;
	sceneStream >> upz;
	sceneStream >> fov;

	Camera* camera = new Camera(lookfromx, lookfromy, lookfromz, lookatx, lookaty, lookatz, upx, upy, upz, fov);

	scene.SetCamera(camera);
}

void SceneParser::ReadSphereParameters(ifstream &sceneStream, Scene &scene)
{
	int x;
	int y;
	int z;
	int radius;

	sceneStream >> x;
	sceneStream >> y;
	sceneStream >> z;
	sceneStream >> radius;

	Sphere sphere(x, y, z, radius);

	scene.AddRenderableObject(sphere);
}

void SceneParser::ReadMaxverts(ifstream &sceneStream)
{
	int maxverts;
	sceneStream >> maxverts;
}

void SceneParser::ReadMaxNormals(ifstream &sceneStream)
{
	int maxNormals;
	sceneStream >> maxNormals;
}

void SceneParser::ReadVertex(ifstream &sceneStream, Scene &scene)
{
	float xCoord;
	float yCoord;
	float zCoord;

	sceneStream >> xCoord;
	sceneStream >> yCoord;
	sceneStream >> zCoord;

	Vertex vertex(xCoord, yCoord, zCoord);

	scene.AddVertex(vertex);
}

void SceneParser::ReadVertNormal(ifstream &sceneStream)
{
	float x;
	float y;
	float z;

	float nx;
	float ny;
	float nz;

	sceneStream >> x;
	sceneStream >> y;
	sceneStream >> z;

	sceneStream >> nx;
	sceneStream >> ny;
	sceneStream >> nz;
}

void SceneParser::ReadTriangleParameters(ifstream &sceneStream, Scene &scene)
{
	int vertIndex0;
	int vertIndex1;
	int vertIndex2;

	sceneStream >> vertIndex0;
	sceneStream >> vertIndex1;
	sceneStream >> vertIndex2;

	Triangle triangle(vertIndex0, vertIndex1, vertIndex2, scene);

	scene.AddRenderableObject(triangle);
}

void SceneParser::ReadTriNormal(ifstream &sceneStream)
{
	float v1;
	float v2;
	float v3;

	sceneStream >> v1;
	sceneStream >> v2;
	sceneStream >> v3;
}