#pragma once
class Direction
{
public:
	Direction();
	~Direction();

	int DirectionX();
	int DirectionY();

	void setUp();
	void setDown();
	void setRight();
	void setLeft();
	bool isUp();
	bool isDown();
	bool isLeft();
	bool isRight();


private:
	int mDirectionX;
	int mDirectionY;
};




