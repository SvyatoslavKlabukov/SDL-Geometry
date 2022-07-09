#include "Circle.h"
#include <ostream>
#include <cmath>

Circle::Circle(int x, int y, double radius) :
	Point(x, y),
	radius_(radius)
{
	if (radius <= 0)
	{
		throw std::invalid_argument("Radius is less or equals to 0");
	}
}

Circle::Circle(int x, int y, double radius, int r, int g, int b, int a) :
	Point(x, y, r, g, b, a),
	radius_(radius)
{
	if (radius <= 0)
	{
		throw std::invalid_argument("Radius is less or equals to 0");
	}
}

void Circle::setRadius(double radius)
{
	radius_ = radius;
}

double Circle::getRadius() const
{
	return radius_;
}

void Circle::drawCircle(SDL_Renderer* gRenderer)
{
	SDL_SetRenderDrawColor(gRenderer, getR(), getG(), getB(), getA());

	// Рисование круга
	for (int x = getX() - radius_; x <= getX() + radius_; x++) {
		for (int y = getY() - radius_; y <= getY() + radius_; y++) {
			if ((pow(getY() - y, 2) + pow(getX() - x, 2)) <= pow(radius_, 2)) 
			{
				SDL_RenderDrawPoint(gRenderer, x, y);
			}
		}
	}
}

//расставляет 8 точек вокруг точки (xc, yc)
void Circle::drawPixel(SDL_Renderer* gRenderer, int xc, int yc, int x, int y)
{
	SDL_RenderDrawPoint(gRenderer, xc+x, yc+y);
	SDL_RenderDrawPoint(gRenderer, xc-x, yc+y);
	SDL_RenderDrawPoint(gRenderer, xc+x, yc-y);
	SDL_RenderDrawPoint(gRenderer, xc-x, yc-y);
	SDL_RenderDrawPoint(gRenderer, xc+y, yc+x);
	SDL_RenderDrawPoint(gRenderer, xc-y, yc+x);
	SDL_RenderDrawPoint(gRenderer, xc+y, yc-x);
	SDL_RenderDrawPoint(gRenderer, xc-y, yc-x);
}

void Circle::circleBres(SDL_Renderer* gRenderer, int xc, int yc, int radius)
{
	int x = 0, y = radius;
	int d = 3 - 2 * y;
	while (x <= y)
	{
		Circle::drawPixel(gRenderer, xc, yc, x, y);
		//проверяем параметр решения и соответствующим образом обновляем d, x, y
		if (d < 0)
		{
			d = d + 4 * x + 6;
		}
		else
		{
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}