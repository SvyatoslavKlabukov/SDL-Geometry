#pragma once
#include "Point.h"

class Circle : public Point
{
public:
	Circle(int x, int y, double radius);
	Circle(int x, int y, double radius, int r, int g, int b, int a);
	double getRadius() const;

	void setRadius(double radius);

	void drawCircle(SDL_Renderer* gRenderer);

	//алгоритм Брезенхэма (для рисования линий на экране)
	static void drawPixel(SDL_Renderer* gRenderer, int xc, int yc, int x, int y);
	static void circleBres(SDL_Renderer* gRenderer, int xc, int yc, int radius);

private:
	double radius_;
};

