#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.hpp"

int main(int argv, char** args){
    SDL_Init(SDL_INIT_EVERYTHING);

    Window window("unitled", 700, 700);

    bool isRunning = true;
    SDL_Event event;

    //timeStep -> Allows rendering at 100 frames per second: 1/100
    float timeStep = 0.01f;
	float currentTime = SDL_GetTicks() * 0.001f;
	float accumulator = 0.0f;
	while (isRunning)
	{
		float newTime = SDL_GetTicks() * 0.001f;
		float f = newTime - currentTime;
		currentTime = newTime;
		
		accumulator += f;
        while(accumulator >= timeStep){
            while (SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT){
					isRunning = false;
					break;
				}
                //Register key events here ->
            }
            //Perform once per frame ->
        }
        accumulator -= timeStep;

        window.clearRenderer();
        //Render content here ->
        window.display();
    }
    window.end();
    SDL_Quit();

    return 0;
}
