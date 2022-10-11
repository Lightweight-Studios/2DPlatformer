#include "Window.hpp"

#include "Graphics.hpp"
#include "Logger.hpp"
#include "RenderInstructionFactory.hpp"

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
   FileSystem::Path image_path{std::string(ASSETS_DIRECTORY) + "/windowsxp.png"};
   auto image_surface = Graphics::Surface::create_from_image(image_path).value();
   auto image_texture = renderer.create_texture_from_surface(std::move(image_surface)).value();
   auto image_instruction = [&image_texture](SDL_Renderer& i_renderer)
   {
      SDL_Rect render_clip{0, 0, 680, 480};
      // SDL_Rect render_quad = render_clip;
      if (0 != SDL_RenderCopy(&i_renderer, image_texture.get_sdl_texture(), &render_clip, nullptr))
      {
         LOG_ERROR("Failed to render f-rect, SDL Error: " << SDL_GetError());
         return false;
      }
      return true;
   };

   for (auto i=0; i<5; ++i)
   {
     // Should see last draw color become exterior fill, happy accident - Bob Ross
     renderer.set_draw_color(static_cast<Color>(i+1));
     auto image_instruction_temp = image_instruction;
     renderer.render(std::move(image_instruction_temp));
     renderer.render(Graphics::RenderInstructionFactory::get_instruction(SDL_Rect{100, 100, 100, 100}));
     renderer.render_present();
     SDL_Delay(1000);
   }

   // StdKeyControlScheme input = StdKeyControlScheme();

   // SDL_Event event;
   // std::shared_ptr<Command> mappedCommand;

   // while (true) {
   //     while (SDL_PollEvent(&event)) {
   //         LOG_MESSAGE("Keyboard Event Detected");
   //         mappedCommand = input.translate_key_evt_to_command(&event);
   //         mappedCommand->execute();
   //     }
   // }

   /////////////////////////////////////////////////////////////////////////////////////////////////



   window.teardown();

   Graphics::teardown();

   LOG_MESSAGE("Exit main()");
   return 0;
}