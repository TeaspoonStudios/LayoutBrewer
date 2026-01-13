include("${TEAPACKET_ROOT}/CMakeCommons/CommonFunctions.CMake")

file(GLOB_RECURSE sources source/*.c*)
add_library(LayoutBrewer ${sources})

TP_add_interface_subdirectory(Graphics)
TP_add_interface_subdirectory(Math)
target_link_libraries(LayoutBrewer TeaPacket_Graphics_Base TeaPacket_Math_Base)

target_include_directories(LayoutBrewer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

