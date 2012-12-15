#pragma once
#include "viewable.h"
#include "Exception.h"
#include "Convert.h"

class NumberView :
	public Viewable
{
private:
	void update(){};
	void draw(SDL_Surface *screen){};
public:
	NumberView(void);

	void updateNumber(int num);

	virtual ~NumberView(void);
};
