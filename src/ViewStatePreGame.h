#pragma once
#include "ViewState.h"
#include "PreGameView.h"
#include "Button.h"

#include "ImageViewable.h"


class ViewStatePreGame :
	public ViewState
{
private:
	PreGameView preGameView;
	
	ImageViewable logo,playBtn;
	Button btn99,btn1313,btn1717,btnEasy,btnNormal,btnPerfect;
	Button* currentGrid,*currentDifficulty;
public:
	ViewStatePreGame(boost::shared_ptr<Game> game) : ViewState(game) {};
	virtual ~ViewStatePreGame(void){};

	void startState();
	void updateState(SDL_Surface* screen);
	void stopState();
	void updateInput(InputState& state);
	

};
