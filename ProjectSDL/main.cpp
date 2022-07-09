//Для черчения фигур используем динамическую библиотеку SDL(simple directmedia layer) http://www.libsdl.org/
#include <SDL.h>
#include <stdio.h>
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Triangle.h"
#include "Parallelogram.h"

//размеры окна
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//запускаем SDL и создаем окно
bool init();

//освобождаем ресурсы и выходим из SDL
void close();

//Объявляем окно
SDL_Window* gWindow = NULL;

//Объявляем экранную поверхность
SDL_Surface* gScreenSurface = NULL;

//визуализатор окна(чтобы можно было создавать текстуры)
SDL_Renderer* gRenderer = NULL;

//инициализируем SDL и создаем окно
bool init();

//освобождаем ресурсы и выходим из SDL
void close();


int main(int argc, char* args[])
{
	//запускаем SDL 
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//флаг отслеживает вышел ли пользователь
		bool quit = false;

		//обработчик события
		SDL_Event e;

		//пока приложение работает
		while (!quit)
		{
			//опрашиваем очередь событий
			while (SDL_PollEvent(&e) != 0)
			{
				//проверка на выход пользователя из программы
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
			//очистка экрана
			//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); //отвечает за фон(белый)
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF); //отвечает за фон(черный)
			SDL_RenderClear(gRenderer);
			
			//создание прямоугольника
			Rectangle rect(SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8, SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, 0xFF, 0xFF, 0xFF, 0xFF);
			Rectangle rect2(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 8, SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6);
			rect.drawRectangle(gRenderer);
			rect2.drawRectangle(gRenderer);

			//создание точки
			Point point1(SCREEN_WIDTH / 8, SCREEN_HEIGHT / 2);
			Point point2(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2, 0xFF, 0xFF, 0x00, 0xFF);
			Point point3(SCREEN_WIDTH / 8, 11*SCREEN_HEIGHT / 20);
			Point point4(SCREEN_WIDTH / 4, 11*SCREEN_HEIGHT / 20, 0x00, 0xFF, 0xFF, 0xFF);
			//Point point3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
			//Point point4(11*SCREEN_WIDTH / 20, SCREEN_HEIGHT / 2, 0x00, 0xFF, 0xFF, 0xFF);
			point1.drawPoint(gRenderer);
			point2.drawPoint(gRenderer);
			point3.drawPoint(gRenderer);
			point4.drawPoint(gRenderer);

			//создание круга
			int radius = 30;
			Circle circle1(SCREEN_WIDTH / 8, 5 * SCREEN_HEIGHT / 6, radius, 0x00, 0x00, 0xFF, 0xFF);
			circle1.drawCircle(gRenderer);

			//создание окружности, алгоритм Брезенхэма
			radius = 90;
			//circleBres - статический метод класса, принадлежит не конкретному объекту, а самому классу
			Circle::circleBres(gRenderer, SCREEN_WIDTH / 3, 3 * SCREEN_HEIGHT / 4, radius);

			//создание линии под углом к горизонту
			int length = 80;
			int angle = 90;
			Line line1( 11*SCREEN_WIDTH / 20, SCREEN_HEIGHT / 8, length, angle, 0xFF, 0xFF, 0x00, 0xFF);
			angle = 120;
			Line line2( 3*SCREEN_WIDTH / 4, SCREEN_HEIGHT / 8, length, angle, 0x00, 0xFF, 0x00, 0xFF);
			angle = 30;
			Line line3(4 * SCREEN_WIDTH / 5, SCREEN_HEIGHT / 8, length, angle, 0x00, 0x00, 0xFF, 0xFF);
			line1.drawLine(gRenderer);
			line2.drawLine(gRenderer);
			line3.drawLine(gRenderer);

			//создание треугольника
			int lineTriangle1 = 50;
			int lineTriangle2 = 50;
			int triangleAngle = 60;
			Triangle triangle1( 2 * SCREEN_WIDTH / 3, 3 * SCREEN_HEIGHT / 4, lineTriangle1, lineTriangle2, triangleAngle);
			triangle1.drawTriangle(gRenderer);
			lineTriangle1 = 100;
			lineTriangle2 = 140;
			triangleAngle = -90;
			Triangle triangle2(2 * SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2, lineTriangle1, lineTriangle2, triangleAngle, 0xFF, 0xFF, 0xFF, 0xFF);
			triangle2.drawTriangle(gRenderer);

			//создание параллелограмма
			int lineParallelogram1 = 85;
			int lineParallelogram2 = 100;
			int angleParallelogram2 = -45;
			Parallelogram parallelogram1(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2, lineParallelogram1, lineParallelogram2, angleParallelogram2, 0x00, 0xFF, 0xFF, 0xFF);
			parallelogram1.drawParallelogram(gRenderer);
			
			//обновление экрана
			SDL_RenderPresent(gRenderer);
		}
	}
	close();

	return 0;
}

bool init()
{
	//флаг
	bool success = true;

	//инициализируем SDL (нельзя вызывать какие-либо функции SDL без предварительной инициализации SDL)
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Создаем окно
		gWindow = SDL_CreateWindow("SDL Geometry", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//получаем поверхность окна, чтобы можно было рисовать на ней
			//gScreenSurface = SDL_GetWindowSurface(gWindow);

			//создаем средство визуализации
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//инициализируем цвет визуализации (рендеринга)

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				//SDL_RenderClear(gRenderer);
				//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
				//SDL_RenderPresent(gRenderer);
			}
		}
	}

	return success;
}

void close()
{

	//уничтожаем окно
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Выход из подсистемы
	SDL_Quit();
}