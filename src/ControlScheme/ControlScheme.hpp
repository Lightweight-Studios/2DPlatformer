#pragma once

#include <map>
#include <memory>
#include <vector>
#include "Command.hpp"
#include "SDL.h"

class ControlScheme {
   public:
      virtual ~ControlScheme() {}
      virtual std::shared_ptr<Command> translate(SDL_Event * e) = 0;

   private:
      std::map<SDL_Keycode, std::vector<std::shared_ptr<Command>>> m_scheme;
   /*
   The convention here is that on a keyDown event, we take vec[0] as 
   our command, and on a keyUp event we take vec[1]. If we do not care
   vec[0] will be taken as the default 
   */ 
};