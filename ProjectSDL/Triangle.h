#ifndef TRIANGLE_HEADER
#define TRIANGLE_HEADER
#include <SDL.h>
#include "Point.h"

class Triangle : public Point
{
public:
	Triangle(int x, int y, int line1, int line2, int angle);
	Triangle(int x, int y, int line1, int line2, int angle, int r, int g, int b, int a);
	void setLine1(int line1);
	void setLine2(int line2);
	void setAngle(int angle);

	int getLine1() const;
	int getLine2() const;
	int getAngle() const;

	void drawTriangle(SDL_Renderer* gRenderer);

private:
	int line1_;
	int line2_;
	int angle_;
};


#endif
