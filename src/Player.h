#pragma once


#include <boost/shared_ptr.hpp>
#include "Grid.h"
#include "Point2D.h"


class Player
{
protected:


	boost::shared_ptr<Grid> grid;
	int score;
	Point2D currentSquare;
	virtual bool getSquare() = 0;
	bool mouseDown,mouseUp;
	bool clickOnSquare(Point2D& square);

public:
	Player(boost::shared_ptr<Grid> grid);
	virtual ~Player(void);

	int getScore();
	virtual void reset();

	bool move();
};


typedef boost::shared_ptr<Player> PlayerPtr;