#include "Renderer.hpp"

#include "Logger.hpp"
#include "ProjectDefs.hpp"

#include "SDL.h"

#include <assert.h>

using namespace Graphics;

Renderer::Renderer(SDL_Renderer* i_sdl_renderer) :
   m_sdl_renderer(i_sdl_renderer)
{
   assert(nullptr != i_sdl_renderer);
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

std::optional<Renderer> Renderer::create(SDL_Renderer* i_sdl_renderer)
{
   if (nullptr != i_sdl_renderer)
   {
      // Set default renderer draw color to white
      if (0 != SDL_SetRenderDrawColor(i_sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF ))
      {
         LOG_WARNING("Failed to set default Renderer draw color to white, SDL Error: " << 
                     SDL_GetError());
      }

      return Renderer(i_sdl_renderer);
   }

   LOG_ERROR("Null i_sdl_renderer passed to factory");
   return std::nullopt;
}

bool Renderer::render()
{
   CHECK_IF_POINTER_VALID_RETURN_BOOL(m_sdl_renderer);
   SDL_RenderPresent(m_sdl_renderer);
   return true;
}

bool Renderer::set_draw_color(RgbaColor color)
{
   CHECK_IF_POINTER_VALID_RETURN_BOOL(m_sdl_renderer);

   if (0 != SDL_SetRenderDrawColor(m_sdl_renderer, color.m_r, color.m_g, color.m_b, color.m_a))
   {
      LOG_WARNING("Failed to set draw color, SDL Error: " << SDL_GetError());
      return false;
   }

   return true;
}

bool Renderer::draw_shape()
{
   CHECK_IF_POINTER_VALID_RETURN_BOOL(m_sdl_renderer);

   SDL_Rect rect{100, 100, 100, 100};
   if (0 != SDL_RenderFillRect(m_sdl_renderer, &rect))
   {
      LOG_WARNING("Failed to set draw color, SDL Error: " << SDL_GetError());
      return false;
   }

   return true;
}
