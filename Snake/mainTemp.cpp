
#include "Modifier.h"
#include "Snake.h"
#include "Food.h"
#include "Console.h"
#include "ConsoleKeyFilterUp.h"
#include "PrintImage.h"
#include "StateMachine.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "ElapsedTimer.h"
//faudrait mettre les #include dans un autre fichier
using namespace std;


int main()
{
	ConsoleContext context(70, 60, "B52", 16, 16, L"Consolas");
	Console::defineContext(context);

	StateMachine machine;
	machine.run(Console::getInstance());

	
	return 0;
}

