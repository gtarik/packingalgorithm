#include "Rectangle.h"
#include <algorithm>

int Rectangle::getHeight() {
	return height;
}

int Rectangle::getWidth() {
	return width;
}

void Rectangle::setParameters(int a, int b)
{
	height = a;
	width = b;
}

Rectangle::~Rectangle()
{

}

std::vector<Rectangle> Rectangle::SortRectangles(std::vector<Rectangle> rectVect)
{
	std::vector< Rectangle > rect_copy = rectVect;
	std::sort(rect_copy.begin(), rect_copy.end(), std::greater <>());
	return rect_copy;
}