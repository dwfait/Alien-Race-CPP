#include "Game.h"

Game::Game(void)
{
	grid			= boost::shared_ptr<Grid>(new Grid());
	aiPlayer		= boost::shared_ptr<AIPlayer>(new AIPlayer(grid));
	humanPlayer		= boost::shared_ptr<HumanPlayer>(new HumanPlayer(grid));
	state			= PREGAME;
}



void Game::startGame()
{
	aiPlayer->reset();
	humanPlayer->reset();
	currentPlayer	= humanPlayer;
	state			= PLAYING;
	
	grid->populateGrid();
}

void Game::update()
{
	if(state == PLAYING)
	{
		if ( currentPlayer->getScore() > (grid->getBombs()/2))
				state = POSTGAME;
		if (currentPlayer->move())
		{
			swapPlayers();
		}


	}
	


}

Game::~Game(void)
{
}


boost::shared_ptr<Grid> Game::getGrid()
{
	return grid;

}


void Game::updateHuman(InputState& state, Point2D square)
{
	humanPlayer->updateState(state,square);
}


void Game::swapPlayers()
{
	if(currentPlayer == humanPlayer)
	{
		currentPlayer = aiPlayer;
		aiPlayer->resetTimer();
	} else {
		currentPlayer = humanPlayer;
	}
}

GameState Game::getState()
{
	return state;
}

void Game::startPreGame()
{
	state = PREGAME;
}

void Game::startInstructions()
{
	state = INSTRUCTIONS;
}

int Game::getHumanScore()
{
	return humanPlayer->getScore();
}


int Game::getAIScore()
{
	return aiPlayer->getScore();
}


bool Game::isPlayersTurn()
{
	return (currentPlayer == humanPlayer);
}
