#include "ScoreView.h"

ScoreView::ScoreView(void)
{

}

void ScoreView::setPosition(Point2D first,Point2D second)
{
	firstNum.updatePosition(first);
	secondNum.updatePosition(second);
}

ScoreView::~ScoreView(void)
{
}



void ScoreView::updateScore(int score)
{
	if ((score < 0) || (score > 99)) throw Exception("Score out of range: "+score);
	firstNum.updateNumber(score/10);
	secondNum.updateNumber(score%10);



}


void ScoreView::draw(SDL_Surface* screen)
{
	firstNum.updateAndDraw(screen);
	secondNum.updateAndDraw(screen);
}