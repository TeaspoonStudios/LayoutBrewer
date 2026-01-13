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
include("${TEAPACKET_ROOT}/CMakeCommons/CommonFunctions.CMake")

file(GLOB_RECURSE sources source/*.c*)
add_library(LayoutBrewer ${sources})

TP_add_interface_subdirectory(Graphics)
TP_add_interface_subdirectory(Math)
target_link_libraries(LayoutBrewer TeaPacket_Graphics_Base TeaPacket_Math_Base)

target_include_directories(LayoutBrewer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory(test)