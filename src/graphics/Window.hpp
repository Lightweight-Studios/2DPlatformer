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
   Window(Window&& other);

   virtual ~Window();

   Window& operator=(const Window&) = delete;
   Window& operator=(Window&& rhs);

   static std::optional<Window> create();

   // @warning Teardown any window before exiting the SDL for the sake of cleanliness
   virtual void teardown();

   virtual void update_surface();

private:

   Window(SDL_Window* sdl_window, Surface&& current_surface);

   void teardown_internal();

   SDL_Window* m_sdl_window = nullptr;
   Surface m_current_surface;

};

} // namespace Window