#include "Window.hpp"

#include "GameGraphics.hpp"
#include "Logger.hpp"

#include "StdKeyBoardCtrlScheme.hpp"

#include "SDL.h"

#include <system_error>

using namespace Graphics;

int main(int argc, char* args[])
{
   LOG_MESSAGE("Enter main()");

   // Initialize SDL2
   if (0 != SDL_Init(SDL_INIT_TIMER & SDL_INIT_VIDEO & SDL_INIT_EVENTS & SDL_INIT_GAMECONTROLLER))
   {
      LOG_ERROR("Failed to initialize the SDL2 library, SDL Error: " << SDL_GetError());
      return -1;
   }

   // Constructions
   // GameInput game_input;
   // GameLogic game_logic;
   GameGraphics game_graphics;

   // Initializations
   // game_input.initialize();
   // game_logic.initialize();
   game_graphics.initialize();

   // Game loop
   // @TODO This will need cleanup, solely using this for demo purposes atm
   auto i=0;
   bool running = true;
   while (running)
   {
      // game_input.process();
      // game_logic.update();
      game_graphics.render();

      if (i++ < 150)
      {
         SDL_Delay(100);
      }
      else
      {
         running = false;
      }
   }

   // Clean up
   game_graphics.teardown();
   // game_logic.teardown();
   // game_input.teardown();

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // StdKeyControlScheme input = StdKeyControlScheme();

   // SDL_Event event;
   // std::shared_ptr<Command> mappedCommand;

   // while (true) {
   //     while (SDL_PollEvent(&event)) {
   //         LOG_MESSAGE("Keyboard Event Detected");
   //         mappedCommand = input.translate_key_evt_to_command(&event);
   //         mappedCommand->execute();
   //     }
   // }
   /////////////////////////////////////////////////////////////////////////////////////////////////

   LOG_MESSAGE("Exit main()");
   return 0;
}