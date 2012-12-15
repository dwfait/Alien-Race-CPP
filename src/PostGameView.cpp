#include "PostGameView.h"

PostGameView::PostGameView(void)
{
	ImageManager* imgMgr = ImageManager::get();
	this->image = imgMgr->getImage("Images/postgame.bmp");
}

PostGameView::~PostGameView(void)
{
}
