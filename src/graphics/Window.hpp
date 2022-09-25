#pragma once

// Forward declarations
class SDL_Window;
class SDL_Surface;

namespace Graphics
{

class Window
{
public:

   // @warning Be wary in your access of this singleton, it should only be 
   //          accessed where necessary, EG: From main() or graphics subsystems
   static Window& instance();

private:

   Window();
   virtual ~Window();

   SDL_Window* m_window = nullptr;
   SDL_Surface* m_current_surface = nullptr;

};

} // namespace Window