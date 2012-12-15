#pragma once
#include "Settings.h"
#include "FileParser.h"
#include "Convert.h"
class SettingsManager
{
private:
	SettingsManager(void);
	static SettingsManager* instance;
	Settings* settings;
	virtual ~SettingsManager(void);
public:
	
	
	static Settings* get();
	static void destroy();


	
};
