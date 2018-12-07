
#ifndef SNAKE_H
#define SNAKE_H
#include <string>
#include <vector>
#include "Position.h"
#include "Direction.h"
#include "ConsoleColor.h"
class Snake
{
public:
	Snake();

	ConsoleColor color();
	Position currentHeadPos();
	int direction();
	bool state();
	int length();
	int speed();
	char symbol();
	std::vector<Position> snakeBody();


	void newSnake(ConsoleColor color, char symbol, Position position, int length);
	void setColor(ConsoleColor color);
	void setState(bool state);
	void setSpeed(int speed);
	void setDirection(int direction);
	void setSymbol(char symbol);
	void addToHead(Direction theDirection);
	void removeFromTail();
	bool touchesItself();

	bool snakePoisonned();
	void setSnakePoisoned(bool poisoned);

	bool outOfBounds();
	bool isDead();
	

private:
	ConsoleColor mColor;
	Position mCurrentHeadPos;
	bool mState;
	int mDirection;
	int mSpeed;
	char mSymbol;
	bool mSnakePoisoned;
	std::vector<Position> mSnakeBody;
};


#endif 

