#pragma once

#include "Console.h"
#include "Transition.h"
class StateMachine;

class State;

typedef int(*StateUpdate)(Console& console, StateMachine& machine);

class State
{

public:
	int nbrTransitions();

	State(StateUpdate execute);

	int execute(Console& console, StateMachine& machine);
	//Transition* isTransiting(Event & event);
	//void(*action)();



private:

	std::vector<Transition> mTransitions;

	StateUpdate mExecute;
	int mNbrTransitions;

};