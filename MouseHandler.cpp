#include "MouseHandler.h"


MouseHandler::MouseHandler()
{
}


MouseHandler::~MouseHandler()
{
}

void MouseHandler::update(SDL_Event* event){

	if (event->motion.x >= 100 && event->motion.x <= 250 && event->motion.y >= 100 && event->motion.y <= 160){
		Menu->button1 = true;//change button state to change its colour
	}
	else if (event->motion.x >= 100 && event->motion.x <= 430 && event->motion.y >= 200 && event->motion.y <= 260){
		Menu->button2 = true;
	}
	else if (event->motion.x >= 100 && event->motion.x <= 240 && event->motion.y >= 300 && event->motion.y <= 360){
		Menu->button3 = true;
	}
	else
	{
		Menu->button1 = false;
		Menu->button2 = false;
		Menu->button3 = false;
	}
}