#ifndef CONSOLE_KEY_FILTER_UP_H
#define CONSOLE_KEY_FILTER_UP_H


#include "ConsoleKeyFilter.h"


// These filters are for one key filtering. If you need to filter a 
// combination of n specific keys, you must not include the first key 
// in any of the following filters.


class ConsoleKeyFilterUp : public ConsoleKeyFilter
{
public:
	bool isFiltered(ConsoleKeyEvent const & consoleKeyEvent) const override;
};


#endif // CONSOLE_KEY_FILTER_UP_H
