cmake_minimum_required(VERSION 3.20)
project(LayoutBrewer)
set(CMAKE_CXX_STANDARD 20)

if(NOT DEFINED TEAPACKET_ROOT)
    if(DEFINED ENV{TEAPACKET_ROOT})
        set(TEAPACKET_ROOT $ENV{TEAPACKET_ROOT})
    else()
        message(FATAL_ERROR "TEAPACKET_ROOT must be defined!")
    endif()
endif ()

add_subdirectory(library)
add_subdirectory(test)