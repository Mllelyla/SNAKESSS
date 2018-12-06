#include "Food.h"
#include "FoodFunctionalities.h"
#include <vector>
#include "PrintBackground.h"

Food::Food()
	:mColor{},
	mPosition{},
	mSymbol{},
	mType{},
	mPoints{1}
{
}
ConsoleColor Food::color() { return mColor; }
Position Food::position() { return mPosition; }
char Food::symbol() { return mSymbol; }
int Food::points() { return mPoints; }
std::string  Food::type() { return mType; }


void Food::setCustomFood(ConsoleColor color, char symbol, int x, int y) {
	mPosition.setCoords(x, y); 
	mColor = color;
	mSymbol = symbol;
}

void Food::setRandomBrocoli() {
	//mPosition.setCoords(30,25);  //pour l'instant fixe, mais on voudrait aleatoire p-e
	mColor = ConsoleColor::bG;
	mSymbol = '@';
	mPoints = 3;
	mType = "POISON";
}

void Food::setRandomApple() {
	//mPosition.setCoords(40, 35);  //pour l'instant fixe, mais on voudrait aleatoire p-e
	mColor = ConsoleColor::bR;
	mSymbol = '$';
	mPoints = 1;
	mType = "NORMAL";
}

void Food::setPosition(Position position) {
	mPosition = position;
}

