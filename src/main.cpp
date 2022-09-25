#include "Window.hpp"

#include "SDL.h"

#include <iostream>

int main(int argc, char* args[])
{
   std::cout << "%% Enter main()" << std::endl;

   if (0 != SDL_Init(SDL_INIT_VIDEO))
   {
      std::cerr << "xx Failed to initialize the SDL2 library" << std::endl;
      return -1;
   }

   auto window_optional = Graphics::Window::create();
   if (std::nullopt == window_optional)
   {
      std::cerr << "xx Failed to create main window" << std::endl;
      return -1;
   }

   auto window = Graphics::Window(std::move(window_optional.value()));
   window.update_surface();

   SDL_Delay(5000);

   window.teardown();

   SDL_Quit();

   std::cout << "%% Exit main()" << std::endl;
   return 0;
}