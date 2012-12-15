#include "ViewStatePostGame.h"




void ViewStatePostGame::startState()
{
	postGameView.updatePosition(Point2D(0,0));

	if (game->getHumanScore() > game->getAIScore())
	{
		score.playerWon();
	} else {
		score.aiWon();
	}

	score.updatePosition(Point2D(85,79));

}



void ViewStatePostGame::updateState(SDL_Surface* screen)
{
	postGameView.updateAndDraw(screen);
	score.updateAndDraw(screen);
}

void ViewStatePostGame::stopState()
{

}

void ViewStatePostGame::updateInput(InputState& state)
{
	if (state.leftMouseHit == true)
		if ((state.mouseCoord.x >= 157) && ( state.mouseCoord.x <= 442) && (state.mouseCoord.y >= 384) && (state.mouseCoord.y <= 469))
			game->startPreGame();
		
}