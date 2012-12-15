#include "App.h"

App::App(void)
{
	game	= boost::shared_ptr<Game>(new Game());
	view	= boost::shared_ptr<View>(new View(game));
	input	= boost::shared_ptr<Input>(new Input(view));

	//game->startGame(15,15);

	view->setup();
}

void App::run()
{
	SettingsManager::get();
	while (input->getExit() == false)
	{
		input->update();
		game->update();
		view->update();
	}
	shutDown();
}

App::~App(void)
{
	shutDown();
}

void App::shutDown()
{
	SettingsManager::destroy();
	ImageManager::destroy();
}
