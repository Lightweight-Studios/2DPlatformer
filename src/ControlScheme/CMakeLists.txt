message("%% Entering control scheme")

####################################################################################################
# Set source files
set(INPUT_COMPONENT_SOURCE_FILES
    
    #${CMAKE_CURRENT_LIST_DIR}/
    ${CMAKE_CURRENT_LIST_DIR}/StdKeyBoardCtrlScheme.cpp

    CACHE INTERNAL "INPUT_COMPONENT_SOURCE_FILES")

####################################################################################################
# Set header files
set(INPUT_COMPONENT_HEADER_FILES

    #${CMAKE_CURRENT_LIST_DIR}/
    ${CMAKE_CURRENT_LIST_DIR}/ControlScheme.hpp
    ${CMAKE_CURRENT_LIST_DIR}/StdKeyBoardCtrlScheme.hpp

    CACHE INTERNAL "INPUT_COMPONENT_HEADER_FILES")

####################################################################################################
# Set include dirs
set(INPUT_COMPONENT_INCLUDE_DIRS

    ${CMAKE_CURRENT_LIST_DIR}

    CACHE INTERNAL "INPUT_COMPONENT_INCLUDE_DIRS")