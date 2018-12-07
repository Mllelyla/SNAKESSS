#ifndef PRINTBACKGROUND_H
#define PRINTBACKGROUND_H
#include "Food.h"
#include "ConsoleImage.h"
#include "Snake.h"

class PrintBackground
{
public:
	PrintBackground();

	size_t gameX();
	size_t gameY();
	size_t gameWidth();
	size_t gameHeight();

	void setgameWidth(size_t newWidth); 
	void setgameHeight(size_t newHeight);

	void set(ConsoleImage &Background,std::string titre);
	void setWelcome(ConsoleImage &Background);
	void setOnGame(ConsoleImage &Background, Food theFood1, Food theFood2);
	void setPause(ConsoleImage &Background);
	void setOptions(ConsoleImage &Background);
	void setQuit(ConsoleImage &Background);
	void setGameOver(ConsoleImage &Background);
	void setInstructions(ConsoleImage &Background);
	void setGameArea(ConsoleImage &Background);

private:
	size_t		mTotalWidth;
	size_t		mTotalHeight;
	size_t		mGameWidth;
	size_t		mGameHeight;

};

#endif 


