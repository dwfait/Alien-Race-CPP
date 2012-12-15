#pragma once
#include "Viewable.h"
#include "Square.h"
#include <sstream>

class SquareView :
	public Viewable
{
private:
	bool uncovered,selected;
	boost::shared_ptr<Square> square;
	void update();
	void draw(SDL_Surface *screen);
	bool showDebug,mouseDown;
	void setImage();
public:
	SquareView(boost::shared_ptr<Square> square);
	virtual ~SquareView(void);

	void setShowDebug(bool show);

};
