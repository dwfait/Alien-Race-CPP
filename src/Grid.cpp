#include "Grid.h"

Grid::Grid(void)
{
}

Grid::~Grid(void)
{
}

void Grid::clearGrid()
{
	GridType::iterator it = grid.begin();
	
	for (;it != grid.end();++it)
	{
		(*it).clear();
	}
	grid.clear();
}

void Grid::createSquares()
{
	grid.resize(columns);

	GridType::iterator it = grid.begin();
	for (;it != grid.end();++it)
	{
		for (int i = 0; i < rows; ++i)
		{
			(*it).push_back(boost::shared_ptr<Square>(new Square()));
		}
	}

}
/**
void Grid::placeBombs()
{
	srand(SDL_GetTicks());
	int bombsPlaced = 0;
    while (true)
    {
        for(int c = 0;c<columns;++c)
		{
			for (int r = 0;r<rows;++r)
			{

				int randomNumber = rand() % 8;
				if (randomNumber > 6)
				{
					if (grid[c][r]->bomb == false)
					{
						grid[c][r]->bomb = true;
						++bombsPlaced;
						if (bombsPlaced == bombs) return;
					}
				}
				
			}
        }
    }
}
**/

void Grid::placeBombs()
{
	srand(SDL_GetTicks());
	int bombsPlaced = 0;
    while (bombsPlaced < bombs)
    {
		int chance = rand() % 10;
		if (chance > 8)
		{
			int randX = rand() % columns;
			int randY = rand() % rows;
			if (grid[randX][randY]->bomb == false)
			{
				grid[randX][randY]->bomb = true;
				++bombsPlaced;
			}
		}
	}
}

void Grid::generateNumbers()
{
	for (int c = 0;c<columns;++c)
	{
		for (int r = 0;r < rows;++r)
		{
			int counter = 0;
			
			for (int x = c - 1;x <= c + 1; ++x)
			{
				for (int y = r - 1; y <= r + 1; ++y)
				{
					if ( ( (x >= 0) && (x < columns) ) && ( (y >= 0) && (y < rows) ) && ( !( (y == r) && (x == c) ) ) )
					{
						if ( grid[x][y]->bomb == true ) counter++;
					}
				}
				grid[c][r]->surroundingBombs = counter;

			}
		}
	}

}

void Grid::populateGrid()
{
	Settings* settings = SettingsManager::get();
	columns = settings->columns;
	rows	= settings->rows;
	bombs = (columns * rows) / 5;
	if ((bombs % 2 == 0)) ++bombs;

	this->bombsRemaining	= bombs;
	shouldBeDown = false;
	clearGrid();
	createSquares();
	placeBombs();
	generateNumbers();


}

int Grid::getBombs()
{
	return bombs;
}
int Grid::getRemainingBombs()
{
	return bombsRemaining;
}
Point2D Grid::getRandomSquare()
{
	while(true)
	{
		int c = rand() % columns;
		int r = rand() % rows;
		
		if (grid[c][r]->uncovered == false)
			return Point2D(c,r);
	}
}

void Grid::mouseDown(Point2D& square)
{
	if ((square.x < 0 || square.x > columns-1) || (square.y < 0 || square.y > rows-1))
	return;
	squareDown.x = square.x;
	squareDown.y = square.y;
	grid[squareDown.x][squareDown.y]->mouseDown = true;
	shouldBeDown = true;

}

int Grid::mouseUp(Point2D& square)
{
	if ((square.x < 0 || square.x > columns-1) || (square.y < 0 || square.y > rows-1))
		return -1;
	shouldBeDown = false;
	grid[squareDown.x][squareDown.y]->mouseDown = false;
	if ((squareDown.x != square.x) || (squareDown.y != square.y)) return -1;

	if (grid[square.x][square.y]->uncovered == true)
		return -1;

	if(grid[square.x][square.y]->surroundingBombs == 0)
		emptyCascade(square);

	grid[square.x][square.y]->uncovered = true;


	if (grid[square.x][square.y]->bomb == true)
	{
		--bombsRemaining;
		return 1;
	}



	
	return 0;

}

const GridType& Grid::getGrid()
{
	return grid;

}



void Grid::emptyCascade(Point2D &square)
{
	if ((square.x < 0 || square.x > columns-1) || (square.y < 0 || square.y > rows-1))
		return;
	if((grid[square.x][square.y]->uncovered == true) || (grid[square.x][square.y]->bomb == true))
		return;
	if(grid[square.x][square.y]->surroundingBombs == 0)
	{
		grid[square.x][square.y]->uncovered=true;
		emptyCascade(Point2D(square.x-1,square.y));
		emptyCascade(Point2D(square.x+1,square.y));
		emptyCascade(Point2D(square.x,square.y-1));
		emptyCascade(Point2D(square.x,square.y+1));


	}



}



void Grid::updateState(InputState& state, Point2D& square)
{
	if (shouldBeDown == true)
	{
		if ((squareDown.x == square.x) && (squareDown.y == square.y))
		{
			grid[squareDown.x][squareDown.y]->mouseDown = true;
		} else {
			grid[squareDown.x][squareDown.y]->mouseDown = false;
		}

	}
	


}