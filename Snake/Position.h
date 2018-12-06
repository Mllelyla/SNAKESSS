#pragma once
class Position
{
public:
	Position();
	Position(int x, int y);


	int x();
	int y();

	void setCoords(int x, int y);

private:

	int mX;
	int mY;

};

