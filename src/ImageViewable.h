#pragma once
#include "viewable.h"
#include <string>
#include "ImageManager.h"

class ImageViewable :
	public Viewable
{
private:
	void update(){};
	void draw(SDL_Surface *screen){};
public:
	ImageViewable(void);
	void setImagePath(std::string path);
	virtual ~ImageViewable(void);

};
