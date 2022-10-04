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
	std::shared_ptr<Command> translate(SDL_Event *evt) override;


private:
	std::map<SDL_Keycode, std::vector<std::shared_ptr<Command>>> m_scheme;

};