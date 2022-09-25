#include "Surface.hpp"

#include "Logger.hpp"

#include "SDL.h"

#include <assert.h>

using namespace Graphics;

Surface::Surface(SDL_Surface* sdl_surface) :
   m_sdl_surface(sdl_surface)
{
   assert(nullptr != sdl_surface);
}

Surface::Surface(Surface&& other) :
   m_sdl_surface(other.m_sdl_surface)
{
   other.m_sdl_surface = nullptr;
}

Surface::~Surface()
{
   teardown_internal();
}

Surface& Surface::operator=(Surface&& rhs)
{
   if (this != &rhs)
   {
      this->m_sdl_surface = rhs.m_sdl_surface;
      rhs.m_sdl_surface = nullptr;
   }

   return *this;
}

std::optional<Surface> Surface::create(SDL_Surface* sdl_surface)
{
   if (nullptr != sdl_surface)
   {
      return Surface(sdl_surface);
   }

   LOG_ERROR("Null sdl_surface passed to factory");
   return std::nullopt;
}

void Surface::teardown()
{
   teardown_internal();
}

void Surface::teardown_internal()
{
   if (nullptr != m_sdl_surface)
   {
      SDL_FreeSurface(m_sdl_surface);
      m_sdl_surface = nullptr;
   }
}

