#ifndef __SCENE_H__
#define __SCENE_H__

#include "SceneObject.h"
#include "Camera.h"

#include <vector>
#include <string>

/// Class holding information for the actual scene for rendering
class Scene
{
public:
	Scene();
	Scene(std::vector<SceneObject> sceneObjects, int imageWidth, int imageHeight, int maxdepth,	std::string imageOutputPath, Camera* camera);
	~Scene();

	inline int GetImageWidth(void){return m_imageWidth;}
	inline int GetImageHeight(void){return m_imageHeight;}
	inline int GetMaxDepth(void){return m_maxdepth;}
	inline std::string GetOutputImagePath(void){return m_imageOutputPath;}
	inline Camera* GetCamera(void){return m_camera;}

	inline void SetImageWidth(int width){m_imageWidth = width;}
	inline void SetImageHeight(int height){m_imageHeight = height;}
	inline void SetMaxDepth(int depth){m_maxdepth = depth;}
	inline void SetOutputImagePath(std::string path){m_imageOutputPath = path;}
	inline void SetCamera(Camera* camera){m_camera = camera;}
private:
	std::vector<SceneObject> m_sceneObjects;
	int m_imageWidth;
	int m_imageHeight;
	int m_maxdepth;
	std::string m_imageOutputPath;

	Camera* m_camera;
};

#endif