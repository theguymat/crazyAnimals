#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "MouseHandler.h"
#include "Menu.h"

using namespace std;


int main(int argc, char **argv){

	//initialise everything of SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{	//output something if failed
		cout << " SDL failed to initialise!" << endl;
		return -1;
	}  
	cout << "SDL sucessfully initialised!" << endl;
		//initialise the image
	if (!(IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG))
	{
		cout << "SDL Image didn't load: " << IMG_GetError()<< endl;
		SDL_Quit();
		system("pause");
		return -1;
	}
	// create a new window
	SDL_Window *window = SDL_CreateWindow("Crazy Animals", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	//check if the window works
	if (window != NULL)
		cout << " Window created!" << endl;
	else
	{
		cout << "Window failed" << endl;
		return -1;
	}
	//create a renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//check if it works
	if (renderer != NULL)
	{
		cout << "Renderer is created!" << endl;
	}
	else
	{
		cout << "Renderer failed" << endl;
		return -1;
	}

	Menu * menu = new Menu();
	MouseHandler mouseHandler;
	mouseHandler.menu = menu;

	//create a surface from image
	SDL_Surface * backgroundSurface = IMG_Load("assets/titlescreen.png");
	//create a texture from surface
	SDL_Texture * backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
	//release the surface memory
	SDL_FreeSurface(backgroundSurface);
	//make a rectangle to draw the background texture
	SDL_Rect backgroundRect = { 0, 0, 1280, 720 };
	//copy the texture to renderer
	SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);


	//setting up the time
	Uint32 lastUpdate = SDL_GetTicks();//milliseconds since the start of the game running

	//current frame (0-3)
	int currentFrame = 0;
	float frameTimer = 0.083;//83 milliseconds per frame


	int framesCounted = 0;
	float oneSecondTimer = 1;

	float millisecondsInASecond = 1000;

	bool loop = true;
	while (loop)
	{
		//TIME!!!!
		//===================
		//get difference between currentTime running minus the last update time
		//ensures game runs at same speed for different computers
		Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
		//convert to deltaTime
		float dt = timeDiff / millisecondsInASecond;
		
		//update lastUpdate to currentTime
		lastUpdate = SDL_GetTicks();

		framesCounted++;
		oneSecondTimer -= dt;//minusing how many milliseconds since last game loop cycle

		//1 second has passed
		if (oneSecondTimer <= 0)
		{
			cout << "FPS = " << framesCounted << " dt = " << dt << endl;
			framesCounted = 0;
			oneSecondTimer = 1;
		}

		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			//check if user has closed window
			if (event.type == SDL_QUIT) {
				//exit loop
				loop = false;
			}


			mouseHandler.update(&event);
		}

		//sets up menu button textures
		menu->set_renderer(renderer);
		menu->drawmenu();//NEEDS TO CHANGE - currently continues to make and destroy textures instead of using a set of textures

		//draw the game
		SDL_RenderPresent(renderer);
	}

	//cleanup
	SDL_DestroyTexture(backgroundTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//shut down sdl subsystems
	SDL_Quit();

	return 0;
}