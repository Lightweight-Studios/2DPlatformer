#pragma once

#include <map>
#include <vector>
#include "Command.hpp"
#include "ControlScheme.hpp"
#include "SDL.h"



class StdKeyControlScheme : public ControlScheme {

public:
	StdKeyControlScheme();
	~StdKeyControlScheme() = default;
	virtual Command * translate(SDL_Event *evt) = 0;


private:
	std::map<SDL_Keycode, std::vector<Command>> scheme;

};