#pragma once
#include "Viewable.h"
#include "Point2D.h"
#include "ImageManager.h"


#include <string>



class Button :
	public Viewable
{
private:
	std::string clickedPath,unClickedPath;
	bool clicked;
	void update(){};
	void draw(SDL_Surface *screen){};
	Point2D size;
public:
	Button(void);
	virtual ~Button(void);

	void setImageClicked(std::string imgPath);
	void setImageUnclicked(std::string imgPath);
	
	bool click(Point2D mousePosition);
	void unClick();

	void setSize(Point2D size);

	bool getState();


};
