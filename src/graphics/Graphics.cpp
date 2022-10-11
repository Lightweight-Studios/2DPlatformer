#include "Graphics.hpp"

#include "Logger.hpp"

#include "SDL.h"
#include "SDL_image.h"

#include <system_error>

using namespace Graphics;

void Graphics::initialize()
{
   LOG_MESSAGE("Enter Graphics::initialize()");

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // Initialize SDL2
   if (0 != SDL_Init(SDL_INIT_VIDEO))
   {
      LOG_ERROR("Failed to initialize the SDL2 library, SDL Error: " << SDL_GetError());
      throw std::system_error(EACCES, 
                              std::generic_category(), 
                              "Failed call to SDL_Init(), SDL Error: " + std::string(SDL_GetError()));
   }

   // Set texture filtering to linear
   if (SDL_FALSE == SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
   {
      LOG_WARNING("Failed to set linear texture filtering option");
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // Initialize SDL2_image
   int supported_image_types = IMG_INIT_PNG;
   if (0 == (supported_image_types & IMG_Init(supported_image_types)))
   {
      LOG_ERROR("Failed to initialize the SDL2_image library, IMG Error: " << IMG_GetError());
      throw std::system_error(EACCES, 
                              std::generic_category(), 
                              "Failed call to IMG_Init(), IMG Error: " + std::string(IMG_GetError()));
   }

   LOG_MESSAGE("Exit Graphics::initialize()");
}

void Graphics::teardown()
{
   SDL_Quit();
}