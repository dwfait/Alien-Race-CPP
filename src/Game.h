#pragma once
#include "Grid.h"
#include "ImageManager.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include <boost/shared_ptr.hpp>
#include "InputState.h"

enum GameState
{
	PREGAME,INSTRUCTIONS,PLAYING,POSTGAME
};


class Game
{
private:
	boost::shared_ptr<AIPlayer>	aiPlayer;
	boost::shared_ptr<HumanPlayer> humanPlayer;
	boost::shared_ptr<Player> currentPlayer;
	boost::shared_ptr<Grid>		grid;
	void swapPlayers();

	GameState state;
public:
	void startGame();
	void update();
	Game(void);
	virtual ~Game(void);
	GameState getState();
	boost::shared_ptr<Grid> getGrid();
	void updateHuman(InputState& state,Point2D square);
	
	void startPreGame();
	void startInstructions();

	int getHumanScore();
	int getAIScore();
	bool isPlayersTurn();
	
};
