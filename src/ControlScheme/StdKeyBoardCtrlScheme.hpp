#pragma once

#include <map>
#include <memory>
#include <vector>
#include "Command.hpp"
#include "ControlScheme.hpp"
#include "SDL.h"



class StdKeyControlScheme : public ControlScheme {

public:
	StdKeyControlScheme();
	~StdKeyControlScheme() = default;
	virtual std::unique_ptr<Command> translate(SDL_Event *evt) = 0;


private:
	std::map<SDL_Keycode, std::vector<std::unique_ptr<Command>>> scheme;

};