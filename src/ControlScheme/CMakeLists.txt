message("%% Entering control scheme")

####################################################################################################
# Set source files
set(CONTROL_SCHEME_FILES
    
    #${CMAKE_CURRENT_LIST_DIR}/
    ${CMAKE_CURRENT_LIST_DIR}/StdKeyBoardCtrlScheme.cpp

    CACHE INTERNAL "CONTROL_SCHEME_FILES")

####################################################################################################
# Set header files
set(CONTROL_SCHEME_HEADER_FILES

    #${CMAKE_CURRENT_LIST_DIR}/
    ${CMAKE_CURRENT_LIST_DIR}/ControlScheme.hpp
    ${CMAKE_CURRENT_LIST_DIR}/StdKeyBoardCtrlScheme.hpp

    CACHE INTERNAL "CONTROL_SCHEME_HEADER_FILES")

####################################################################################################
# Set include dirs
set(CONTROL_SCHEME_INCLUDE_DIRS

    ${CMAKE_CURRENT_LIST_DIR}

    CACHE INTERNAL "CONTROL_SCHEME_INCLUDE_DIRS")