#pragma once

#include <boost/shared_ptr.hpp>

#include "Game.h"
#include "InputState.h"
#include "SDL.h"


class ViewState
{
protected:
	boost::shared_ptr<Game> game;
public:
	ViewState(boost::shared_ptr<Game> game) {this->game = game;};
	virtual ~ViewState(void) {};

	virtual void startState() = 0;
	virtual void updateState(SDL_Surface* screen) = 0;
	virtual void stopState() = 0;
	virtual void updateInput(InputState& state) = 0;
};

typedef boost::shared_ptr<ViewState> ViewStatePtr;