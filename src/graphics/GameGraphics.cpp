#include "GameGraphics.hpp"

#include "Logger.hpp"
#include "RenderInstructionFactory.hpp"

#include "SDL.h"
#include "SDL_image.h"

#include <system_error>

using namespace Graphics;

void GameGraphics::initialize()
{
   LOG_MESSAGE("Enter GameGraphics::initialize()");

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // Initialize SDL2
   //// Set texture filtering to linear
   if (SDL_FALSE == SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
   {
      LOG_WARNING("Failed to set linear texture filtering option");
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // Initialize SDL2_image
   int supported_image_types = IMG_INIT_PNG;
   if (0 == (supported_image_types & IMG_Init(supported_image_types)))
   {
      LOG_ERROR("Failed to initialize the SDL2_image library, IMG Error: " << IMG_GetError());
      throw std::system_error(EACCES, 
                              std::generic_category(), 
                              "Failed call to IMG_Init(), IMG Error: " + std::string(IMG_GetError()));
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // Create Window
   auto window_optional = Window::create();
   if (std::nullopt == window_optional)
   {
      LOG_ERROR("Failed to create Window!");
      throw std::system_error(EACCES, std::generic_category(), "Failed to create Window!");
   }

   m_window = std::make_unique<Window>(std::move(window_optional.value()));

   LOG_MESSAGE("Exit GameGraphics::initialize()");
}

// Tears down objects in reverse order
void GameGraphics::teardown()
{
   LOG_MESSAGE("Enter GameGraphics::teardown()");

   if (nullptr != m_window)
   {
      m_window->teardown();
   }

   SDL_Quit();

   LOG_MESSAGE("Exit GameGraphics::teardown()");
}

void GameGraphics::render()
{
   LOG_MESSAGE("Enter GameGraphics::render()");

   if (nullptr == m_window)
   {
      LOG_ERROR("m_window is no longer valid!");
      throw std::system_error(EACCES, std::generic_category(), "m_window is no longer valid!");
   }

   auto& renderer = m_window->get_renderer();

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // TODO: Remove, this is just test bed code (Enter your test bed code here)
   static FileSystem::Path background_image_path{std::string(ASSETS_DIRECTORY) + "/windowsxp.png"};
   static auto background_image_surface = Graphics::Surface::create_from_image(background_image_path).value();
   static auto background_image_texture = renderer.create_texture_from_surface(std::move(background_image_surface)).value();
   static auto background_image_instruction = [](SDL_Renderer& i_renderer)
   {
      SDL_Rect render_clip{0, 0, 680, 480};
      // SDL_Rect render_quad = render_clip;
      if (0 != SDL_RenderCopy(&i_renderer, background_image_texture.get_sdl_texture(), &render_clip, nullptr))
      {
         LOG_ERROR("Failed to render f-rect, SDL Error: " << SDL_GetError());
         return false;
      }
      return true;
   };

   static auto i = 0;

   static FileSystem::Path sonic_sprite_sheet_path{std::string(ASSETS_DIRECTORY) + "/sonicSpriteSheet.png"};
   static auto sonic_sprite_sheet_surface = Graphics::Surface::create_from_image(sonic_sprite_sheet_path).value();
   static auto sonic_sprite_sheet_texture = renderer.create_texture_from_surface(std::move(sonic_sprite_sheet_surface)).value();
   static SDL_Rect sonic_sprite_clips[6];

   static auto sprite_width = 48;
   static auto sprite_height = 48;
   for (auto j=0; j<6; ++j) sonic_sprite_clips[j] = SDL_Rect{j*sprite_width, 0, sprite_width, sprite_height};
   
   auto sonic_render_instruction = [](SDL_Renderer& i_renderer)
   {
      SDL_Rect render_clip = sonic_sprite_clips[i++%6];
      SDL_Rect render_quad = render_clip;
      render_quad.x = -1 * sprite_width + i*5;
      render_quad.y = 100;
      if (0 != SDL_RenderCopy(&i_renderer, sonic_sprite_sheet_texture.get_sdl_texture(), &render_clip, &render_quad))
      {
         LOG_ERROR("Failed to render f-rect, SDL Error: " << SDL_GetError());
         return false;
      }
      return true;
   };

   auto background_image_instruction_temp = background_image_instruction;
   renderer.render(std::move(background_image_instruction_temp));

   auto sonic_render_instruction_temp = sonic_render_instruction;
   renderer.render(std::move(sonic_render_instruction_temp));
   
   /////////////////////////////////////////////////////////////////////////////////////////////////

   renderer.render_present();

   LOG_MESSAGE("Exit GameGraphics::render()");
}