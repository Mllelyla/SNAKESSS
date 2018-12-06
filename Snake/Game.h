
#include "Level.h"
#include "Snake.h"

class Game
{
public:
	Game();
	Level CurrentLevel(); //Getter
	void setCurrentLevel(int level);

	int getScore();
	void addScore(int points);
	void changeLevel();

	//void setSpeedSnake(Snake &theSnake);

private:
	Level mCurrentLevel;
	bool mStarted;
	int mScore;
	//bool mSnakePoisonSpeed{ false };
};