#pragma once

#include <boost/shared_ptr.hpp>
#include <string>
#include <map>
#include "Image.h"
#include "../resource.h"
#include "windows.h"


class ImageManager
{
private:
	 std::map<std::string,boost::shared_ptr<Image> > imageCache;


	Image* loadImage(std::string imagePath);
	ImageManager(void);
	virtual ~ImageManager(void);
	static ImageManager* instance;
public:
	
	static ImageManager* get();
	static void destroy();

	boost::shared_ptr<Image> getImage(std::string imagePath);

	void clearCache();

};
