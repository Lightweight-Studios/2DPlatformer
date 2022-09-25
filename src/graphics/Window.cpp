#include "Window.hpp"

#include "SDL.h"

#include <system_error>

using namespace Graphics;

namespace
{
   constexpr auto WINDOW_NAME = "2DPlatformer"; 
   constexpr int DEFAULT_WINDOW_WIDTH = 680;
   constexpr int DEFAULT_WINDOW_HEIGHT = 480;
}

Window::Window()
{
   m_window = SDL_CreateWindow(WINDOW_NAME,
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               DEFAULT_WINDOW_WIDTH, 
                               DEFAULT_WINDOW_HEIGHT,
                               SDL_WINDOW_SHOWN);
   if (nullptr == m_window)
   {
      throw std::system_error(EACCES, 
                              std::generic_category(), 
                              "Failed call to SDL_CreateWindow()");
   }
}

Window::~Window()
{
   SDL_FreeSurface(m_current_surface);
   m_current_surface = nullptr;

   SDL_DestroyWindow(m_window);
   m_window = nullptr;
}

Window& Window::instance()
{
   static Window window;
   return window;
}

