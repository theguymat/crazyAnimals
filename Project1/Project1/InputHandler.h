#pragma once
#include <SDL.h>
#include "Menu.h"
class InputHandler
{
public:
	Menu * menu;// Class identifier

	InputHandler();
	~InputHandler();


	virtual void update(SDL_Event* event) = 0;
};

