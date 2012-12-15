#include "PreGameView.h"

PreGameView::PreGameView(void)
{
	ImageManager* imgMgr = ImageManager::get();
	this->image = imgMgr->getImage("Images/pregame.bmp");
}

PreGameView::~PreGameView(void)
{
}
