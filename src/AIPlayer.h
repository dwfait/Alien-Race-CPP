#pragma once
#include "player.h"
#include "SDL.h"
#include "SettingsManager.h"
#include <vector>
#include "Point2D.h"


#include <iostream>
class Weight
{
public:
	Weight(){weight = 0;possible = true;};
	~Weight(){};

	int weight;
	bool possible;
};



typedef std::vector< std::vector< Weight > > GridWeight;
typedef std::vector< Weight > InnerGridWeight;

class AIPlayer :
	public Player
{
protected:

	bool getSquare();
	unsigned int AITimer,moveInterval,clickTimer;
	GridWeight weights;

	int rows,columns,difficulty;

	std::vector<Point2D> highestWeightSquares;

	int maxWeight;

	void calculateWeights();
	void setWeight(GridType& grid,int c,int r,int weight);
	void createWeights();
	void resetWeights();
	void getRating(GridType& grid,int c,int r,int& possibleCovered,int& possibleBombs);
	void setImpossible(GridType& grid,int c,int r);


	void chooseSquare();
	
public:
	AIPlayer(boost::shared_ptr<Grid> grid);
	virtual ~AIPlayer(void);
	void resetTimer();
	void reset();
};
