#pragma once

#include "GraphicsDefs.hpp"
#include "Logger.hpp"

#include "SDL_rect.h"

namespace Graphics
{

namespace RenderInstructionFactory
{
   /////////////////////////////////////////////////////////////////////////////////////////////////
   // Declarations
   inline RenderInstruction_t get_instruction(SDL_Rect i_rectangle);
   inline RenderInstruction_t get_instruction(SDL_FRect i_rectangle);

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // Definitions
   inline RenderInstruction_t get_instruction(SDL_Rect i_rectangle)
   {
      return [rect = std::move(i_rectangle)](SDL_Renderer& i_renderer)
      {
         if (0 != SDL_RenderFillRect(&i_renderer, &rect))
         {
            LOG_ERROR("Failed to render rect, SDL Error: " << SDL_GetError());
            return false;
         }
         return true;
      };
   }

   inline RenderInstruction_t get_instruction(SDL_FRect i_rectangle)
   {
      return [rect = std::move(i_rectangle)](SDL_Renderer& i_renderer)
      {
         if (0 != SDL_RenderFillRectF(&i_renderer, &rect))
         {
            LOG_ERROR("Failed to render f-rect, SDL Error: " << SDL_GetError());
            return false;
         }
         return true;
      };
   }

} // RenderInstructionFactory

} // Graphics