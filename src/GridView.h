#pragma once
#include "Viewable.h"
#include "SquareView.h"
#include <vector>
#include "Grid.h"
#include "Point2D.h"

class GridView :
	public Viewable
{
private:
	std::vector< boost::shared_ptr<SquareView> > squares;
	boost::shared_ptr<Grid> grid;
	void update();
	void draw(SDL_Surface* screen);
	Point2D offset,squareSize;
	bool showSquares;

public:
	GridView(boost::shared_ptr<Grid> grid);
	Point2D squareCoordFromMouse(Point2D mouseCoord);
	void createView();
	virtual ~GridView(void);
	void setShowSquares(bool show);
};
