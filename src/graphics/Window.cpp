#include "Window.hpp"

#include "Logger.hpp"

#include "SDL.h"

#include <assert.h>

using namespace Graphics;

namespace
{
   constexpr auto WINDOW_NAME = "2DPlatformer"; 
   constexpr int DEFAULT_WINDOW_WIDTH = 680;
   constexpr int DEFAULT_WINDOW_HEIGHT = 480;
}

Window::Window(SDL_Window* sdl_window, Surface&& current_surface) :
   m_sdl_window(sdl_window),
   m_current_surface(std::move(current_surface))
{
   assert(nullptr != sdl_window);
}

Window::Window(Window&& other) :
   m_sdl_window(other.m_sdl_window),
   m_current_surface(std::move(other.m_current_surface))
{
   other.m_sdl_window = nullptr;
}

Window::~Window()
{
   teardown_internal();
}

Window& Window::operator=(Window&& rhs)
{
   if (this != &rhs)
   {
      this->m_sdl_window = rhs.m_sdl_window;
      this->m_current_surface = std::move(rhs.m_current_surface);
      rhs.m_sdl_window = nullptr;
   }

   return *this;
}

std::optional<Window> Window::create()
{
   auto sdl_window = SDL_CreateWindow(WINDOW_NAME,
                                      SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED,
                                      DEFAULT_WINDOW_WIDTH, 
                                      DEFAULT_WINDOW_HEIGHT,
                                      SDL_WINDOW_SHOWN);
   if (nullptr == sdl_window)
   {
      LOG_ERROR("Failed to create an SDL window");
      return std::nullopt;
   }

   auto surface_optional = Surface::create(SDL_GetWindowSurface(sdl_window));
   if (std::nullopt == surface_optional)
   {
      LOG_ERROR("Failed to create a Surface");
      SDL_DestroyWindow(sdl_window);
      return std::nullopt;
   }

   return std::optional<Window>({sdl_window, std::move(surface_optional.value())});
}

void Window::teardown()
{
   teardown_internal();
}

void Window::teardown_internal()
{
   m_current_surface.teardown();

   if (nullptr != m_sdl_window)
   {
      SDL_DestroyWindow(m_sdl_window);
      m_sdl_window = nullptr;
   }
}

void Window::update_surface()
{
   SDL_UpdateWindowSurface(m_sdl_window);
}

