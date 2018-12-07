#include "Snake.h"
#include "PrintBackground.h" 

Snake::Snake()

	: mColor{},
	mCurrentHeadPos{},
	mState{ true }, //vivant
	mSpeed{ 1 },
	mSymbol{ ' ' },
	mDirection{},
	mSnakeBody{},
	mSnakePoisoned {false}

{
}

ConsoleColor Snake::color() { return mColor; }
Position Snake::currentHeadPos() { return mCurrentHeadPos; }
bool Snake::state() { return mState; }
int Snake::length() { return mSnakeBody.size(); }
int Snake::speed() { return mSpeed; }
int Snake::direction() { return mDirection; }
char Snake::symbol() { return mSymbol; }
std::vector<Position> Snake::snakeBody() { return mSnakeBody; }

bool Snake::snakePoisoned() { return mSnakePoisoned; }
void Snake::setSpeed(int speed) { mSpeed = speed; }
void  Snake::setColor(ConsoleColor color){mColor = color;};
void  Snake::setState(bool state){mState = state;};
void  Snake::setDirection(int direction){mDirection = direction;};
void  Snake::setSymbol(char symbol){mSymbol = symbol;};

void Snake::setSnakePoisoned(bool poisoned) { 
	mSnakePoisoned= poisoned;
}

void Snake::newSnake(ConsoleColor color, char symbol, Position position, int length)
{
	//initialiser les parametres 
	mColor = color;
	mSymbol = symbol;

	//vider vecteur si pas vide
	if (mSnakeBody.size() != 0)
	{
		mSnakeBody.clear(); 
	}

	//init les premiers points dans le vecteur / pour longueur de serpent x
	Position pos;
	mCurrentHeadPos.setCoords(position.x(), position.y());

	for (unsigned i = 0; i < length; i++) {
		pos.setCoords(position.x() - i, position.y());
		mSnakeBody.insert(mSnakeBody.begin(), pos);
	}

}


void Snake::addToHead(Direction direction)
{
	//ajouter a la fin du vecteur la nouvelle position de la tete
	Position currentHead{ mSnakeBody[mSnakeBody.size() - 1] };    // garder en memoire la tete actuelle
	Position newHead{};

	newHead.setCoords(currentHead.x() + direction.DirectionX(), currentHead.y() + direction.DirectionY()); 
																																													
	mSnakeBody.insert(mSnakeBody.end(), newHead);
	mCurrentHeadPos.setCoords(newHead.x(), newHead.y());
}

void Snake::removeFromTail()
{
	mSnakeBody.erase(mSnakeBody.begin()); 
										  
}

bool Snake::outOfBounds()
{
	PrintBackground pbg;

	int headX = currentHeadPos().x();
	int headY = currentHeadPos().y();

	size_t limitX = pbg.gameX() + pbg.gameWidth() - 3;
	size_t limitY = pbg.gameY() + pbg.gameHeight() - 3;


	if (headX > limitX || headY > limitY || headX < pbg.gameX()+2 || headY < pbg.gameY()+2)
	{
		return true;
	}
	return false;
}



bool Snake::touchesItself() //pas dans le sens louche
{
	Position laPos;
	for (int i = 0; i < mSnakeBody.size() - 1; ++i)
	{
		laPos.setCoords(mSnakeBody.at(i).x(), mSnakeBody.at(i).y());
		if (laPos.x() == mCurrentHeadPos.x() && laPos.y() == mCurrentHeadPos.y())
		{
			return true;
		}
	}
	return false;
}

bool Snake::isDead()
{
	if (outOfBounds() || touchesItself())
		return true;
	return false;
}




