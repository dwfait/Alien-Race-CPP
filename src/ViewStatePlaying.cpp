#include "ViewStatePlaying.h"







void ViewStatePlaying::startState()
{
	game->startGame();
	gridView = boost::shared_ptr<GridView>(new GridView(game->getGrid()));
	gridView->createView();
	humanScore.setPosition(Point2D(499,98),Point2D(549,98));
	aiScore.setPosition(Point2D(498,192),Point2D(548,192));
	remaining.setPosition(Point2D(498,293),Point2D(548,293));
	turn.updatePosition(Point2D(531,396));
}



void ViewStatePlaying::updateState(SDL_Surface* screen)
{
	gridView->updateAndDraw(screen);
	humanScore.updateScore(game->getHumanScore());
	aiScore.updateScore(game->getAIScore());
	humanScore.draw(screen);
	aiScore.draw(screen);
	turn.updateTurn(game->isPlayersTurn());
	turn.updateAndDraw(screen);
	remaining.updateScore(game->getGrid()->getRemainingBombs());
	remaining.draw(screen);
}

void ViewStatePlaying::stopState()
{

}

void ViewStatePlaying::updateInput(InputState& state)
{
	if (state.leftMouseHit == true) // exit button, crude but it works.
	{
		if ((state.mouseCoord.x >= 515) && ( state.mouseCoord.x <= 576) && (state.mouseCoord.y >= 503) && (state.mouseCoord.y <= 538)) // exit button
			state.exit = true;
		if ((state.mouseCoord.x >= 520) && ( state.mouseCoord.x <= 569) && (state.mouseCoord.y >= 454) && (state.mouseCoord.y <= 489)) // new game
			game->startPreGame();
	}
	gridView->setShowSquares(state.rightMouseDown);
	game->updateHuman(state,gridView->squareCoordFromMouse(state.mouseCoord));
	game->getGrid()->updateState(state,gridView->squareCoordFromMouse(state.mouseCoord));
}