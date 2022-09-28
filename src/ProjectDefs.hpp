#pragma once

#include "Logger.hpp"

#include <assert.h>

#define CHECK_IF_POINTER_VALID_RETURN_BOOL(ptr) \
   if (nullptr == ptr) \
   { \
      LOG_ERROR("Given pointer '" << #ptr << "' is null!"); \
      assert(nullptr != ptr); \
      return false; \
   } \

#define WATCH_VALUE_MESSAGE(value) LogMessage(#value << " is: " << value);
#define WATCH_VALUE_WARNING(value) LogWarning(#value << " is: " << value);
#define WATCH_VALUE_ERROR(value) LogError(#value << " is: " << value);