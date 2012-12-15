#include "Viewable.h"

Viewable::Viewable(void)
{
	allowDraw = true;
}

Viewable::~Viewable(void)
{
}


void Viewable::updateAndDraw(SDL_Surface *screen)
{
	update();
	blit(screen);
	draw(screen);
	
}


void Viewable::updatePosition(Point2D pos)
{
	this->position.x = pos.x;
	this->position.y = pos.y;
}


void Viewable::blit(SDL_Surface* screen)
{
	if (allowDraw)
	{
		if(image)SDL_BlitSurface(image->image, 0, screen, &position);
	}
}