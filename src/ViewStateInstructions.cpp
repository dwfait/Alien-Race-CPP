#include "ViewStateInstructions.h"

void ViewStateInstructions::startState()
{
	instructions.setImagePath("Images/instructions.bmp");
	instructions.updatePosition(Point2D(0,0));
}



void ViewStateInstructions::updateState(SDL_Surface* screen)
{
	instructions.updateAndDraw(screen);

}

void ViewStateInstructions::stopState()
{

}

void ViewStateInstructions::updateInput(InputState& state)
{
	if (state.leftMouseHit == true)
		if ((state.mouseCoord.x >= 212) && ( state.mouseCoord.x <= 382) && (state.mouseCoord.y >= 471) && (state.mouseCoord.y <= 505))
			game->startGame();
		
}