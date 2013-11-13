#include "SDL.h"

int main( int argc, char* args[] )
{
    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    
	SDL_Surface* displaysurface = SDL_SetVideoMode(
        640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	unsigned backgroundcolor = SDL_MapRGB(displaysurface->format, 0, 64, 0);

    SDL_Event sdlevent;
    bool running = true;

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

		SDL_FillRect(displaysurface, NULL, backgroundcolor);
		SDL_Flip(displaysurface);
		//SDL_Delay(2000);
	}

    //Quit SDL
    SDL_Quit();
    
    return 0;    
}