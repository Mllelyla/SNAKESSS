#pragma once

#include "State.h"
#include <vector>
#include "Console.h"

class StateMachine
{
	std::vector<State> mStates;
public:
	StateMachine();

	State& getState(int index);

	void run(Console& console);
};

