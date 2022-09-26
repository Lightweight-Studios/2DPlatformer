#pragma once

#include <optional>

// Forward declarations
class SDL_Window;
class SDL_Renderer;

namespace Graphics
{

// @warning This class is not thread safe
class Renderer
{
public:

   Renderer() = delete;
   Renderer(const Renderer&) = delete;
   Renderer(Renderer&&);

   virtual ~Renderer();

   Renderer& operator=(const Renderer&) = delete;
   Renderer& operator=(Renderer&& rhs);

   static std::optional<Renderer> create(SDL_Renderer* sdl_renderer);
   
private:

   Renderer(SDL_Renderer* sdl_renderer);

   SDL_Renderer* m_sdl_renderer = nullptr;

};

} // namespace Window