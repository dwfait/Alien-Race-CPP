#pragma once
#include "viewable.h"
#include "ImageManager.h"


class FinalScoreView :
	public Viewable
{
private:
	void update(){};
	void draw(SDL_Surface *screen){};
public:
	FinalScoreView(void);
	virtual ~FinalScoreView(void);

	void playerWon();
	void aiWon();
};
