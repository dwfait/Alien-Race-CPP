#include "NewAIPlayer.h"

NewAIPlayer::NewAIPlayer(boost::shared_ptr<Grid> grid) : Player(grid)
{

}

NewAIPlayer::~NewAIPlayer(void)
{
}


NewAIPlayer::reset()
{
	AITimer = 0;
	moveInterval = 2000;
	clickTimer = 0;
	score = 0;

	createWeights();
	

	Settings* settings = SettingsManager::get();
	rows		= settings->rows;
	columns		= settings->columns;
	difficulty	= settings->difficulty;

}


bool AIPlayer::getSquare()
{
	if (mouseDown == false)
	{
		if (AITimer + moveInterval < SDL_GetTicks()) 
		{

			chooseSquare();
			if (weights[currentSquare.x][currentSquare.y].weight == 0) currentSquare = grid->getRandomSquare();
			while (weights[currentSquare.x][currentSquare.y].possible == false)
			{
				currentSquare = grid->getRandomSquare();
			}


			clickTimer = SDL_GetTicks();
			mouseDown = true;
			grid->mouseDown(currentSquare);

		}
	} else {
		if (clickTimer + 100 < SDL_GetTicks())
		{
			mouseDown = false;
			resetWeights();
			resetTimer();
			return true;
		}

	}
	return false;
}


void AIPlayer::resetTimer()
{
	AITimer = SDL_GetTicks() + ((rand() %2000) - 1000);
}

void AIPlayer::createWeights()
{

	weights.clear();
	weights.resize(columns);
	GridWeight::iterator it = weights.begin();

	for (;it!=weights.end();++it)
	{
		(*it).resize(rows);
	}

}


void AIPlayer::resetWeights()
{

	GridWeight::iterator it = weights.begin();
	InnerGridWeight::iterator innerIt;
	for (;it!=weights.end();++it)
	{
		for(innerIt = (*it).begin();innerIt!=(*it).end();++innerIt)
		{
			(*innerIt).weight	= 0;
		}
	}
}




void AIPlayer::calculateWeights()
{

	GridType grid = this->grid->getGrid();
	


	for (int c = 0;c < columns;++c)
	{
		for (int r = 0; r < rows;++r)
		{
			if (grid[c][r]->uncovered == false)
				continue;
			if (grid[c][r]->bomb == true)
				continue;

			int covered;
			int potentialBombs = getPotentialBombs(grid,c,r,covered);

			if (potentialBombs == 0)
			{
				setImpossible(grid,c,r);
				continue;
			}
			if (covered == 0)
			{
				continue;
			}
			setWeight(grid,c,r,((100*potentialBombs) / covered));
		
		}
	}
}



void NewAIPlayer::getRating(GridType& grid,int c,int r,int& possibleCovered,int& possibleBombs)
{
	possibleBombs = grid[c][r]->surroundingBombs;
	possibleCovered = 0;
	for (int x = c - 1;x <= c + 1; ++x)
	{
		for (int y = r - 1; y <= r + 1; ++y)
		{
			if  ( ((x >= 0) && (x < columns)) && ((y>=0) && (y < rows)))
			{
				if (!((y == r) && (x == c)))
				{
					if (grid[x][y]->uncovered == true)
					{
						if(grid[x][y]->bomb == true)
						{
							--potentialBombs;
						}

					} else {
						if (weights[x][y].possible == true)
							++possibleCovered;
					}
				}
			}
		}
	}
}


void AIPlayer::setWeight(GridType& grid,int c,int r,int weight)
{
	for (int x = c - 1;x <= c + 1; ++x)
	{
		for (int y = r - 1; y <= r + 1; ++y)
		{
			if ((x >= 0 && x < columns) && (y >=0 && y < rows) && (!((y == r) && (x == c))))
			{
				if(weights[x][y].possible == false) continue;

				if (grid[x][y]->uncovered == false)
				{
					if (weight > weights[x][y].weight)
						weights[x][y].weight = weight;
				}
			}
		}
	}
}

void AIPlayer::setImpossible(GridType& grid,int c,int r)
{
	for (int x = c - 1;x <= c + 1; ++x)
	{
		for (int y = r - 1; y <= r + 1; ++y)
		{
			if ((x >= 0 && x < columns) && (y >=0 && y < rows) && (!((y == r) && (x == c))))
			{
				weights[x][y].possible = false;
				addWeights(grid,x,y,10);
			}
		}
	}
}