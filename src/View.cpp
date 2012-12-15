#include "View.h"

View::View(boost::shared_ptr<Game> game)
{
	this->game = boost::shared_ptr<Game>(game);

	ImageManager* imgMgr = ImageManager::get();
	boost::shared_ptr<Image> tmp = imgMgr->getImage("Images/uncovered.bmp");
	Settings* config = SettingsManager::get();
	config->squareWidth = tmp->width;
	config->squareHeight = tmp->height;
	setupWindow(600, 550);
	
	preGameState = ViewStatePtr(new ViewStatePreGame(game));
	playingState = ViewStatePtr(new ViewStatePlaying(game));
	postGameState = ViewStatePtr(new ViewStatePostGame(game));
	instructionsState = ViewStatePtr(new ViewStateInstructions(game));
	currentState = preGameState;
}

View::~View(void)
{
	SDL_Quit( );
}


void View::setup()
{
	setupState();


}
void View::setupState()
{
	if(currentState)currentState->stopState();
	switch(game->getState())
	{
	case PREGAME:
		currentState = preGameState;
		break;
	case INSTRUCTIONS:
		currentState = instructionsState;
		break;
	case PLAYING:
		currentState = playingState;
		break;
	case POSTGAME:
		currentState = postGameState;
		break;
	}
	this->localState = game->getState();
	currentState->startState();
}

void View::update()
{
	if (localState != game->getState())
	{
		setupState();
	}

	currentState->updateState(screen);
	

	SDL_Flip(screen);
	SDL_FillRect( screen, NULL, 0 );
	Settings* config = SettingsManager::get();
	SDL_Delay(config->delayTime);

}

void View::updateInput(InputState& state)
{
	currentState->updateInput(state);
}









void View::setupWindow(size_t x,size_t y)
{
	
	SDL_Quit();
	screen = SDL_SetVideoMode(x, y, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		SDL_Quit( );
		throw Exception("Can not initialise video");
	}
	Settings* settings = SettingsManager::get();
	settings->screenWidth = x;
	settings->screenHeight = y;
	SDL_WM_SetCaption("Alien Race - Someone Studios",NULL);
	
}