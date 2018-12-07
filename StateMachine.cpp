#include "StateMachine.h"
#include "State.h"
#include <iostream>
#include "Direction.h"
#include "Snake.h"
#include "Game.h"
#include "Food.h"
#include "FoodFunctionalities.h"
#include "Console.h"
#include "ConsoleKeyFilterUp.h"
#include "PrintImage.h"
#include "ElapsedTimer.h"
#include "PrintBackground.h"
#include <windows.h > //tests beeps sonores :p


using namespace std;

const int INDEX_EXIT = 0;
const int INDEX_WELCOME = 1;
const int INDEX_START = 2;
const int INDEX_ONGAME = 3;
const int INDEX_GAMEOVER = 4;
const int INDEX_PAUSE = 5;
const int INDEX_QUIT = 6;
const int INDEX_INSTRUCTIONS = 7;
const int INDEX_OPTIONS = 8;


int welcome(Console& console, StateMachine& machine)
{

	////////////////////////////////////////////////////////
	//FONCTION PRINTBACKGROUND

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };
	PrintBackground printbG;
	printbG.setWelcome(Background);

	writer.push("Background");
	///////////////////////////////////////////////////////

	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	ConsoleKeyReader::KeyEvents keyEvents;
	reader.read(keyEvents);  //vecteur de keyEvents
	for (auto event : keyEvents) {

		switch (event.keyA())
		{
		case 'o': return INDEX_OPTIONS;  break;
		case 'O': return INDEX_OPTIONS;  break;
		case 's': return INDEX_START;  break;
		case 'S': return INDEX_START;  break;
		case 'q': return INDEX_QUIT;  break;
		case 'Q': return INDEX_QUIT;  break;
		}
	}
	return INDEX_WELCOME;
}

int exit(Console& console, StateMachine& machine)
{
	return -1;
}

int start(Console& console, StateMachine& machine)
{
	return INDEX_ONGAME;
}

int onGame(Console& console, StateMachine& machine)
{
	//initialisation des instances d'objets  ...a faire dans Game ?
	Direction leMod;
	leMod.setRight(); //direction par defaut au debut
	Snake theSnake;
	FoodFunctionalities foodFunctions;
	Food theFood, theFood2;
	PrintImage printImage;
	ElapsedTimer<> leTimer;
	PrintBackground printbG;
	Game currentGame;
	int score;
	int currentlevel;

	bool started = false;
	int currentSlice{};
	currentGame.setCurrentLevel(1);  // + que les niveaux avancent, plus le serpent va vite

	int levelTimeUpdateInMs = currentGame.CurrentLevel().calcMsBetweenMovement();

	bool gameEnd = false;
	leTimer.start();
	started = true;

	theSnake.newSnake(ConsoleColor::tc, char(219), Position(30, 30), 4); //position de depart 
	theFood.setRandomApple();
	theFood2.setRandomBrocoli();
	theFood.setPosition(foodFunctions.newRandomFoodPosition(theSnake)); //random position Food1 relative a la position du snake
	theFood2.setPosition(foodFunctions.newRandomFoodPosition(theSnake)); //random position Food2 relative a la position du snake

	////////////////////////////////////////////////////////
	//BACKGROUND 
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	printbG.setOnGame(Background, theFood, theFood2);

	writer.push("Background");

	ConsoleImage &Image{ writer.createImage("Image") };  //creation d'une image vide
	/////////////////////////////////////////////////////////
	while (!gameEnd)
	{
		//updates score/level
		score = currentGame.getScore();
		currentlevel = currentGame.CurrentLevel().levelNumber();

		//regarde si on doit augmenter la vitesse : si on change de niveau ou si le serpent est empoisonné ( augmente vitesse temporairement)
		//currentGame.setSpeedSnake(theSnake);
		levelTimeUpdateInMs = currentGame.CurrentLevel().updateMsBetweenMovement();

		//print background + nouvelles Images
		writer.push("Background", "Image"); //met le background dans l'image vide / ecrase l'image si elle existe deja
		printImage.drawAll(theSnake, theFood, theFood2, Image); //rajoute le visuel de tes objets sur l'image
		printImage.drawStats(theSnake, score, currentlevel, Image); //visuel du score/level
		writer.push("Image"); //affiche nouvelle image + background

		ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
		ConsoleKeyReader::KeyEvents keyEvents;
		reader.installFilter(new ConsoleKeyFilterUp);
		reader.read(keyEvents);
		for (auto event : keyEvents)
		{
			switch (event.keyV())
			{
			case 'W': leMod.setUp();    break;
			case 'w': leMod.setUp();    break;
			case 'A': leMod.setLeft();  break;
			case 'a': leMod.setLeft();  break;
			case 'S': leMod.setDown();  break;
			case 's': leMod.setDown();  break;
			case 'D': leMod.setRight(); break;
			case 'd': leMod.setRight(); break;
			}
			if (GetAsyncKeyState(VK_ESCAPE))
			{

				return INDEX_PAUSE;
			}
		}


		if ((leTimer.elapsedSeconds() * 1000 / levelTimeUpdateInMs) > currentSlice) //test Pause
		{
			gameEnd = theSnake.isDead();
			theSnake.addToHead(leMod); //mouvement du serpent

			if (!foodFunctions.snakeTouchingFood(theSnake, theFood, theFood2)) {
				theSnake.removeFromTail();
			}
			else {
				Food * foodTouched = foodFunctions.FoodEaten();
				foodFunctions.snakeEatFood(theSnake, (*foodTouched));
				currentGame.addScore(foodFunctions.pointsByTypeFood());
				Beep(880, 100);  //SON !!
				currentGame.changeLevel();
			}
			++currentSlice; //Changer pour des slices, et la slice est définie par le niveau
		}
	}
	return INDEX_GAMEOVER;
}

int gameOver(Console& console, StateMachine& machine)
{
	////////////////////////////////////////////////////////
	//FONCTION PRINTBACKGROUND

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setGameOver(Background);

	writer.push("Background");
	///////////////////////////////////////////////////////
	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	ConsoleKeyReader::KeyEvents keyEvents;
	reader.installFilter(new ConsoleKeyFilterUp);
	reader.read(keyEvents);
	for (auto event : keyEvents)
	{
		switch (event.keyV())
		{
		case 'q': return INDEX_QUIT;   break;
		case 'Q': return INDEX_QUIT;   break;
		
		}
	}


	while (1) {
		
		for (char button = 0; button < 256; button++) {
			if (GetAsyncKeyState(button) & 0x8000) {
				return INDEX_WELCOME;
			}
		}
		return INDEX_QUIT;
	}





	//if (GetAsyncKeyState(any_key))
	//{

	//	return INDEX_PAUSE;
	//}
	return INDEX_QUIT;
}

int pause(Console& console, StateMachine& machine)
{
	////////////////////////////////////////////////////////
	//FONCTION PRINTBACKGROUND

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setPause(Background);

	writer.push("Background");
	///////////////////////////////////////////////////////

	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	ConsoleKeyReader::KeyEvents keyEvents;

	reader.read(keyEvents);  //vecteur de keyEvents
	for (auto event : keyEvents) {

		switch (event.keyA())
		{
		case 'e': return INDEX_WELCOME;  break;
		case 'E': return INDEX_WELCOME;  break;
		case 'Q': return INDEX_QUIT;  break;
		case 'q': return INDEX_QUIT;  break;

		}
	}
	return INDEX_PAUSE;
}

int quit(Console& console, StateMachine& machine)
{
	////////////////////////////////////////////////////////
	//FONCTION PRINTBACKGROUND

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setGameOver(Background);

	writer.push("Background");
	///////////////////////////////////////////////////////

	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	ConsoleKeyReader::KeyEvents keyEvents;
	reader.read(keyEvents);  //vecteur de keyEvents
	
	for (auto event : keyEvents) {

		switch (event.keyA())
		{
		case 'y': return INDEX_EXIT;;  break;
		case 'Y': return INDEX_EXIT;;  break;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{

			return INDEX_WELCOME;
		}
	}
	return INDEX_QUIT;
}

int instructions(Console& console, StateMachine& machine)
{

	////////////////////////////////////////////////////////
	//FONCTION PRINTBACKGROUND

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setInstructions(Background);

	writer.push("Background");
	///////////////////////////////////////////////////////

	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	ConsoleKeyReader::KeyEvents keyEvents;

	reader.read(keyEvents);  //vecteur de keyEvents
	for (auto event : keyEvents) {

		switch (event.keyA())
		{
		case 'O': return INDEX_OPTIONS;  break;
		case 'o': return INDEX_OPTIONS;  break;

		}
		
		if (GetAsyncKeyState(VK_ESCAPE))
		{

			return INDEX_OPTIONS;
		}
	}

	return INDEX_INSTRUCTIONS;
}

int options(Console& console, StateMachine& machine)
{

	////////////////////////////////////////////////////////
	//FONCTION PRINTBACKGROUND

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setOptions(Background);

	writer.push("Background");
	///////////////////////////////////////////////////////

	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	ConsoleKeyReader::KeyEvents keyEvents;


	reader.read(keyEvents);  //vecteur de keyEvents
	for (auto event : keyEvents) {

		switch (event.keyA())
		{
		case 'I': return INDEX_INSTRUCTIONS; break;
		case 'i': return INDEX_INSTRUCTIONS; break;

		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{

			return INDEX_WELCOME;
		}
	}
	return INDEX_OPTIONS;
}

StateMachine::StateMachine()
{
	mStates.push_back(State(exit));
	mStates.push_back(State(welcome));
	mStates.push_back(State(start));
	mStates.push_back(State(onGame));
	mStates.push_back(State(gameOver));
	mStates.push_back(State(pause));
	mStates.push_back(State(quit));
	mStates.push_back(State(instructions));
	mStates.push_back(State(options));
}


State& StateMachine::getState(int index)
{
	return mStates[index];
}

void StateMachine::run(Console& console)
{
	int currentStateIndex = INDEX_WELCOME;
	while (currentStateIndex != INDEX_EXIT)
	{
		State& currentState = mStates[currentStateIndex];
		currentStateIndex = currentState.execute(console, *this);
	}
}