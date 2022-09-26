#include "Window.hpp"

#include "Logger.hpp"

#include "SDL.h"

int main(int argc, char* args[])
{
   LOG_MESSAGE("Enter main()");

   if (0 != SDL_Init(SDL_INIT_VIDEO))
   {
      LOG_ERROR("Failed to initialize the SDL2 library");
      return -1;
   }

   auto window_optional = Graphics::Window::create();
   if (std::nullopt == window_optional)
   {
      LOG_ERROR("Failed to create main window");
      return -1;
   }

   auto window = Graphics::Window(std::move(window_optional.value()));

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // TODO: Remove, this is just test bed code (Enter your test bed code here)
   for (auto i=0; i<5; ++i)
   {
      window.update_surface();
      SDL_Delay(1000);
   }
   /////////////////////////////////////////////////////////////////////////////////////////////////

   window.teardown();

   SDL_Quit();

   LOG_MESSAGE("Exit main()");
   return 0;
}