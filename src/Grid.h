#pragma once

#include <vector>
#include <boost/shared_ptr.hpp>
#include "Square.h"
#include "SDL.h"
#include "Point2D.h"
#include "SettingsManager.h"
#include "InputState.h"

typedef std::vector< std::vector< boost::shared_ptr<Square> > > GridType;
typedef std::vector< boost::shared_ptr<Square> > InnerGridType;
class Grid
{
private:


	int columns,rows;
	int bombs,bombsRemaining;

	void clearGrid();
	void createSquares();
	void placeBombs();
	void generateNumbers();
	void emptyCascade(Point2D& square);

	Point2D squareDown;
	bool shouldBeDown;

	GridType grid;
public:

	Grid(void);
	
	void populateGrid();
	int getBombs();
	int getRemainingBombs();
	Point2D getRandomSquare();
	int mouseUp(Point2D& square);
	void mouseDown(Point2D& square);
	virtual ~Grid(void);
	void updateState(InputState& state,Point2D& square);

	const GridType& getGrid();
};
