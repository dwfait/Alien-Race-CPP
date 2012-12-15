#pragma once
#include "viewstate.h"
#include "ImageViewable.h"
class ViewStateInstructions :
	public ViewState
{
private: 
	ImageViewable instructions;
public:
	ViewStateInstructions(boost::shared_ptr<Game> game) : ViewState(game) {};
	virtual ~ViewStateInstructions(void){};

	void startState();
	void updateState(SDL_Surface* screen);
	void stopState();
	void updateInput(InputState& state);
};
