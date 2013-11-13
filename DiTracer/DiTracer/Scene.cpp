#include "Scene.h"

Scene::Scene()
{
}

Scene::Scene(std::vector<SceneObject> renderableObjects, int imageWidth, int imageHeight, int maxdepth,	std::string imageOutputPath, Camera* camera) :
	m_renderableObjects(renderableObjects), m_imageWidth(imageWidth), m_imageHeight(imageHeight), m_imageOutputPath(imageOutputPath), m_camera(camera)
{
}

Scene::~Scene()
{
	//delete m_camera;
}

void Scene::AddRenderableObject(SceneObject rendObject)
{
	m_renderableObjects.push_back(rendObject);
}