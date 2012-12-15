#pragma once
#include "viewable.h"

class PreGameView :
	public Viewable
{
private:
	void update(){};
	void draw(SDL_Surface *screen){};
public:
	PreGameView(void);
	virtual ~PreGameView(void);
};
