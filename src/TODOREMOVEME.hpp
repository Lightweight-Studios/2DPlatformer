#pragma once

#include "Logger.hpp"
#include "Texture.hpp"

#include <memory>

// This is solely here as a temporary test file to use/alter game state from different systems
// of the game EG: Input, game logic, and rendering
namespace TODORemove
{

enum class Direction
{
   left = 0,
   right = 1,
   up = 2,
   down = 3
};

struct PlayerData
{
   int m_health = 100;

   float m_height = 0;
   float m_width = 0;
   float m_mass = 0;

   float m_x_position = 0;
   float m_y_position = 0;

   Direction m_facing_direction = Direction::right;

   float m_x_velocity = 0;
   float m_y_velocity = 0;

   float m_x_acceleration = 0;
   float m_y_acceleration = 0;

   std::shared_ptr<Graphics::Texture> m_sprite_sheet_texture = nullptr;
   // Associated with frame set of is_moving or is_still depending on current state
   size_t m_current_clip_frame = 0; 

   bool is_alive() const noexcept
   {
      return m_health > 0;
   }

   bool is_dead() const noexcept
   {
      return !is_alive();
   }

   bool is_still() const noexcept
   {
      return m_x_velocity == 0.0 && 
             m_y_velocity == 0.0 && 
             m_x_acceleration == 0.0 && 
             m_y_acceleration == 0.0;
   }

   bool is_moving() const noexcept
   {
      return !is_still();
   }

   bool is_moving(Direction direction) const noexcept
   {
      switch (direction)
      {
      case Direction::left:
         return m_x_velocity < 0.0;
      case Direction::right:
         return m_x_velocity > 0.0;
      case Direction::up:
         return m_y_velocity > 0.0;
      case Direction::down:
         return m_y_velocity < 0.0;
      default:
         LOG_ERROR("Invalid direction provided!");
      }

      return false;
   }

   bool is_accelerating(Direction direction) const noexcept
   {
      switch (direction)
      {
      case Direction::left:
         return m_x_acceleration < 0.0;
      case Direction::right:
         return m_x_acceleration > 0.0;
      case Direction::up:
         return m_y_acceleration > 0.0;
      case Direction::down:
         return m_x_acceleration < 0.0;
      default:
         LOG_ERROR("Invalid direction provided!");
      }

      return false;
   }

   bool is_decelerating(Direction direction) const noexcept
   {
      switch (direction)
      {
      case Direction::left:
         return m_x_acceleration > 0.0;
      case Direction::right:
         return m_x_acceleration < 0.0;
      case Direction::up:
         return m_y_acceleration < 0.0;
      case Direction::down:
         return m_x_acceleration > 0.0;
      default:
         LOG_ERROR("Invalid direction provided!");
      }

      return false;
   }

};

// After rendering in the game loop, last_state will be set to current_state, and current_state
// will maintain whatever it had before as if flying through space uninhibited
static PlayerData s_main_player_last_state;
static PlayerData s_main_player_current_state;

}
