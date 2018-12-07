#include "Position.h"



Position::Position(int x, int y)

	: mX{ x }, mY{ y }
{
}

Position::Position()

	: mX{ 0 }, mY{ 0 }
{
}

int Position::x() { return mX; }
int Position::y() { return mY; }

void Position::setCoords(int x, int y)
{
	mX = x;
	mY = y;
};
