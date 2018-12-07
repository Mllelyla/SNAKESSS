#include "Level.h"
#include "Snake.h"



Level::Level(int number)//int number
	: mNumber{ number }, 
	mMsBetweenMovement{ calcMsBetweenMovement()}
{
}

int Level::levelNumber() { return mNumber; }
void Level::setlevelNumber(int niveau) { mNumber = niveau; }


void Level::MsBetweenMovementMultiplier(int speedMultiplier) { mMsBetweenMovement *= speedMultiplier; } //setter custom

int Level::updateMsBetweenMovement() 
{
	mMsBetweenMovement = calcMsBetweenMovement();
	return mMsBetweenMovement;
}

int Level::getMsBetweenMovement() //getter
{
	return mMsBetweenMovement;
}

int Level::calcMsBetweenMovement()
{
	return 200 - (40*(mNumber-1));
}

