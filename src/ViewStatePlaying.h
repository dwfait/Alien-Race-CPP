#pragma once
#include "ViewState.h"
#include "GridView.h"
#include "ScoreView.h"
#include "TurnView.h"

class ViewStatePlaying :
	public ViewState
{
private:
	boost::shared_ptr<GridView> gridView;
	ScoreView humanScore,aiScore,remaining;
	TurnView turn;
public:
	ViewStatePlaying(boost::shared_ptr<Game> game) : ViewState(game) {};
	virtual ~ViewStatePlaying(void){};

	void startState();
	void updateState(SDL_Surface* screen);
	void stopState();
	void updateInput(InputState& state);
};
