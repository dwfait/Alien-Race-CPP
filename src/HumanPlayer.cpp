#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(boost::shared_ptr<Grid> grid) : Player(grid)
{
}

HumanPlayer::~HumanPlayer(void)
{
}


bool HumanPlayer::getSquare()
{
	return mouseUp;
}

void HumanPlayer::updateState(InputState& state,Point2D& square)
{
	this->mouseDown = state.leftMouseHit;
	this->mouseUp	= state.leftMouseUp;
	this->currentSquare.x = square.x;
	this->currentSquare.y = square.y;
}