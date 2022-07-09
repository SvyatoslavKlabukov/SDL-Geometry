#ifndef RECTANGLE_HEADER
#define RECTANGLE_HEADER
#include <SDL.h>
#include "Point.h"

class Rectangle : public Point
{
public:
	Rectangle(int x, int y, int width, int height);
	Rectangle(int x, int y, int width, int height, int r, int g, int b, int a);
	int getWidth() const;
	int getHeight() const;

	void setWidth(int width);
	void setHeight(int height);

	void drawRectangle(SDL_Renderer* gRenderer);

private:
	int width_;
	int height_;
};

#endif
