#ifndef FOOD_H
#define FOOD_H
#include "Position.h"
#include "ConsoleColor.h"
#include <vector>
class Food
{
public:
	Food();
	ConsoleColor color();
	char symbol();
	Position position();
	int points();
	std::string type();

	void setCustomFood(ConsoleColor color, char symbol, int xDepart, int yDepart);

	void setRandomApple();
	void setRandomBrocoli();

	void setPosition(Position position);


private:
	ConsoleColor mColor;
	Position mPosition;
	char mSymbol;
	int mPoints;
	std::string mType;

};

#endif 