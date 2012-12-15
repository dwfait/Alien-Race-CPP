#pragma once
#include <boost/shared_ptr.hpp>
#include "Game.h"
#include "GridView.h"
#include "SettingsManager.h"
#include "ImageManager.h"

#include "ViewState.h"
#include "ViewStatePreGame.h"
#include "ViewStatePlaying.h"
#include "ViewStatePostGame.h"
#include "ViewStateInstructions.h"


class View
{
private:
	boost::shared_ptr<Game> game;
	
	SDL_Surface* screen;

	
	
	void setupWindow(size_t x,size_t y);

	void setupState();


	GameState localState;

	ViewStatePtr currentState;
	ViewStatePtr preGameState;
	ViewStatePtr playingState;
	ViewStatePtr postGameState;
	ViewStatePtr instructionsState;


public:
	View(boost::shared_ptr<Game> game);

	void update();
	void updateInput(InputState& state);



	void setup();

	virtual ~View(void);
};
