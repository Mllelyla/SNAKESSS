#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
class State;

class Transition
{
public:
	Transition();

	bool condition();
	State* nextState();

	void setCondition(bool condition);
	void setNextState(State* nextState);
	
private:
	bool mCondition; // inclut une touche
	State* mNextState;
};
#endif // CONSOLE_H

