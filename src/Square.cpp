#include "Square.h"

Square::Square(void)
{
	surroundingBombs = 0;
	bomb = false;
	uncovered = false;

	mouseDown = false;
}

Square::~Square(void)
{
}


