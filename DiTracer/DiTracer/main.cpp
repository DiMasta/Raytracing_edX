#include <iostream>
#if defined(_MSC_VER)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

/**
* Lesson 1: Hello World!
*/
int main(int argc, char** argv){
        //First we need to start up SDL, and make sure it went ok
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
                std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
                return 1;
        }
        
        //Now create a window with title "Hello World" at 100, 100 on the screen with w:640 h:480 and show it
        SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
        //Make sure creating our window went ok
        if (win == nullptr){
                std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
                return 1;
        }

        //Create a renderer that will draw to the window, -1 specifies that we want to load whichever 
        //video driver supports the flags we're passing
        //Flags: SDL_RENDERER_ACCELERATED: We want to use hardware accelerated rendering
        //SDL_RENDERER_PRESENTVSYNC: We want the renderer's present function (update screen) to be
        //synchornized with the monitor's refresh rate
        SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (ren == nullptr){
                std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
                return 1;
        }
        
        //Now lets draw our image
        //First clear the renderer
        SDL_RenderClear(ren);
        //Update the screen
        SDL_RenderPresent(ren);

        //Have the program wait for 2000ms so we get a chance to see the screen
        SDL_Delay(2000);

        //Clean up our objects and quit
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
        
        return 0;
}