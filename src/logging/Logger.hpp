#pragma once

#ifndef SILENCE_LOGGING

   #include <iostream>

   #define LOG_MESSAGE(message) \
      std::cout << "LOG | " << __FILE__ << " - " << \
                               __func__ << " - " << \
                               __LINE__ << ": " << \
                               message << std::endl;
   #define LOG_WARNING(warning) \
      std::cout << "WRN | " << __FILE__ << " - " << \
                               __func__ << " - " << \
                               __LINE__ << ": " << \
                               warning << std::endl;
   #define LOG_ERROR(error) \
      std::cerr << "ERR | " << __FILE__ << " - " << \
                               __func__ << " - " << \
                               __LINE__ << ": " << \
                               error << std::endl;

#else 

   #define LOG_MESSAGE(message) (void)
   #define LOG_WARNING(warning) (void)
   #define LOG_ERROR(error) (void)

#endif