#pragma once
class Level
{
public:
	Level(int number);
	int updateMsBetweenMovement();
	int calcMsBetweenMovement();
	int levelNumber();
	void setlevelNumber(int niveau);
	void MsBetweenMovementMultiplier(int ms);
	int getMsBetweenMovement();

private:
	int mMsBetweenMovement;
	int mNumber;

};

