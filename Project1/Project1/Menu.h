#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


using namespace std;

class Menu
{
public:
	bool button1 = false;
	bool button2 = false;
	bool button3 = false;
	SDL_Renderer* renderer;

	Menu();
	~Menu();

	void set_renderer(SDL_Renderer* renderer);

	void drawmenu();
	

	void startGame();
	void showLeadBord();
	void Quit();
};