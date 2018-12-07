
#ifndef PRINTIMAGE_H
#define PRINTIMAGE_H
#include "Food.h"
#include "ConsoleImage.h"
#include "Snake.h"

class PrintImage
{
public:
	PrintImage();

	Snake snake();
	Food food();

	void drawSnake(Snake snake,ConsoleImage &Image); //avec reference & image , &snake, &food ?
	void drawFood(Food food, ConsoleImage &Image);
	void drawAll(Snake snake, Food food,Food food2, ConsoleImage &Image);
	void drawStats(Snake &snake, int &score, int &currentlevel, int &freezeCountDown, ConsoleImage &Image);

private:
	Snake mSnake;
	Food mFood;
	bool mSnakeFlash;
};


#endif 

