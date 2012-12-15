#pragma once
#include "viewable.h"

class TurnView :
	public Viewable
{
private:
	void update(){};
	void draw(SDL_Surface *screen){};
	bool playersTurn;
public:
	TurnView(void);
	void updateTurn(bool turn);
	virtual ~TurnView(void);
};
