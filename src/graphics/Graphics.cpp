#include "Graphics.hpp"

#include "Logger.hpp"

#include "SDL.h"

#include <system_error>

using namespace Graphics;

void Graphics::initialize()
{
   LOG_MESSAGE("Enter Graphics::initialize()");

   // Initialize SDL
   if (0 != SDL_Init(SDL_INIT_VIDEO))
   {
      LOG_ERROR("Failed to initialize the SDL2 library");
      throw std::system_error(EACCES, 
                              std::generic_category(), 
                              "Failed call to SDL_Init(), SDL Error: " + std::string(SDL_GetError()));
   }

   // Set texture filtering to linear
   if (SDL_FALSE == SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
   {
      LOG_WARNING("Failed to set linear texture filtering option");
   }

   LOG_MESSAGE("Exit Graphics::initialize()");
}

void Graphics::teardown()
{
   SDL_Quit();
}