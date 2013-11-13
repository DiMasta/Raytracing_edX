#include <time.h>

#include "SDL.h"

const int IMAGE_WIDHT = 640;
const int IMAGE_HEIGHT = 480;

/// Sets pixel color
void PutPixel32_nolock(SDL_Surface * surface, int x, int y, Uint32 color)
{
    Uint8 * pixel = (Uint8*)surface->pixels;
    pixel += (y * surface->pitch) + (x * sizeof(Uint32));
    *((Uint32*)pixel) = color;
}

/// Sets the color of all screen pixels
void FillScreenPixels(SDL_Surface * surface)
{
	unsigned randColor;
	int rand1, rand2, rand3, seed;

	for(int i = 0; i < IMAGE_WIDHT; ++i)
	{
		for(int j = 0; j < IMAGE_HEIGHT; ++j)
		{
			// random color
			seed = /*rand() %*/ 255;
			rand1 = seed;
			seed = rand() % 255;
			rand2 = seed;
			seed = rand() % 255;
			rand3 = seed;

			randColor = SDL_MapRGB(surface->format, rand1, rand2, rand3);

			PutPixel32_nolock(surface, i, j, randColor);
		}
	}
}

int main( int argc, char* args[] )
{
	srand(time(NULL));

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    
	SDL_Surface* displaysurface = SDL_SetVideoMode(
        IMAGE_WIDHT, IMAGE_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	unsigned backgroundcolor = SDL_MapRGB(displaysurface->format, 0, 64, 0);
	unsigned red = SDL_MapRGB(displaysurface->format, 255, 0, 0);

    SDL_Event sdlevent;
    bool running = true;

	FillScreenPixels(displaysurface);

    while(running)
    {
        while(SDL_PollEvent(&sdlevent))
        {
            switch(sdlevent.type)
            {
            case SDL_QUIT:
                {
                    running = false;
                }break;
			}
		}

		FillScreenPixels(displaysurface);
		SDL_Flip(displaysurface);
		SDL_Delay(20);
	}

    //Quit SDL
    SDL_Quit();
    
    return 0;    
}