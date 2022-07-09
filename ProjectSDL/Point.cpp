#include "Point.h"
#include <ostream>


Point::Point(int x, int y) :
	x_(x),
	y_(y)
{}

Point::Point(int x, int y, int r, int g, int b, int a) :
	x_(x),
	y_(y),
	r_(r),
	g_(g),
	b_(b),
	a_(a)
{}

void Point::setX(int x)
{
	x_ = x;
}

void Point::setY(int y)
{
	y_ = y;
}

void Point::setR(int r)
{
	r_ = r;
}

void Point::setG(int g)
{
	g_ = g;
}

void Point::setB(int b)
{
	b_ = b;
}

void Point::setA(int a)
{
	a_ = a;
}

int Point::getX() const
{
	return x_;
}

int Point::getY() const
{
	return y_;
}


int Point::getR() const
{
	return r_;
}

int Point::getG() const
{
	return g_;
}

int Point::getB() const
{
	return b_;
}

int Point::getA() const
{
	return a_;
}

void Point::drawPoint(SDL_Renderer* gRenderer)
{
	//устанавливаем цвет точки
	SDL_SetRenderDrawColor(gRenderer, r_, g_, b_, a_);
	//рисуем точку
	SDL_RenderDrawPoint(gRenderer, x_, y_);
}