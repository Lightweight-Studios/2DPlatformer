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

   auto& window = Graphics::Window::instance();

   // auto window_surface = SDL_GetWindowSurface(s_Window);

   // if (nullptr == window_surface)
   // {
   //    std::cerr << "xx Failed to get the surface from the window" << std::endl;
   //    return -1;
   // }

   // SDL_UpdateWindowSurface(s_Window);

   SDL_Delay(5000);


   SDL_Quit();

   std::cout << "%% Exit main()" << std::endl;
   return 0;
}