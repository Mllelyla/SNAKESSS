
#include "Console.h"
#include "StateMachine.h"

int main()
{
	ConsoleContext context(70, 60, "B52", 16, 16, L"Consolas");
	Console::defineContext(context);

	StateMachine machine;
	machine.run(Console::getInstance());

	
	return 0;
}

