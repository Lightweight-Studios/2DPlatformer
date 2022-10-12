#include "Window.hpp"

#include "GameGraphics.hpp"
#include "Logger.hpp"
#include "TODOREMOVEME.hpp"

#include "StdKeyBoardCtrlScheme.hpp"

#include "SDL.h"

#include <system_error>

using namespace Graphics;

namespace
{
   // GameInput game_input;
   // GameLogic game_logic;
   GameGraphics game_graphics;
}

int initialize()
{
   // Initialize SDL2
   if (0 != SDL_Init(SDL_INIT_TIMER & SDL_INIT_VIDEO & SDL_INIT_EVENTS & SDL_INIT_GAMECONTROLLER))
   {
      LOG_ERROR("Failed to initialize the SDL2 library, SDL Error: " << SDL_GetError());
      return -1;
   }

   // game_input.initialize();
   // game_logic.initialize();
   game_graphics.initialize();

   return 0;
}

void teardown()
{
   game_graphics.teardown();
   // game_logic.teardown();
   // game_input.teardown();

   SDL_Quit();
}

void run_gameloop()
{
   // @TODO REMOVE ALL LOGIC WITH TEMPORARY MAIN PLAYER USED FOR DEMOING
   TODORemove::s_main_player_last_state = TODORemove::PlayerData{};
   TODORemove::s_main_player_current_state = TODORemove::PlayerData{};
   TODORemove::s_main_player_current_state.m_x_velocity = 5.0;
   TODORemove::s_main_player_current_state.m_facing_direction = TODORemove::Direction::right;

   // @TODO Need to determine how we want to manage game loop timing
   //       https://gameprogrammingpatterns.com/game-loop.html
   // @TODO This will need cleanup, solely using this for demo purposes atm
   auto i = 0;
   auto running = true;
   while (running)
   {
      // game_input.process();
      // game_logic.update();
      game_graphics.render();

      // @TODO REMOVE ALL LOGIC WITH TEMPORARY MAIN PLAYER USED FOR DEMOING
      TODORemove::s_main_player_last_state = TODORemove::s_main_player_current_state;

      if (i++ < 150)
      {
         SDL_Delay(100);
      }
      else
      {
         running = false;
      }
   }
}

int main(int argc, char* args[])
{
   LOG_MESSAGE("Enter main()");

   auto return_value = initialize();
   if (0 == return_value) run_gameloop();
   teardown();

   LOG_MESSAGE("Exit main()");
   return return_value;
}

// @TODO Remove, leaving for Colby to reference
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