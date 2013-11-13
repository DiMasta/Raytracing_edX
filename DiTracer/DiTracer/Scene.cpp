#include "Scene.h"

Scene::Scene()
{
}

Scene::Scene(std::vector<SceneObject> sceneObjects, int imageWidth, int imageHeight, int maxdepth,	std::string imageOutputPath, Camera* camera) :
	m_sceneObjects(sceneObjects), m_imageWidth(imageWidth), m_imageHeight(imageHeight), m_imageOutputPath(imageOutputPath), m_camera(camera)
{
}

Scene::~Scene()
{
	//delete m_camera;
}