#ifndef __SCENE_PARSER__
#define __SCENE_PARSER__

#include <fstream>

#include "Scene.h"
#include "Constants.h"

class SceneParser 
{
public:
	SceneParser(const char* name);
	Scene ReadScene(void);

	// Helper read methods

	/// Reads the information for the resulting image resolution
	void ReadComment(std::ifstream &sceneStream);
	void ReadImageresolutionInfo(std::ifstream &sceneStream, Scene &scene);
	void ReadMaxDepth(std::ifstream &sceneStream, Scene &scene);
	void ReadImageOutputPath(std::ifstream &sceneStream, Scene &scene);
	void ReadCameraParamters(std::ifstream &sceneStream, Scene &scene);
	void ReadSphereParameters(std::ifstream &sceneStream, Scene &scene);
	void ReadMaxverts(std::ifstream &sceneStream);

private:
	const char* cgSceneName;
};

#endif