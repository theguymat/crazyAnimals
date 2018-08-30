#pragma once
#include "InputHandler.h"
class MouseHandler :
	public InputHandler
{
public:
	MouseHandler();
	~MouseHandler();

	//override
	void update(SDL_Event* event);
};

