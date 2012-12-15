#pragma once

#include "SDL.h"
#include <string>
#include "Exception.h"
#include <iostream>


class Image
{
public:

	SDL_Surface* image;
	std::string imagePath;

	size_t width,height;

	Image(void);

	virtual ~Image(void);
};
