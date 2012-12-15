#pragma once
#include <boost/shared_ptr.hpp>
#include "Image.h"
#include "SDL.h"
#include "ImageManager.h"
#include "Point2D.h"
#include <vector>

class Viewable
{
protected:

	boost::shared_ptr<Image> image;
	virtual void update() = 0;
	virtual void draw(SDL_Surface* screen) = 0;
	SDL_Rect position;
	void blit(SDL_Surface* screen);

	bool allowDraw;
public:
	Viewable(void);
	void updateAndDraw(SDL_Surface* screen);
	void updatePosition(Point2D pos);
	
	virtual ~Viewable(void);
};
