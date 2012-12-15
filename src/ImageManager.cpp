#include "ImageManager.h"

ImageManager* ImageManager::instance = 0;

ImageManager::ImageManager(void)
{
}


ImageManager* ImageManager::get()
{
	if (instance == 0)
		instance = new ImageManager();
	return instance;
}

void ImageManager::destroy()
{
	if (instance != 0)
	{
		delete instance;
		instance = 0;
	}
}

Image* ImageManager::loadImage(std::string imagePath)
{
	Image* image = new Image();

	image->imagePath = imagePath;

	image->image = SDL_LoadBMP(imagePath.c_str());

    if (!image->image)
    {
		throw Exception(imagePath+ ": unable to load.");
    }
	SDL_SetColorKey(image->image,SDL_SRCCOLORKEY, 0xFF00FF);
	image->height = image->image->h;
	image->width  = image->image->w;

	return image;
}

boost::shared_ptr<Image> ImageManager::getImage(std::string imagePath)
{
	std::map<std::string,boost::shared_ptr<Image> >::iterator iter;

	iter = imageCache.find(imagePath);

	if (iter != imageCache.end())
	{
		return iter->second;
	}
	
	//Image* img = loadImage(imagePath);

	boost::shared_ptr<Image> imgPtr(loadImage(imagePath));



	imageCache.insert(std::pair<std::string,boost::shared_ptr<Image> >(imagePath,imgPtr));

	return imgPtr;

}


void ImageManager::clearCache()
{
	imageCache.clear();
}


ImageManager::~ImageManager(void)
{
}
