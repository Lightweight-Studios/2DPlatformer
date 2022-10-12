message("%% Entering EntityComponent")

####################################################################################################
# Set source files
set(ENTITY_COMPONENT_SOURCE_FILES

    CACHE INTERNAL "ENTITY_COMPONENT_SOURCE_FILES")

####################################################################################################
# Set header files
set(ENTITY_COMPONENT_HEADER_FILES

    ${CMAKE_CURRENT_LIST_DIR}/EntityComponentDefs.hpp

    CACHE INTERNAL "ENTITY_COMPONENT_HEADER_FILES")

####################################################################################################
# Set include dirs
set(ENTITY_COMPONENT_INCLUDE_DIRS
    ${CMAKE_CURRENT_LIST_DIR}

    CACHE INTERNAL "ENTITY_COMPONENT_INCLUDE_DIRS")