#include "Game.h"
#include "PrintBackground.h"

Game::Game()
	: mCurrentLevel{ Level::Level(1) },
	mStarted{ false },
	mScore{ 0 }
	//mSnakePoisonSpeed {false}

{
}

int Game::getScore() { return mScore; }
void Game::addScore(int points) { mScore+=points; }

Level Game::CurrentLevel() //getter de niveau
{
	return mCurrentLevel;
}

void Game::setCurrentLevel(int niveau) //setter de niveau
{
	mCurrentLevel.setlevelNumber(niveau) ;
}
void Game::changeLevel() 
{
	//tests : each 10 points, switch level 
	int lvl = mScore / 10;
	setCurrentLevel(lvl+1);

	/*
	if (mScore != 0 && mScore % 10 == 0) {

		setCurrentLevel(mCurrentLevel.levelNumber()+1);
	}
	*/
}

/*
void Game::setSpeedSnake(Snake &theSnake) {
	//test avec vitesse du serpent pour quand empoisonné
	if (theSnake.snakePoisoned() && !mSnakePoisonSpeed){
		mCurrentLevel.MsBetweenMovementMultiplier(theSnake.speed()*0.005);
		mSnakePoisonSpeed = true;
	}
	else if (!theSnake.snakePoisoned())
		mSnakePoisonSpeed = false;
}
*/


