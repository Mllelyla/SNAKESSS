#pragma once
class Level
{
public:
	Level(int number);
	float updateMsBetweenMovement();
	float calcMsBetweenMovement();
	int levelNumber();
	void setlevelNumber(int niveau);
	float getMsBetweenMovement();

private:
	float mMsBetweenMovement;
	int mNumber;

};

