#include "ViewStatePreGame.h"



void ViewStatePreGame::startState()
{
	btn99.updatePosition(Point2D(75,229));
	btn1313.updatePosition(Point2D(75,300));
	btn1717.updatePosition(Point2D(75,371));
	btnEasy.updatePosition(Point2D(350,229));
	btnNormal.updatePosition(Point2D(350,300));
	btnPerfect.updatePosition(Point2D(350,371));

	btn99.setSize(Point2D(175,50));
	btn1313.setSize(Point2D(175,50));
	btn1717.setSize(Point2D(175,50));
	btnEasy.setSize(Point2D(175,50));
	btnNormal.setSize(Point2D(175,50));
	btnPerfect.setSize(Point2D(175,50));

	btn99.unClick();btn1313.unClick();btn1717.unClick();
	btnEasy.unClick();btnNormal.unClick();btnPerfect.unClick();

	currentGrid = 0;
	currentDifficulty = 0;
	logo.setImagePath("Images/logomini.bmp");
	logo.updatePosition(Point2D(403,499));
	playBtn.setImagePath("");
	playBtn.updatePosition(Point2D(206,465));
}



void ViewStatePreGame::updateState(SDL_Surface* screen)
{
	preGameView.updateAndDraw(screen);
	btn99.updateAndDraw(screen);
	btn1313.updateAndDraw(screen);
	btn1717.updateAndDraw(screen);
	btnEasy.updateAndDraw(screen);
	btnNormal.updateAndDraw(screen);
	btnPerfect.updateAndDraw(screen);
	logo.updateAndDraw(screen);
	playBtn.updateAndDraw(screen);

}

void ViewStatePreGame::stopState()
{

}

void ViewStatePreGame::updateInput(InputState& state)
{
	if (state.leftMouseHit == true)
	{



		Button* newGrid = 0,*newDifficulty = 0;

		if (btn99.click(state.mouseCoord)) newGrid = &btn99;
		if (btn1313.click(state.mouseCoord)) newGrid = &btn1313;
		if (btn1717.click(state.mouseCoord)) newGrid = &btn1717;

		if (btnEasy.click(state.mouseCoord)) newDifficulty = &btnEasy;
		if (btnNormal.click(state.mouseCoord)) newDifficulty = &btnNormal;
		if (btnPerfect.click(state.mouseCoord)) newDifficulty = &btnPerfect;

		if (newGrid != 0)
		{
			if (currentGrid != 0) 
			{
				if (currentGrid != newGrid)
				{
					currentGrid->unClick();
					currentGrid = newGrid;
				}
			} else {
				currentGrid = newGrid;
			}
		}

		if (newDifficulty != 0)
		{

			if (currentDifficulty != 0) 
			{
				if (currentDifficulty != newDifficulty)
				{
					currentDifficulty->unClick();
					currentDifficulty = newDifficulty;					
				}
			} else {
				currentDifficulty = newDifficulty;
			}
		}
			

	}
	if (currentDifficulty && currentGrid) 
	{
		playBtn.setImagePath("Images/play.bmp");
		if (state.leftMouseHit == true)
		{
			if ((state.mouseCoord.x >= 212) && ( state.mouseCoord.x <= 382) && (state.mouseCoord.y >= 471) && (state.mouseCoord.y <= 505))
			{
				Settings* settings = SettingsManager::get();
				if (btn99.getState())
				{settings->rows = 9; settings->columns = 9;}
				if (btn1313.getState())
				{settings->rows = 13; settings->columns = 13;}
				if (btn1717.getState())
				{settings->rows = 17; settings->columns = 17;}

				if (btnEasy.getState())
					settings->difficulty = 1;
				if (btnNormal.getState())
					settings->difficulty = 2;
				if (btnPerfect.getState())
					settings->difficulty = 3;
				game->startInstructions();
			}
		}
	}
}