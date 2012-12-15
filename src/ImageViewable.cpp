#include "ImageViewable.h"

ImageViewable::ImageViewable(void)
{
}

ImageViewable::~ImageViewable(void)
{
}



void ImageViewable::setImagePath(std::string path)
{
	if (path != "")
	{
		allowDraw = true;
		this->image = ImageManager::get()->getImage(path);
	} else {
		this->allowDraw = false;
	}

}


