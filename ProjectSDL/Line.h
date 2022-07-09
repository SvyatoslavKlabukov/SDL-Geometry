#ifndef LINE_HEADER
#define LINE_HEADER
#include <SDL.h>
#include "Point.h"

class Line : public Point
{
public:
	Line(int x, int y, int length, int angle);
	Line(int x, int y, int length, int angle, int r, int g, int b, int a);
	int getLength() const;
	int getAngle() const;

	void setLength(int width);
	void setAngle(int height);

	void drawLine(SDL_Renderer* gRenderer);

private:
	int length_;
	int angle_;
};

#endif