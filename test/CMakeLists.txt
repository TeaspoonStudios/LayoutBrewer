include("${TEAPACKET_ROOT}/Subtools/AssetMixer/Functions.CMake")

add_executable(LayoutBrewer_Test main.cpp)
TP_use_profile(Windows)
target_link_libraries(LayoutBrewer_Test LayoutBrewer)

# asset mixer temp
set(PARSER_DIRS "${TEAPACKET_ROOT}/Modules/Graphics/Direct3D11/AssetMixer/Parsers/")

TP_AM_BuildAssets(
        TARGET LayoutBrewer_Test
        SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/assets/"
        DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
        ASSET_PLATFORM "STDFile"
        PARSER_DIRS ${PARSER_DIRS}
)
set_target_properties(LayoutBrewer_Test PROPERTIES CXX_STANDARD 20)