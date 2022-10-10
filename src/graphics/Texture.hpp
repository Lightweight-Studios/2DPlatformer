#pragma once

#include <optional>

// Forward declarations
class SDL_Texture;

namespace Graphics
{

// @warning This class is not thread safe 
class Texture
{
   // Friend permissions provided as the Renderer acts as a factory for Textures
   friend class Renderer;

public:

   Texture() = delete;
   Texture(const Texture&) = delete;
   Texture(Texture&&);

   virtual ~Texture();

   Texture& operator=(const Texture&) = delete;
   Texture& operator=(Texture&&);

   // @warning Teardown any Texture before exiting the SDL for the sake of cleanliness
   void teardown();

private:

   Texture(SDL_Texture* i_texture);

   void teardown_internal();

   SDL_Texture* m_texture;

};

} // Graphics