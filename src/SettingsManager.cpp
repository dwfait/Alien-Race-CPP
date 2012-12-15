#include "SettingsManager.h"


SettingsManager* SettingsManager::instance = 0;

SettingsManager::SettingsManager(void)
{
	settings = new Settings();
	/**FileParser tmp("settings.txt");
	try
	{
		settings->columns		= stringTo<size_t>(tmp.getValue("columns"));
		settings->rows			= stringTo<size_t>(tmp.getValue("rows"));
	} catch (BadConvert&)
	{
		throw Exception("Bad settings file.");
	}**/
	settings->columns	= 17;
	settings->rows		= 17;
	//std::cout << settings->columns;
	settings->delayTime = 20;
	
}

SettingsManager::~SettingsManager(void)
{
	delete settings;
}


Settings* SettingsManager::get()
{
	if (instance == 0)
		instance = new SettingsManager();
	return instance->settings;
}

void SettingsManager::destroy()
{
	if (instance != 0)
	{
		delete instance;
		instance = 0;
	}
}

