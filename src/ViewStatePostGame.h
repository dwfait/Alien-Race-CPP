#pragma once
#include "ViewState.h"
#include "PostGameView.h"
#include "FinalScoreView.h"

class ViewStatePostGame :
	public ViewState
{
private:
	PostGameView postGameView;
	FinalScoreView score;
public:
	ViewStatePostGame(boost::shared_ptr<Game> game) : ViewState(game) {};
	virtual ~ViewStatePostGame(void){};

	void startState();
	void updateState(SDL_Surface* screen);
	void stopState();
	void updateInput(InputState& state);
};
