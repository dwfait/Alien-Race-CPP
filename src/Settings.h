#pragma once

class Settings
{
public:
	Settings(void){};
	virtual ~Settings(void){};

	int rows,columns;
	size_t screenWidth,screenHeight;
	size_t squareWidth,squareHeight;
	int difficulty,gridSize;
	int delayTime;

};
