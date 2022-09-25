#pragma once

#include <optional>

// Forward declarations
class SDL_Surface;

namespace Graphics
{

class Surface
{
public:

   Surface() = delete;
   Surface(const Surface&) = delete;
   Surface(Surface&&) = default;

   Surface& operator=(const Surface&) = delete;
   Surface& operator=(Surface&&) = default;

   virtual ~Surface();

   static std::optional<Surface> create(SDL_Surface* sdl_surface);
   
   void teardown();

private:

   Surface(SDL_Surface* sdl_surface);

   void teardown_internal();

   SDL_Surface* m_sdl_surface = nullptr;

};

} // namespace Window