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
#include <windows.h > 


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

	//FONCTION PRINTBACKGROUND
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };
	PrintBackground printbG;
	printbG.setWelcome(Background);

	writer.push("Background");

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
	//initialisation des instances d'objets  
	Direction theDirection;
	theDirection.setRight(); //direction par defaut au debut
	Snake theSnake;
	ElapsedTimer <> leTimer;
	FoodFunctionalities foodFunctions;
	Food theFood, theFood2;
	PrintImage printImage;
	PrintBackground printbG;
	Game currentGame;
	int score;
	int currentlevel;
	int freezeCountDown;

	bool started = false;
	//int currentSlice{};
	leTimer.start();
	currentGame.setCurrentLevel(1);  // + que les niveaux avancent, plus le serpent va vite
	float levelTimeUpdateInMs = currentGame.CurrentLevel().calcMsBetweenMovement();

	bool gameEnd = false;
	started = true;

	theSnake.newSnake(ConsoleColor::tc, char(219), Position(30, 30), 4); //position de depart 
	theFood.setRandomApple();
	theFood2.setRandomBrocoli();
	theFood.setPosition(foodFunctions.newRandomFoodPosition(theSnake)); //random position Food1 relative a la position du snake
	theFood2.setPosition(foodFunctions.newRandomFoodPosition(theSnake)); //random position Food2 relative a la position du snake

																		 
	//BACKGROUND 
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	printbG.setOnGame(Background, theFood, theFood2);

	writer.push("Background");

	ConsoleImage &Image{ writer.createImage("Image") };  //creation d'une image vide
													
	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	ConsoleKeyReader::KeyEvents keyEvents;
	reader.installFilter(new ConsoleKeyFilterUp);

	while (!gameEnd)
	{
		//si le snake est empoisonné, tu peux pas utiliser les commandes !!!!

		if (!currentGame.getSnakePoisonFreeze()) {
			reader.read(keyEvents);
			for (auto event : keyEvents) {
				switch (event.keyV()){
					case 'W': if (!(theDirection.isDown())) { theDirection.setUp(); } break;
					case 'w': if (!(theDirection.isDown())) { theDirection.setUp(); } break;
					case 'A': if (!(theDirection.isRight())) { theDirection.setLeft(); } break;
					case 'a': if (!(theDirection.isRight())) { theDirection.setLeft(); } break;
					case 'S': if (!(theDirection.isUp())) { theDirection.setDown(); } break;
					case 's': if (!(theDirection.isUp())) { theDirection.setDown(); } break;
					case 'D': if (!(theDirection.isLeft())) { theDirection.setRight(); } break;
					case 'd': if (!(theDirection.isLeft())) { theDirection.setRight(); } break;
				}
					if (GetAsyncKeyState(VK_ESCAPE))
						return INDEX_PAUSE;
			}


		}
		//print background + nouvelles Images
		writer.push("Background", "Image"); //met le background dans l'image vide / ecrase l'image si elle existe deja
		printImage.drawAll(theSnake, theFood, theFood2, Image); //rajoute le visuel de tes objets sur l'image
		printImage.drawStats(theSnake, score, currentlevel, freezeCountDown, Image); //visuel du score/level
		writer.push("Image"); //affiche nouvelle image + background


		if ((leTimer.elapsedSeconds() * 1000 / levelTimeUpdateInMs) > currentGame.getCurrentSlice())
		{
			//updates score/level
			score = currentGame.getScore();
			currentlevel = currentGame.CurrentLevel().levelNumber();
			freezeCountDown = currentGame.getFreezeCountDown();

			gameEnd = theSnake.isDead();

			theSnake.addToHead(theDirection); //mouvement du serpent

			if (!foodFunctions.snakeTouchingFood(theSnake, theFood, theFood2)) {
				theSnake.removeFromTail();
			}
			else {
				Food * foodTouched = foodFunctions.FoodEaten();
				foodFunctions.snakeEatFood(theSnake, (*foodTouched));
				currentGame.addScore(foodFunctions.pointsByTypeFood());
				Beep(880, 100);  //SON !!
			}

			currentGame.setFreezeSnakePoison(theSnake); //regarde si le serpent doit freezer pcq empoisonné

			levelTimeUpdateInMs = currentGame.CurrentLevel().updateMsBetweenMovement();

			currentGame.changeLevel();

			if (currentGame.resetTime()) //si empoisonné ou change de niveau
				leTimer.restart();
		}
	}
	
	return INDEX_GAMEOVER;
}

int gameOver(Console& console, StateMachine& machine)
{
	
	//FONCTION PRINTBACKGROUND
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setGameOver(Background);

	writer.push("Background");

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

	return INDEX_QUIT;
}

int pause(Console& console, StateMachine& machine)
{
	
	//FONCTION PRINTBACKGROUND
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setPause(Background);

	writer.push("Background");
	

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
		case 'G': return INDEX_ONGAME;  break;
		case 'g': return INDEX_ONGAME;  break;

		}
	}
	return INDEX_PAUSE;
}

int quit(Console& console, StateMachine& machine)
{
	
	//FONCTION PRINTBACKGROUND

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setGameOver(Background);

	writer.push("Background");
	

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
	return INDEX_EXIT;
}

int instructions(Console& console, StateMachine& machine)
{

	
	//FONCTION PRINTBACKGROUND

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setInstructions(Background);

	writer.push("Background");
	

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

	
	//FONCTION PRINTBACKGROUND

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & Background{ writer.createImage("Background") };

	PrintBackground printbG;
	printbG.setOptions(Background);

	writer.push("Background");


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