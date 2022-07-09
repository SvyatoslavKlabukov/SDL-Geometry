#include "Triangle.h"
#include <ostream>

Triangle::Triangle(int x, int y, int line1, int line2, int angle) :
	Point(x, y),
	line1_(line1),
	line2_(line2),
	angle_(angle)
{
	if (line1 <= 0)
	{
		throw std::invalid_argument("Line1 <= 0");
	}
	if (line2 <= 0)
	{
		throw std::invalid_argument("Line2 <= 0");
	}
}

Triangle::Triangle(int x, int y, int line1, int line2, int angle, int r, int g, int b, int a) :
	Point(x, y, r, g, b, a),
	line1_(line1),
	line2_(line2),
	angle_(angle)
{
	if (line1 <= 0)
	{
		throw std::invalid_argument("Line1 <= 0");
	}
	if (line2 <= 0)
	{
		throw std::invalid_argument("Line2 <= 0");
	}
}

void Triangle::setLine1(int line1)
{
	line1_ = line1;
}

void Triangle::setLine2(int line2)
{
	line2_ = line2;
}

void Triangle::setAngle(int angle)
{
	angle_ = angle;
}

int Triangle::getLine1() const
{
	return line1_;
}

int Triangle::getLine2() const
{
	return line2_;
}

int Triangle::getAngle() const
{
	return angle_;
}

void Triangle::drawTriangle(SDL_Renderer* gRenderer)
{
	SDL_SetRenderDrawColor(gRenderer, getR(), getG(), getB(), getA());
	int x2 = getX() + getLine1() * cos(getAngle() * M_PI / 180);
	int y2 = getY() + getLine1() * sin(getAngle() * M_PI / 180);
	SDL_RenderDrawLine(gRenderer, getX(), getY(), x2, y2);
	int x3 = getX() + getLine2();
	int y3 = getY();
	SDL_RenderDrawLine(gRenderer, getX(), getY(), x3, y3);
	SDL_RenderDrawLine(gRenderer, x2, y2, x3, y3);
}