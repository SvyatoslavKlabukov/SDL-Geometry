#include "Parallelogram.h"


Parallelogram::Parallelogram(int x, int y, int line1, int line2, int angle):
	Triangle::Triangle(x, y, line1, line2, angle)
{}

Parallelogram::Parallelogram(int x, int y, int line1, int line2, int angle, int r, int g, int b, int a):
	Triangle::Triangle(x, y, line1, line2, angle, r, g, b, a)
{}

void Parallelogram::drawParallelogram(SDL_Renderer* gRenderer)
{
	SDL_SetRenderDrawColor(gRenderer, getR(), getG(), getB(), getA());
	int x2 = getX() + getLine1() * cos(getAngle() * M_PI / 180);
	int y2 = getY() + getLine1() * sin(getAngle() * M_PI / 180);
	SDL_RenderDrawLine(gRenderer, getX(), getY(), x2, y2);
	int x3 = getX() + getLine2();
	int y3 = getY();
	SDL_RenderDrawLine(gRenderer, getX(), getY(), x3, y3);
	int x4 = x2 + getLine2();
	int y4 = y2;
	SDL_RenderDrawLine(gRenderer, x2, y2, x4, y4);
	SDL_RenderDrawLine(gRenderer, x4, y4, x3, y3);
}