#pragma once

class InputState
{
public:
	InputState(){};
	~InputState(){};
	bool leftMouseHit;
	bool leftMouseUp;
	bool rightMouseDown;
	Point2D mouseCoord;

	bool anyKey;
	bool anyMouseButton;
	bool exit;
};
