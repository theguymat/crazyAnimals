#include "MouseHandler.h"


MouseHandler::MouseHandler()
{
}


MouseHandler::~MouseHandler()
{
}

void MouseHandler::update(SDL_Event* event){

	if (event->motion.x >= /*object1->pos.x*/ && event->motion.x <= /*object1->pos.x + 60*/ && event->motion.y >= /*object1->pos.y*/ && event->motion.y <= /*object1->pos.y + 32*/){
		Menu->button1 = true;//change button state to change its colour
	}
	else if (event->motion.x >= /*object2->pos.x*/ && event->motion.x <= /*object2->pos.x + 60*/ && event->motion.y >= /*object2->pos.y*/ && event->motion.y <= /*object2->pos.y + 32*/){
		Menu->button2 = true;
	}
	else if (event->motion.x >= /*object3->pos.x*/ && event->motion.x <= /*object3->pos.x + 60*/ && event->motion.y >= /*object3->pos.y*/ && event->motion.y <= /*object3->pos.y + 32*/){
		Menu->button3 = true;
	}
	else
	{
		Menu->button1 = false;//reset all button states when not over button
		Menu->button2 = false;
		Menu->button3 = false;
	}
}