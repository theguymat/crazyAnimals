#include "MouseHandler.h"


MouseHandler::MouseHandler()
{
}


MouseHandler::~MouseHandler()
{
}

void MouseHandler::update(SDL_Event* event) {

	if (event->motion.x >= 100 && event->motion.x <= 250 && event->motion.y >= 300 && event->motion.y <= 360) {//check button position
		menu->button1 = true;//change button state to change its colour
	}
	else if (event->motion.x >= 100 && event->motion.x <= 430 && event->motion.y >= 400 && event->motion.y <= 460) {
		menu->button2 = true;
	}
	else if (event->motion.x >= 100 && event->motion.x <= 240 && event->motion.y >= 500 && event->motion.y <= 560) {
		menu->button3 = true;
	}
	else
	{
		//will reset button state when it is not being hovered over
		menu->button1 = false;
		menu->button2 = false;
		menu->button3 = false;
	}
}