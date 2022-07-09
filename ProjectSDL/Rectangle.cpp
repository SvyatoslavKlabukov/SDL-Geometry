#include "Rectangle.h"
#include <ostream>


Rectangle::Rectangle(int x, int y, int width, int height): 
	Point(x, y),
	width_(width),
	height_(height)
{
	if (width == 0)
	{
		throw std::invalid_argument("Width equals 0");
	}
	if (height == 0)
	{
		throw std::invalid_argument("Height equals 0");
	}
}


Rectangle::Rectangle(int x, int y, int width, int height, int r, int g, int b, int a) :
	Point(x, y, r, g, b, a),
	width_(width),
	height_(height)
{
	if (width == 0)
	{
		throw std::invalid_argument("Width equals 0");
	}
	if (height == 0)
	{
		throw std::invalid_argument("Height equals 0");
	}
}


void Rectangle::setWidth(int width)
{
	width_ = width;
}

void Rectangle::setHeight(int height)
{
	height_ = height;
}

int Rectangle::getWidth() const
{
	return width_;
}

int Rectangle::getHeight() const
{
	return height_;
}

void Rectangle::drawRectangle( SDL_Renderer* gRenderer)
{
	SDL_Rect fillRect = {getX(), getY(), width_, height_ };
	SDL_SetRenderDrawColor(gRenderer, getR(), getG(), getB(), getA());
	SDL_RenderFillRect(gRenderer, &fillRect);
}