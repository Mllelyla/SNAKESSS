#pragma once
class Modifier
{
public:
	Modifier();
	~Modifier();

	int ModX();
	int ModY();

	void setUp();
	void setDown();
	void setRight();
	void setLeft();

private:
	int mModX;
	int mModY;
};




