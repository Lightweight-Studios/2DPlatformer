####################################################################################################
# Fundamental project setup
cmake_minimum_required(VERSION 3.23)
set(PROJECT_NAME "2DPlatformer")
message("%% Entering ${PROJECT_NAME} cmake project")
project(${PROJECT_NAME})

####################################################################################################
# List project options
## Turns off all logging
option(SILENCE_LOGGING "Silence ${PROJECT_NAME} logging" OFF)
message("%% SILENCE_LOGGING set to ${SILENCE_LOGGING}")

## Enables unit testing in build
option(BUILD_UNIT_TESTS "Build ${PROJECT_NAME} unit tests" OFF)
message("%% BUILD_UNIT_TESTS set to ${BUILD_UNIT_TESTS}")

####################################################################################################
# Establish project standards
message("%% Using C++20")
set(CMAKE_CXX_STANDARD 20)

####################################################################################################
# Make necessary inclusions and add relevant subdirectories
include(${CMAKE_CURRENT_LIST_DIR}/GetDependencies.cmake)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)

####################################################################################################
# Ensure known directories included to ensure flat file structure in source code includes
include_directories(${${PROJECT_NAME}_DEPENDENCY_INCLUDE_DIRS}
                    ${${PROJECT_NAME}_INCLUDE_DIRS})

####################################################################################################
# Create executable and make necessary library linkages
add_executable(${PROJECT_NAME} 
               ${${PROJECT_NAME}_SOURCE_FILES}
               ${${PROJECT_NAME}_HEADER_FILES})
target_link_libraries(${PROJECT_NAME} 
                      ${${PROJECT_NAME}_DEPENDENCY_LIBRARIES})