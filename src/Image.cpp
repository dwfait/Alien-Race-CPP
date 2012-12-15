#include "Image.h"

Image::Image(void)
{
	image = 0;
}


Image::~Image(void)
{
	SDL_FreeSurface(image);
	std::cout << imagePath << " unloaded." << std::endl;

}
