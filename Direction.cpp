#include "Direction.h"



Direction::Direction()

	: mDirectionX{ 0 },
	mDirectionY{ 0 }
{
}


Direction::~Direction()
{
}

int Direction::DirectionX() { return mDirectionX; }
int Direction::DirectionY() { return mDirectionY; }

void Direction::setUp()
{
	mDirectionY = -1;
	mDirectionX = 0;
}

void Direction::setDown()
{
	mDirectionY = 1;
	mDirectionX = 0;
}

void Direction::setRight()
{
	mDirectionY = 0;
	mDirectionX = 1;
}

void Direction::setLeft()
{
	mDirectionY = 0;
	mDirectionX = -1;
}

bool Direction::isUp()
{
	if (mDirectionY == -1 && mDirectionX == 0)
		return true;
	else
		return false;
}

bool Direction::isDown()
{
	if (mDirectionY == 1 && mDirectionX == 0)
		return true;
	else
		return false;
}
bool Direction::isLeft()
{
	if (mDirectionY == 0 && mDirectionX == -1)
		return true;
	else
		return false;
}

bool Direction::isRight()
{
	if (mDirectionY == 0 && mDirectionX == 1)
		return true;
	else
		return false;
}

