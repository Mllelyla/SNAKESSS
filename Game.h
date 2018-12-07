
#include "Level.h"
#include "Snake.h"
#include "ElapsedTimer.h"

class Game
{
public:
	Game();
	Level CurrentLevel(); //Getter
	void setCurrentLevel(int level);

	int getScore();
	void addScore(int points);
	void changeLevel();
	int getCurrentSlice();
	bool resetTime();
	void setFreezeSnakePoison(Snake &theSnake);
	bool getSnakePoisonFreeze();
	int getFreezePoisonSlice();
	int getFreezeCountDown();

private:
	Level mCurrentLevel;
	bool mStarted;
	int mScore;
	bool mResetTime;
	int mCurrentSlice;
	bool mSnakePoisonFreeze{ false };
	int mFreezePoisonSlice;
	int mFreezeCountDown;
};