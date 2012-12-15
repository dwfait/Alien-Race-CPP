#include "FinalScoreView.h"

FinalScoreView::FinalScoreView(void)
{
}

FinalScoreView::~FinalScoreView(void)
{
}


void FinalScoreView::playerWon()
{
	this->image = ImageManager::get()->getImage("Images/youwin.bmp");
}

void FinalScoreView::aiWon()
{
	this->image = ImageManager::get()->getImage("Images/youlose.bmp");
}
