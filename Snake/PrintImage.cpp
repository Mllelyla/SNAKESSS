#include "PrintImage.h"
#include "Game.h"
#include <string>
#include <iostream>

PrintImage::PrintImage()

	: mSnake{},
	mFood{},
	mSnakeFlash {false}

{
}
Snake PrintImage::snake() { return mSnake; };
Food PrintImage::food() { return mFood; }

void PrintImage::drawSnake(Snake theSnake, ConsoleImage &Image)
{
	//serpent tourne vert et "pseudo flash" s'il est empoisonné
	ConsoleColor colorTemp;
	if (theSnake.snakeFrozen() && !mSnakeFlash) {
		colorTemp = ConsoleColor::tG;
		mSnakeFlash =  true ;
	}
	else
		if (theSnake.snakeFrozen() && mSnakeFlash) {
			colorTemp = ConsoleColor::tg;
			mSnakeFlash = false;
	}
	else
		//colorTemp = ConsoleColor::tR; //test
		colorTemp = theSnake.color();

	for (unsigned i = 0; i < theSnake.snakeBody().size(); i++)
	{
		if (i == theSnake.snakeBody().size() - 1) {
			Image.drawPoint(size_t(theSnake.snakeBody().at(i).x()), size_t(theSnake.snakeBody().at(i).y()), char(178), ConsoleColor::tg); //tete
		}
		else
			Image.drawPoint(size_t(theSnake.snakeBody().at(i).x()), size_t(theSnake.snakeBody().at(i).y()), theSnake.symbol(), colorTemp); //corps
	}
}

void PrintImage::drawFood(Food theFood,ConsoleImage &Image)
{

	Image.drawPoint(size_t(theFood.position().x()), size_t(theFood.position().y()), theFood.symbol(), theFood.color());
}

void PrintImage::drawStats( Snake &snake, int &score, int &currentlevel, ConsoleImage &Image ) {
	std::string snakestate;
	//score related text
	Image.drawText(size_t(19), size_t(9), "SCORE TOTAL = "+std::to_string(score), ConsoleColor::ty);

	//level related text
	Image.drawText(size_t(40), size_t(9), "LEVEL = "+std::to_string(currentlevel), ConsoleColor::ty);

	//state snake
	if (snake.snakeFrozen())
		snakestate= "POISONED"; 
	else
		snakestate= "NORMAL"; 

	Image.drawText(size_t(19), size_t(11), "SNAKE STATE = "+snakestate, ConsoleColor::ty);

}

void PrintImage::drawAll(Snake snake, Food food,Food food2, ConsoleImage &Image) {
	PrintImage::drawSnake(snake, Image);
	PrintImage::drawFood(food, Image);
	PrintImage::drawFood(food2, Image);
}