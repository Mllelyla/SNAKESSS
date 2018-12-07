#include "Transition.h"

Transition::Transition()

	: mCondition{},
	mNextState{}
{
}


bool Transition::condition() { return mCondition; };
State* Transition::nextState() { return mNextState; };


void Transition::setCondition(bool condition) { mCondition = condition; }
void Transition::setNextState(State* nextState) { mNextState = nextState; }


void setNextState(State* nextState) {

	return;

}

