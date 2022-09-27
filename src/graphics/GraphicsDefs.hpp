#pragma once

#include <stdint.h>

enum class Color
{
   WHITE = 0
};

struct RgbColor_t
{
   // TODO Constructors for general colors using enums

   uint8_t m_r;
   uint8_t m_g;
   uint8_t m_b;
   uint8_t m_a;
};