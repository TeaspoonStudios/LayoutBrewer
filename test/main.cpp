#include <iostream>

#include "LayoutBrewer/ContainerPanel.hpp"
#include "LayoutBrewer/ContainerPanelParams.hpp"
#include "LayoutBrewer/ImagePanelParams.hpp"
#include "LayoutBrewer/ImagePanel.hpp"
#include "LayoutBrewer/Panel.hpp"
#include "LayoutBrewer/Render.hpp"

#include "TeaPacket/Graphics/Display.hpp"
#include "TeaPacket/Graphics/DisplayParameters.hpp"
#include "TeaPacket/Graphics/Graphics.hpp"
#include "TeaPacket/Graphics/Mesh/Mesh.hpp"
#include "TeaPacket/Graphics/Mesh/MeshParameters.hpp"
#include "TeaPacket/Graphics/Shader/Shader.hpp"
#include "TeaPacket/Graphics/Shader/ShaderParameters.hpp"
#include "TeaPacket/Graphics/Texture/TextureData.hpp"
#include "TeaPacket/System/System.hpp"
#include "TeaPacket/Assets/ReadAsset.hpp"
#include "TeaPacket/Graphics/Shader/ShaderVariable.hpp"

#include "TeaPacket/Core/Core.hpp"
#include "TeaPacket/Extensions/STBImageLoader/ImageLoader.hpp"
#include "TeaPacket/Graphics/UniformBuffer.hpp"
#include "TeaPacket/Graphics/UniformBufferParameters.hpp"
#include "TeaPacket/Graphics/Texture/TextureParameters.hpp"



using namespace TeaPacket;
using namespace TeaPacket::Graphics;

int main()
{
    TeaPacket::Initialize();
    auto dispParams = DisplayParameters{
        .width = 1280,
        .height = 720};
    Display::InitializeDefaultDisplays({dispParams});

    constexpr auto texParms = TextureParameters{
        .data = nullptr,
        .width = 3,
        .height = 3,
        .format = TextureFormat::RGBA8,
        .useFlags = TextureUseFlags{
            .shaderResource = true,
            .renderTargetColor = false,
            .renderTargetDepth = false,
            .writeMode = TextureAvailableMode::None,
            .cpuReadable = false
        },
        .filterMode = TextureFilterMode::Linear,
        .wrapMode = TextureWrapMode::Wrap
    };
    auto tex= Extensions::STBImageLoader::LoadImage("testimg.png", texParms);

    auto tex2 = Extensions::STBImageLoader::LoadImage("test2.png", texParms);

    LayoutBrewer::ContainerPanel screenContainer(LayoutBrewer::ContainerPanelParams{
    .rect = {},
    .subcontainers = {},
    .images = {
        {
            .rect = {
                .anchorPoint = {0,0},
                .positionScale = {0,0},
                .positionOffset = {100,100},
                .sizeScale = {0,0},
                .sizeOffset = {(float)tex.GetWidth(),(float)tex.GetHeight()}
            },
            .texture = &tex,
        },
        {
            .rect = {
                .anchorPoint = {0,0},
                .positionScale = {0,0},
                .positionOffset = {0,0},
                .sizeScale = {0,0},
                .sizeOffset = {100,100}
            },
            .texture = &tex2,
        }
    },
    .contentsSize = {1280,720}
});
    
    
    while (System::ShouldRun())
    {
        System::ProcessSystem();
        Display::BeginRender(0);

        Viewport::ClearColor(0, 0, 0);
        //uniformBuffer.SetActive(0);
        LayoutBrewer::Render::SetupRender();
        LayoutBrewer::Render::Render(screenContainer);
        
        Display::FinishRender(0);
        Display::PresentAll();
    }
    TeaPacket::DeInitialize();
}