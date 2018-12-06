#include "Modifier.h"



Modifier::Modifier()

	: mModX{ 0 },
	mModY{ 0 }
{
}


Modifier::~Modifier()
{
}

int Modifier::ModX() { return mModX; }
int Modifier::ModY() { return mModY; }

void Modifier::setUp()
{
	mModY = -1;
	mModX = 0;
}

void Modifier::setDown()
{
	mModY = 1;
	mModX = 0;
}

void Modifier::setRight()
{
	mModY = 0;
	mModX  = 1;
}

void Modifier::setLeft()
{
	mModY = 0;
	mModX = -1;
}