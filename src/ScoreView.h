#pragma once
#include "Player.h"
#include "Point2D.h"
#include "NumberView.h"

class ScoreView
{
private:
	PlayerPtr player;
	NumberView firstNum,secondNum;
public:
	ScoreView();
	void setPosition(Point2D first,Point2D second);
	void updateScore(int score);
	void draw(SDL_Surface* screen);

	virtual ~ScoreView(void);
};
