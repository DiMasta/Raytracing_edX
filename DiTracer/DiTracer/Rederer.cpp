#include "Render.h"
#include "Ray.h"

#include <cmath>

Renderer::Renderer()
{
}

Renderer::Renderer(Scene scene) : m_scene(scene)
{
}

Renderer::~Renderer()
{
}

void Renderer::Render(SDL_Surface* surface)
{
	Ray tracingRay;

	// Shoot ray from every pixel and compute its intersetion
	for(int i = 0; i < m_scene.GetImageWidth(); ++i)
	{
		for(int j = 0; j < m_scene.GetImageHeight(); ++j)
		{
			// Cast Ray
			tracingRay = RayThruPixel(m_scene.GetCamera(), i, j);

			unsigned randColor = SDL_MapRGB(surface->format, 255, rand() % 255, rand() % 255);
			PutPixelColor(surface, i, j, randColor);
		}
	}
}

void Renderer::PutPixelColor(SDL_Surface* surface, int x, int y, Uint32 color)
{
    Uint8 * pixel = (Uint8*)surface->pixels;
    pixel += (y * surface->pitch) + (x * sizeof(Uint32));
    *((Uint32*)pixel) = color;
}

Ray Renderer::RayThruPixel(Camera* camera, int i, int j)
{
	float alpha;
	float beta;

	//alpha = tan(camera->Getfov());

	Ray r;
	return r;
}