#pragma once
#include "viewable.h"

class PostGameView :
	public Viewable
{
private:
	void update(){};
	void draw(SDL_Surface *screen){};
public:
	PostGameView(void);
	virtual ~PostGameView(void);
};
