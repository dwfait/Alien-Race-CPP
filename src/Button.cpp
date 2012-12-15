#include "Button.h"

Button::Button(void)
{
	clicked = false;
	clickedPath = "Images/buttonclicked.bmp";
	unClickedPath = "";
}

Button::~Button(void)
{
}



void Button::setImageClicked(std::string imgPath)
{
	this->clickedPath = imgPath;
}

void Button::setImageUnclicked(std::string imgPath)
{
	this->unClickedPath = imgPath;
}


bool Button::click(Point2D mousePosition)
{
	if (clicked == false)
	{
		if ((mousePosition.x >= position.x) && ( mousePosition.x <= (position.x + size.x)) && (mousePosition.y >= position.y) && (mousePosition.y <= (position.y + size.y)))
		{
			if (clickedPath != "")
			{
				this->image = ImageManager::get()->getImage(clickedPath);
				allowDraw = true;
			} else {
				allowDraw = false;
			}
			clicked = true;
			return true;
		}
		
	}
	return false;
}


void Button::unClick()
{
	if (clicked == true)
	{

		if (unClickedPath != "")
		{
			this->image = ImageManager::get()->getImage(unClickedPath);
			allowDraw = true;
		} else {
			allowDraw = false;
		}
		clicked = false;
	
	}
}


void Button::setSize(Point2D size)
{
	this->size.x		= size.x;
	this->size.y		= size.y;
}





bool Button::getState()
{
	return clicked;
}