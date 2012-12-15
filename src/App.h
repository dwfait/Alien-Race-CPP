#pragma once
#include <boost/shared_ptr.hpp>

#include "Game.h"
#include "View.h"
#include "Input.h"

#include "SettingsManager.h"

class App
{
private:

	boost::shared_ptr<Game> game;
	boost::shared_ptr<View> view;
	boost::shared_ptr<Input> input;
	
	void shutDown();
public:

	App(void);
	~App(void);
	void run();
};
