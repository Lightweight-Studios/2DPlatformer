#pragma once

#include "Surface.hpp"

#include <optional>

// Forward declarations
class SDL_Window;

namespace Graphics
{

class Window
{
public:

   Window() = delete;
   Window(const Window&) = delete;
   Window(Window&&) = default;

   Window& operator=(const Window&) = delete;
   Window& operator=(Window&&) = default;

   virtual ~Window();

   static std::optional<Window> create();

   virtual void teardown();

   virtual void update_surface() const;

private:

   Window(SDL_Window* sdl_window, Surface&& current_surface);

   void teardown_internal();

   SDL_Window* m_sdl_window = nullptr;
   Surface m_current_surface;

};

} // namespace Window