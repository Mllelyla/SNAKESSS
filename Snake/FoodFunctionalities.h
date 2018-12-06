#include "Snake.h"
#include "Position.h"
#include "Food.h"

class FoodFunctionalities
{
public:
	FoodFunctionalities();
	Food* FoodEaten();
	//Food  FoodEaten();
	std::string typeFoodTouched();

Position newRandomFoodPosition(Snake theSnake);
void newRandomFoodStyle(Food &theFood);
int pointsByTypeFood();

bool snakeTouchingFood(Snake theSnake, Food &theFood, Food &theFood2);
void snakeEatFood(Snake &theSnake, Food &theFood);

private:
	Food * mFoodEaten;
	//Food mFoodEaten;
	std::string mTypeFoodTouched;
	int mPointsFoodTouched;
};

