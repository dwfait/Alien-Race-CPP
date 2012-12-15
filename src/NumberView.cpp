#include "NumberView.h"

NumberView::NumberView(void)
{
}

NumberView::~NumberView(void)
{
}


void NumberView::updateNumber(int num)
{
	if ((num<0) || (num>9)) throw Exception("Displaying number that is out of range: " +num);

	this->image = ImageManager::get()->getImage("Images/Numbers/" +toString<int>(num)+".bmp");



}