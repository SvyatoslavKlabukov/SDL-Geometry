#pragma once
#include <SDL.h>

class Point
{
public:
	Point(int x, int y);
	Point(int x, int y, int r, int g, int b, int a);
	int getX() const;
	int getY() const;
	int getR() const;
	int getG() const;
	int getB() const;
	int getA() const;

	void setX(int x);
	void setY(int y);
	void setR(int r);
	void setG(int g);
	void setB(int b);
	void setA(int a);

	void drawPoint(SDL_Renderer* gRenderer);

private:
	int x_;
	int y_;
	//цвет в RGBA (красный по умолчанию)
	int r_ = 0xFF;
	int g_ = 0x00;
	int b_ = 0x00;
	int a_ = 0xFF;
};
