#define _USE_MATH_DEFINES
#include "Line.h"
#include <ostream>
#include <cmath>


Line::Line(int x, int y, int length, int angle) :
	Point(x, y),
	length_(length),
	angle_(angle)
{
	if (length < 0)
	{
		throw std::invalid_argument("Length < 0");
	}
}

Line::Line(int x, int y, int length, int angle, int r, int g, int b, int a):
	Point(x, y, r, g, b, a),
	length_(length),
	angle_(angle)
{
	if (length < 0)
	{
		throw std::invalid_argument("Length < 0");
	}
}

void Line::setLength(int length)
{
	length_ = length;
}

void Line::setAngle(int angle)
{
	angle_ = angle;
}

int Line::getLength() const
{
	return length_;
}

int Line::getAngle() const
{
	return angle_;
}

void Line::drawLine(SDL_Renderer* gRenderer)
{
	SDL_SetRenderDrawColor(gRenderer, getR(), getG(), getB(), getA());
	int x2 = getX() + getLength() * cos(getAngle()* M_PI / 180);
	int y2 = getY() + getLength() * sin(getAngle()* M_PI / 180);
	SDL_RenderDrawLine(gRenderer, getX(), getY(), x2, y2);
}