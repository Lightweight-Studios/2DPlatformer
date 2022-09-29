#include "Window.hpp"

#include "Graphics.hpp"
#include "Logger.hpp"

#include "StdKeyBoardCtrlScheme.hpp"

#include "SDL.h"

int main(int argc, char* args[])
{
   LOG_MESSAGE("Enter main()");

   Graphics::initialize();

   auto window_optional = Graphics::Window::create();
   if (std::nullopt == window_optional)
   {
      LOG_ERROR("Failed to create main window");
      return -1;
   }

   auto& window = window_optional.value();
   auto& renderer = window.get_renderer();

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // TODO: Remove, this is just test bed code (Enter your test bed code here)
   for (auto i=0; i<5; ++i)
   {
      // Should see last draw color become exterior fill, happy accident - Bob Ross
      renderer.set_draw_color(static_cast<Color>(i+1));
      renderer.draw_shape();
      renderer.render();
      //window.update_surface();
      SDL_Delay(1000);
   }
   /////////////////////////////////////////////////////////////////////////////////////////////////

   window.teardown();

   Graphics::teardown();

   LOG_MESSAGE("Exit main()");
   return 0;
}