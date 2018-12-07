#include "State.h"

int State::nbrTransitions() { return mNbrTransitions; }

State::State(StateUpdate execute) : mExecute(execute)
{
}

int State::execute(Console& console, StateMachine& machine)
{
	return mExecute(console, machine);
}
//
//void Transition::setNextState(State* nextState)
//{
//	 mNextState;
//
//}


