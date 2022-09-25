message("%% Entering GetDependencies.cmake")

####################################################################################################
# Include for dynamically pulling dependencies
include(FetchContent)

####################################################################################################
# Declare dependency versions
## https://github.com/libsdl-org/SDL/releases/tag/release-2.24.0
set(SDL2_RELEASE_VERSION "2.24.0")

####################################################################################################
# SDL2
FetchContent_Declare(SDL2
                     URL "https://github.com/libsdl-org/SDL/archive/refs/tags/release-${SDL2_RELEASE_VERSION}.zip")
FetchContent_MakeAvailable(SDL2)

set(SDL2_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/_deps/sdl2-src/include)
set(SDL2_LIBRARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/_deps/sdl2-build/Debug)
set(SDL2_LIBRARIES 
    ${SDL2_LIBRARY_DIR}/SDL2d.lib
    ${SDL2_LIBRARY_DIR}/SDL2maind.lib)

####################################################################################################
# Set overall project dependency variables
set(${PROJECT_NAME}_DEPENDENCY_INCLUDE_DIRS

    ${SDL2_INCLUDE_DIRS}
    
    CACHE INTERNAL "${PROJECT_NAME}_DEPENDENCY_INCLUDE_DIRS")

set(${PROJECT_NAME}_DEPENDENCY_LIBRARIES

    ${SDL2_LIBRARIES}
    
    CACHE INTERNAL "${PROJECT_NAME}_DEPENDENCY_LIBRARIES")