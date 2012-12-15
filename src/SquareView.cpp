#include "SquareView.h"

SquareView::SquareView(boost::shared_ptr<Square> square)
{
	this -> square = square;
	this -> uncovered	= square->uncovered;
	this -> showDebug = false;
	setImage();
}

SquareView::~SquareView(void)
{
}

void SquareView::draw(SDL_Surface *screen)
{
	
}


void SquareView::update()
{
	if ( (this->uncovered != square->uncovered) || (this->mouseDown != square->mouseDown) )
	{
		this->uncovered = square->uncovered;
		this->mouseDown = square->mouseDown;
		setImage();
	}

}


void SquareView::setShowDebug(bool show)
{
	this->showDebug = show;

	setImage();
}


void SquareView::setImage()
{
	ImageManager* imgMgr = ImageManager::get();
	
	
	

	if (uncovered == true || showDebug == true)
	{
		if (square->bomb == true)
		{
			image = imgMgr->getImage("Images/bomb.bmp");
		} else {
			std::string tmpPath = "Images/";
			std::stringstream tmpStream;
			tmpStream << square->surroundingBombs;
			tmpPath.append(tmpStream.str());
			tmpPath+=".bmp";
			image = imgMgr->getImage(tmpPath);
		}
	} else {
		if (mouseDown == true)
		{
			this->image = imgMgr->getImage("Images/clicked.bmp");
		} else {
			this->image = imgMgr->getImage("Images/uncovered.bmp");
		}
		
	}

	
}