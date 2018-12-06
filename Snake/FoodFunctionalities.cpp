#include "FoodFunctionalities.h"
#include "Position.h"
#include "Snake.h"
#include "Food.h"
#include "PrintBackground.h"
#include <stdlib.h>

FoodFunctionalities::FoodFunctionalities()
	: mFoodEaten{nullptr},
	//mFoodEaten{},
	mTypeFoodTouched{""},
	mPointsFoodTouched{}
{
}
Food* FoodFunctionalities::FoodEaten() { return mFoodEaten; }
std::string FoodFunctionalities::typeFoodTouched() { return mTypeFoodTouched; }
int FoodFunctionalities::pointsByTypeFood() { return mPointsFoodTouched; }


bool FoodFunctionalities::snakeTouchingFood(Snake theSnake, Food &theFood,Food &theFood2) {
	bool isFoodTouched;
	int headX = theSnake.currentHeadPos().x();
	int headY = theSnake.currentHeadPos().y();

	int Food1X = theFood.position().x();
	int Food1Y = theFood.position().y();

	int Food2X = theFood2.position().x();
	int Food2Y = theFood2.position().y();

	if (headX == Food1X && headY == Food1Y) {
		isFoodTouched = true;
		mFoodEaten = &theFood;
	}
	else
		if (headX == Food2X && headY == Food2Y) {
			isFoodTouched = true;
			mFoodEaten = &theFood2;
		}
	else 
		isFoodTouched = false;

	return isFoodTouched;
	}

Position FoodFunctionalities::newRandomFoodPosition(Snake theSnake) {

	Position pos;

	//s'assurer que la new food apparaisse dans les limites du jeu
	//s'assurer que la new food n'apparaisse pas sur le serpent 

	PrintBackground pbg;

	int xrand = rand() % (pbg.gameWidth() - 2) + pbg.gameX();
	int yrand = rand() % (pbg.gameHeight() - 2) + pbg.gameY();

	bool coordsValides = false;
	bool toutEstBeau = true;

	while (!coordsValides)
	{
		for (int i = 0; i < theSnake.snakeBody().size(); ++i)
		{
			if (theSnake.snakeBody().at(i).x() == xrand && theSnake.snakeBody().at(i).y() == yrand)
			{
				toutEstBeau = false;
				int xrand = rand() % (pbg.gameWidth() - 2) + pbg.gameX();
				int yrand = rand() % (pbg.gameHeight() - 2) + pbg.gameY();

			}
		}
		if (toutEstBeau)
		{
			coordsValides = true;
		}
	}

	pos.setCoords(xrand, yrand);
	return pos;
}

void FoodFunctionalities::snakeEatFood(Snake &theSnake, Food &theFoodTouched) {

		mTypeFoodTouched = theFoodTouched.type();
		mPointsFoodTouched = theFoodTouched.points();

		if (theFoodTouched.type()=="POISON")
			theSnake.setSnakePoisoned(true);
		if (theFoodTouched.type() == "NORMAL") //test
			theSnake.setSnakePoisoned(false);

		newRandomFoodStyle(theFoodTouched);  //piger une sorte de Food aleatoire

		theFoodTouched.setPosition(newRandomFoodPosition(theSnake));  //changer la position

}


void FoodFunctionalities::newRandomFoodStyle(Food &theFood) {

	int styleRand = rand() %2;

	if (styleRand == 0)
		theFood.setRandomApple();
	else
		theFood.setRandomBrocoli();
}
