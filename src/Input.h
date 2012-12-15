#pragma once
#include "View.h"
#include "Point2D.h"
#include <boost/shared_ptr.hpp>

#include "InputState.h"

class Input
{
private:
	boost::shared_ptr<View> view;
	
	InputState state;

	void pollInput();
public:
	Input(boost::shared_ptr<View> view);

	bool getExit();
	void update();

	virtual ~Input(void);
};
