#pragma once

#include <map>
#include "Command.hpp"
#include "ControlScheme.hpp"
#include "SDL.h"


class StdKeyControlScheme : public ControlScheme {

public:
	~StdKeyControlScheme() {}
	virtual Command translate() = 0;


private:
	std::map<SDL_Event, Command> scheme;

};