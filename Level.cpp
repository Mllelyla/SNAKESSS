#include "Level.h"
#include "Snake.h"
#include "math.h"

Level::Level(int number)//int number
	: mNumber{ number },
	mMsBetweenMovement{ calcMsBetweenMovement() }
{
}

int Level::levelNumber() { return mNumber; }
void Level::setlevelNumber(int niveau) { mNumber = niveau; }

float Level::updateMsBetweenMovement()
{
	mMsBetweenMovement = calcMsBetweenMovement();
	return mMsBetweenMovement;
}

float Level::getMsBetweenMovement() //getter
{
	return mMsBetweenMovement;
}

float Level::calcMsBetweenMovement()
{
	return 150 - pow(.95, mNumber);
	//return 200 - (40 * (mNumber - 1));
}

