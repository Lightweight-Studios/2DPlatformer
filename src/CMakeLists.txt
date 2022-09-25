message("%% Entering src")

####################################################################################################
# Make necessary inclusions and add relevant subdirectories
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/graphics)

####################################################################################################
# Set source files
set(${PROJECT_NAME}_SOURCE_FILES
    ${GRAPHICS_SOURCE_FILES}

    ${CMAKE_CURRENT_LIST_DIR}/main.cpp

    CACHE INTERNAL "${PROJECT_NAME}_SOURCE_FILES")

####################################################################################################
# Set header files
set(${PROJECT_NAME}_HEADER_FILES
    ${GRAPHICS_HEADER_FILES}

    CACHE INTERNAL "${PROJECT_NAME}_HEADER_FILES")

####################################################################################################
# Set include dirs
set(${PROJECT_NAME}_INCLUDE_DIRS
    ${GRAPHICS_INCLUDE_DIRS}

    ${CMAKE_CURRENT_LIST_DIR}

    CACHE INTERNAL "${PROJECT_NAME}_INCLUDE_DIRS")