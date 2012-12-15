#include "Player.h"

Player::Player(boost::shared_ptr<Grid> grid)
{
	this->grid = grid;
	score = 0;
	mouseDown = false;
	mouseUp = false;
}


int Player::getScore()
{
	return score;
}

void Player::reset()
{
	score = 0;
}
Player::~Player(void)
{
}
bool Player::move()
{
	if (this->mouseDown == true) grid->mouseDown(currentSquare);
	if (getSquare() == true)
		return clickOnSquare(currentSquare);
	return false;
}

bool Player::clickOnSquare(Point2D &square)
{
	int result = grid->mouseUp(square);

	switch(result)
	{
	case -1:
		//Selected an already clicked square and do nothing
		//Or the player moused up on a different square
		break;
	case 0:
		//no bomb
		return true;
		break;
	case 1:
		//bomb
		++score;
		return false;
		break;
	}

	return false;
}