#pragma once

#ifndef SILENCE_LOGGING

   #define LOG_MESSAGE(...) (void)
   #define LOG_WARNING(...) (void)
   #define LOG_ERROR(...) (void)

#else 

   #define LOG_MESSAGE(...) (void)
   #define LOG_WARNING(...) (void)
   #define LOG_ERROR(...) (void)

#endif