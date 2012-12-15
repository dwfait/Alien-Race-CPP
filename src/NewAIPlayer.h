#pragma once
#include "player.h"
#include "SDL.h"
#include "SettingsManager.h"
#include <vector>


class Weight
{
public:
	Weight(){weight = 0;possible = true;};
	~Weight(){};

	int weight;
	bool possible;

	int possibleBombs,possibleCovered;
};



typedef std::vector< std::vector< Weight > > GridWeight;
typedef std::vector< Weight > InnerGridWeight;


class NewAIPlayer :
	public Player
{
protected:
	int columns,rows,difficulty;
	void reset();
	bool getSquare();
	unsigned int AITimer,moveInterval,clickTimer;
	GridWeight weights;

	void chooseSquare;
	void calculateWeights();
	void setWeight(GridType& grid,int c,int r,int weight);
	void createWeights();
	void resetWeights();
	void getRating(GridType& grid,int c,int r,int& possibleCovered,int& possibleBombs);
	void setImpossible(GridType& grid,int c,int r);
	int difficulty;
public:
	NewAIPlayer(boost::shared_ptr<Grid> grid);
	virtual ~NewAIPlayer(void);
	void resetTimer();
};
