#include "Render.h"

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
			tracingRay = RayThruPixel(i, j);

			Sphere sphere(0, 0, 0, 1);

			if(RaySphereIntersection(tracingRay, sphere))
			{
				unsigned randColor = SDL_MapRGB(surface->format, 255, 0, 0);
				PutPixelColor(surface, i, j, randColor);
			}

			//unsigned randColor = SDL_MapRGB(surface->format, 255, rand() % 255, rand() % 255);
			//PutPixelColor(surface, i, j, randColor);
		}
	}
}

void Renderer::PutPixelColor(SDL_Surface* surface, int x, int y, Uint32 color)
{
    Uint8 * pixel = (Uint8*)surface->pixels;
    pixel += (y * surface->pitch) + (x * sizeof(Uint32));
    *((Uint32*)pixel) = color;
}

Ray Renderer::RayThruPixel(int i, int j)
{
	Ray viewRay;

	Camera* camera = m_scene.GetCamera();

	viewRay.SetOrigin(camera->GetlookfromPoint());

	int d = camera->Getfov();
	int l, r, b, t;
	double u, v;

	l = -(m_scene.GetImageWidth() / 2);
	r = m_scene.GetImageWidth() / 2;
	b = -(m_scene.GetImageHeight() / 2);
	t = m_scene.GetImageHeight() / 2;

	u = l + (r - l) * (i + 0.5) / m_scene.GetImageWidth();
	v = b + (t - b) * (j + 0.5) / m_scene.GetImageHeight();

	Vector w(camera->GetlookatPoint().Inverse());
	Vector upVector(camera->GetupVector());
	Vector uVector = w * upVector;

	Vector directionVector;
	
	directionVector = (w * (-d)) + (uVector * u) + (upVector * v);

	viewRay.SetDirection(directionVector);

	return viewRay;
}

bool Renderer::RaySphereIntersection(Ray ray, Sphere sphere)
{
	Vector d = ray.GetDirection();
	Vector e = ray.GetOrigin();
	Vector c = sphere.GetCenter();
	int R = sphere.GetRadius();

	float discriminant = (d ^ (e - c)) * (d ^ (e - c)) - ((d ^ d) * (((e - c) ^ (e - c)) - R * R));

	if(discriminant >= 0.0)
		return true;

	return false;
}