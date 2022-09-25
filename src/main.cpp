#include "SDL.h"

#include <iostream>

namespace
{
   SDL_Window* s_Window = nullptr;
   const int DEFAULT_WINDOW_WIDTH = 680;
   const int DEFAULT_WINDOW_HEIGHT = 480;
}

int main(int argc, char* args[])
{
   std::cout << "%% Enter main()" << std::endl;

   if (0 != SDL_Init(SDL_INIT_VIDEO))
   {
      std::cerr << "xx Failed to initialize the SDL2 library" << std::endl;
      return -1;
   }

   s_Window = SDL_CreateWindow("SDL2 Window",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               DEFAULT_WINDOW_WIDTH, 
                               DEFAULT_WINDOW_HEIGHT,
                               0);

   if (nullptr == s_Window)
   {
      std::cerr << "xx Failed to create window" << std::endl;
      return -1;
   }

   SDL_Surface *window_surface = SDL_GetWindowSurface(s_Window);

   if (nullptr == window_surface)
   {
      std::cerr << "xx Failed to get the surface from the window" << std::endl;
      return -1;
   }

   SDL_UpdateWindowSurface(s_Window);

   SDL_Delay(5000);

   std::cout << "%% Exit main()" << std::endl;
   return 0;
}