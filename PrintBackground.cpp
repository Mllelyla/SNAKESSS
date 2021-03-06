#include "PrintBackground.h"
#include "Console.h"
#include <string>


PrintBackground::PrintBackground()
	:mTotalWidth{ 70 },
	mTotalHeight{ 60 },
	mGameWidth{ 35 },
	mGameHeight{ 35 }
{
}

size_t PrintBackground::gameX() {
	size_t gameX = (mTotalWidth / 2) - (mGameWidth / 2);
	return gameX;
}

size_t PrintBackground::gameY() {
	size_t gameY = (mTotalHeight / 2) - (mGameHeight / 2);
	return gameY;
}

size_t PrintBackground::gameWidth() { return mGameWidth; }
size_t PrintBackground::gameHeight() { return mGameHeight; }

void PrintBackground::setgameWidth(size_t newWidth) { mGameWidth = newWidth; }

void PrintBackground::setgameHeight(size_t newHeight) { mGameHeight = newHeight; }

void PrintBackground::set(ConsoleImage &Background, std::string titre)
{
	//BACKGROUND GENERIC
	Background.drawRect(size_t(0), size_t(0), mTotalWidth, mTotalHeight, char(219), ConsoleColor::tb, ' ', ConsoleColor::bK); //cadre principal avec bordure
	Background.drawRect(size_t(19), size_t(4), size_t(30), size_t(4), char(219), ConsoleColor::tY, ' ', ConsoleColor::tb); //cadre titre
	Background.drawText(size_t(20), size_t(5), titre, ConsoleColor::ty); //titre
}

void PrintBackground::setOnGame(ConsoleImage &Background, Food theFood, Food theFood2) {

	PrintBackground::set(Background, "~ THE FABULOUS SNAKE GAME ~");

	//draw food info 
	Background.drawPoint(size_t(2), size_t(20), theFood.symbol(), theFood.color());
	Background.drawText(size_t(4), size_t(20), "= 1 points", ConsoleColor::ty);
	Background.drawPoint(size_t(2), size_t(25), theFood2.symbol(), theFood2.color());
	Background.drawText(size_t(4), size_t(25), " = 3 points & POISON", ConsoleColor::ty);
	Background.drawText(size_t(1), size_t(28), "POISON = INPUTS", ConsoleColor::ty);
	Background.drawText(size_t(1), size_t(30), "TEMPORARY FROZEN", ConsoleColor::ty);

	//draw Ctlr info
	Background.drawText(size_t(55), size_t(20), "UP = W ", ConsoleColor::ty);
	Background.drawText(size_t(55), size_t(24), "DOWN = S ", ConsoleColor::ty);
	Background.drawText(size_t(55), size_t(28), "LEFT = A ", ConsoleColor::ty);
	Background.drawText(size_t(55), size_t(32), "RIGHT = D ", ConsoleColor::ty);
	Background.drawText(size_t(55), size_t(38), "PAUSE = 'esc' ", ConsoleColor::ty);
	//Background.drawText(size_t(55), size_t(42), "QUIT = Q ", ConsoleColor::ty);

	//Game Area
	PrintBackground::setGameArea(Background);
}

void PrintBackground::setGameArea(ConsoleImage &Background)
{
	Background.drawRect(PrintBackground::gameX(), PrintBackground::gameY(), size_t(mGameWidth), size_t(mGameHeight), char(219), ConsoleColor::tr, 'S', ConsoleColor::tb);
}

void PrintBackground::setWelcome(ConsoleImage &Background)
{
	PrintBackground::set(Background, "        ~ WELCOME ~");
	Background.drawText(size_t(20), size_t(20), "PRESS 'S' TO START THE GAME", ConsoleColor::tW);
	Background.drawText(size_t(20), size_t(25), "PRESS 'O' TO VIEW THE OPTIONS", ConsoleColor::tW);
	Background.drawText(size_t(20), size_t(30), "PRESS 'Q' TO QUIT THE GAME", ConsoleColor::tW);

}

void PrintBackground::setOptions(ConsoleImage &Background)
{
	PrintBackground::set(Background,"        ~ OPTIONS ~");
	Background.drawText(size_t(20), size_t(20), "PRESS 'I' TO VIEW THE INSTRUCTIONS", ConsoleColor::tW);
	Background.drawText(size_t(20), size_t(25), "PRESS 'esc' TO GO BACK", ConsoleColor::tW);
}

void PrintBackground::setInstructions(ConsoleImage &Background)
{
	PrintBackground::set(Background, "      ~ INSTRUCTIONS ~");


	Background.drawText(size_t(12), size_t(10), " * FOOD = POINTS", ConsoleColor::ty);
	Background.drawText(size_t(12), size_t(12), " * THE SNAKE GOES FASTER WITH THE LEVELS", ConsoleColor::ty);
	Background.drawText(size_t(12), size_t(14), " * THE POISONED FOOD GIVE YOU MORE POINTS BUT", ConsoleColor::ty);
	Background.drawText(size_t(12), size_t(16), "   YOU CAN'T USE THE INPUTS FOR A SHORT TIME", ConsoleColor::ty);
	Background.drawText(size_t(32), size_t(20), "W : UP", ConsoleColor::ty);
	Background.drawText(size_t(32), size_t(44), "A : LEFT", ConsoleColor::ty);
	Background.drawText(size_t(33), size_t(32), "SNAKE!", ConsoleColor::ty);
	Background.drawText(size_t(12), size_t(32), "A : LEFT", ConsoleColor::ty);
	Background.drawText(size_t(52), size_t(32), "D : RIGHT", ConsoleColor::ty);
	Background.drawText(size_t(56), size_t(5), "O : OPTIONS", ConsoleColor::ty);


}

void PrintBackground::setPause(ConsoleImage &Background)
{
	std::string snakesAscii = " " ;

	PrintBackground::set(Background, "         ~ PAUSE ~");
	Background.drawText(size_t(20), size_t(20), "Q = QUIT THE GAME", ConsoleColor::ty);
	Background.drawText(size_t(20), size_t(23), "G = BACK TO THE GAME", ConsoleColor::ty);
	Background.drawText(size_t(20), size_t(26), "E = WELCOME MENU", ConsoleColor::ty);
	Background.drawText(size_t(20), size_t(30), "                   oo ", ConsoleColor::ty);
	Background.drawText(size_t(20), size_t(31), " . ..__ / \_ / \_ / `' ", ConsoleColor::ty);


}
void PrintBackground::setGameOver(ConsoleImage &Background)
{
	PrintBackground::set(Background, "        ~ GAMEOVER ~");
	Background.drawText(size_t(20), size_t(20), "THANKS FOR PLAYING !", ConsoleColor::ty);
	Background.drawText(size_t(20), size_t(23), "W = WELCOME MENU", ConsoleColor::ty);
	Background.drawText(size_t(20), size_t(26), "Q = QUIT THE GAME", ConsoleColor::ty);

}
void PrintBackground::setQuit(ConsoleImage &Background)
{
	PrintBackground::set(Background, "  ~ QUIT ~");
	Background.drawText(size_t(20), size_t(20), "PRESS 'Q' TO EXIT", ConsoleColor::tW);
	Background.drawText(size_t(20), size_t(25), "PRESS 'esc' TO GO BACK", ConsoleColor::tW);
}


