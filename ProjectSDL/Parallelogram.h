#ifndef PARALLELOGRAM_HEADER
#define PARALLELOGRAM_HEADER
#include "Triangle.h"

class Parallelogram : public Triangle
{
public:
	Parallelogram(int x, int y, int line1, int line2, int angle);
	Parallelogram(int x, int y, int line1, int line2, int angle, int r, int g, int b, int a);

	void drawParallelogram(SDL_Renderer* gRenderer);
};

#endif
