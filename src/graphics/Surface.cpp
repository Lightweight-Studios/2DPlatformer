#include "Surface.hpp"

#include "SDL.h"

#include <assert.h>
#include <iostream>

using namespace Graphics;

Surface::Surface(SDL_Surface* sdl_surface) :
   m_sdl_surface(sdl_surface)
{
   assert(nullptr != sdl_surface);
}

Surface::~Surface()
{
   teardown_internal();
}

std::optional<Surface> Surface::create(SDL_Surface* sdl_surface)
{
   if (nullptr != sdl_surface)
   {
      return Surface(sdl_surface);
   }

   std::cerr << "xx Null sdl_surface passed to factory" << std::endl;
   return std::nullopt;
}

void Surface::teardown()
{
   teardown_internal();
}

void Surface::teardown_internal()
{
   SDL_FreeSurface(m_sdl_surface);
   m_sdl_surface = nullptr;
}

