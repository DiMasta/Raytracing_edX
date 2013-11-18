#ifndef __RENDER_H__
#define __RENDER_H__

#include "SDL.h"
#include "Scene.h"
#include "Ray.h"

class Renderer
{
public:
	Renderer();
	Renderer(Scene scene);
	~Renderer();

	inline Scene GetScene(){return m_scene;}

	inline void SetScene(Scene scene){m_scene = scene;}

	void Render(SDL_Surface* surface);
	void PutPixelColor(SDL_Surface* surface, int x, int y, Uint32 color);

	Ray RayThruPixel(Camera* camera, int i, int j);
private:
	Scene m_scene;
};

#endif