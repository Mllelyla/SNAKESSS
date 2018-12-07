#include "Game.h"
#include "PrintBackground.h"

Game::Game()
	: mCurrentLevel{ Level::Level(1) },
	mStarted{ false },
	mScore{ 0 },
	mResetTime{ false },
	mCurrentSlice{},
	mSnakePoisonFreeze{ false },
	mFreezePoisonSlice{},
	mFreezeCountDown{5 }
{
}

int Game::getScore() { return mScore; }
void Game::addScore(int points) { mScore += points; }
int Game::getCurrentSlice() { return mCurrentSlice; }
int Game::getFreezePoisonSlice() { return mFreezePoisonSlice; }
bool Game::resetTime() { return mResetTime; }
bool Game::getSnakePoisonFreeze() { return mSnakePoisonFreeze; }
int Game::getFreezeCountDown() { return mFreezeCountDown; }


Level Game::CurrentLevel() //getter de niveau
{
	return mCurrentLevel;
}

void Game::setCurrentLevel(int niveau) //setter de niveau
{
	mCurrentLevel.setlevelNumber(niveau);
}
void Game::changeLevel()
{
	//tests : each 10 points, switch level 
	int lvl = mScore / 5;
	if (lvl + 1 != mCurrentLevel.levelNumber())
	{
		setCurrentLevel(lvl + 1);
		mCurrentSlice = 0;
		mResetTime = true;
	}
	else {
		mResetTime = false;
		mCurrentSlice++;
	}
}


void Game::setFreezeSnakePoison(Snake &theSnake) {
	//freeze les inputs quand empoisonné
	if (theSnake.snakePoisoned() && !mSnakePoisonFreeze) {
		mSnakePoisonFreeze = true;
	}
	else if (!theSnake.snakePoisoned())
		mSnakePoisonFreeze = false;

	if (mSnakePoisonFreeze && mFreezePoisonSlice < 5) {
		mFreezeCountDown--;
		mFreezePoisonSlice++;
	}
	else {
		mFreezePoisonSlice = 0;
		mFreezeCountDown = 5;
		theSnake.setSnakePoisoned(false);
	}

}




