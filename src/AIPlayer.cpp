#include "AIPlayer.h"

AIPlayer::AIPlayer(boost::shared_ptr<Grid> grid) : Player(grid)
{
}

AIPlayer::~AIPlayer(void)
{
}


void AIPlayer::reset()
{
	AITimer = 0;
	moveInterval = 2000;
	clickTimer = 0;
	score = 0;
	maxWeight = 0;
	Settings* settings = SettingsManager::get();
	rows		= settings->rows;
	columns		= settings->columns;
	difficulty	= settings->difficulty;
	createWeights();
}


bool AIPlayer::getSquare()
{
	if (mouseDown == false)
	{
		if (AITimer + moveInterval < SDL_GetTicks()) 
		{

			calculateWeights();

			chooseSquare();

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


void AIPlayer::chooseSquare()
{
	highestWeightSquares.clear();
	highestWeightSquares.resize(0);
	int minWeight = 0;
	//std::cout << "Difficulty: " << difficulty << std::endl;
	if (difficulty == 1)
	{
		minWeight = maxWeight - 40;
	}
	else if (difficulty == 2)
	{
		minWeight = maxWeight - 20;
	}
	else if (difficulty == 3)
	{
		minWeight = maxWeight;
	}
	//std::cout << minWeight <<  " : " << maxWeight << std::endl;
	for (int c = 0;c < columns;++c)
	{
		for (int r = 0; r < rows;++r)
		{
			if (weights[c][r].possible == true)
			{
				//std::cout << weights[c][r].weight << std::endl;
				if ((weights[c][r].weight >= minWeight) && (weights[c][r].weight <= maxWeight))
				{
					highestWeightSquares.push_back(Point2D(c,r));
					//std::cout << c <<  " push back " << r << std::endl;
				}
			}	
		}
	}
	//std::cout << "Before" << std::endl;
	int size = highestWeightSquares.size();
	//std::cout << "After size: " <<size << std::endl;
	
	int randomNumber = rand();
	//std::cout << "After rand" << std::endl;
	int chosen = randomNumber % size;
	//std::cout << "After mod" << std::endl;
	currentSquare = highestWeightSquares[chosen];
	
	//currentSquare = highestWeightSquares.at(chosen);			
	//std::cout << "After allocation" << std::endl;
	
	maxWeight = 0;
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
			weights[c][r].possible = false;
			if (grid[c][r]->bomb == true)
				continue;

			int covered,potentialBombs;
			getRating(grid,c,r,covered,potentialBombs);

			if ((potentialBombs == 0) || (covered == 0))
			{
				setImpossible(grid,c,r);
				continue;
			}

			
			float step1 = static_cast<float>(potentialBombs);
			float step2 = static_cast<float>(covered);
			float step3 = step1 / step2;
			float step4 = step3 * 100;
			int step5	= static_cast<int>(step4);

			setWeight(grid,c,r,step5);
		
		}
	}
}



void AIPlayer::getRating(GridType& grid,int c,int r,int& possibleCovered,int& possibleBombs)
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
							--possibleBombs;
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
					if (weight > maxWeight)
						maxWeight = weight;
				}
			}
		}
	}
}

void AIPlayer::setImpossible(GridType& grid,int c,int r)
{
	int set = 1;
	if ( difficulty == 1)
	{
		set = rand() % 2;
	}
	for (int x = c - 1;x <= c + 1; ++x)
	{
		for (int y = r - 1; y <= r + 1; ++y)
		{
			if ((x >= 0 && x < columns) && (y >=0 && y < rows) && (!((y == r) && (x == c))))
			{
				if (set==1) weights[x][y].possible = false;
				if (difficulty == 3) setWeight(grid,x,y,30);
			}
		}
	}
}