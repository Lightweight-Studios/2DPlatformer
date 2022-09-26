#include "Renderer.hpp"

#include "Logger.hpp"

#include "SDL.h"

#include <assert.h>

using namespace Graphics;

Renderer::Renderer(SDL_Renderer* sdl_renderer) :
   m_sdl_renderer(sdl_renderer)
{
   assert(nullptr != sdl_renderer);
}

Renderer::Renderer(Renderer&& other) :
   m_sdl_renderer(other.m_sdl_renderer)
{
   other.m_sdl_renderer = nullptr;
}

Renderer::~Renderer()
{
   if (nullptr != m_sdl_renderer)
   {
      SDL_DestroyRenderer(m_sdl_renderer);
   }
}

Renderer& Renderer::operator=(Renderer&& rhs)
{
   if (this != &rhs)
   {
      this->m_sdl_renderer = rhs.m_sdl_renderer;
      rhs.m_sdl_renderer = nullptr;
   }

   return *this;
}

std::optional<Renderer> Renderer::create(SDL_Renderer* sdl_renderer)
{
   if (nullptr != sdl_renderer)
   {
      return Renderer(sdl_renderer);
   }

   LOG_ERROR("Null sdl_renderer passed to factory");
   return std::nullopt;
}
