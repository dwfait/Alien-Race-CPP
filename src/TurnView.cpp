#include "TurnView.h"

TurnView::TurnView(void)
{
	playersTurn = true;
	this->image = ImageManager::get()->getImage("Images/yourturn.bmp");
}

TurnView::~TurnView(void)
{
}


void TurnView::updateTurn(bool turn)
{
	if (turn != playersTurn)
	{
		if ( turn == true)
		{
			this->image = ImageManager::get()->getImage("Images/yourturn.bmp");
		} else this->image = ImageManager::get()->getImage("Images/notyourturn.bmp");
		playersTurn = turn;
	}
}

