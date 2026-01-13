#include <iostream>

#include "LayoutBrewer/ContainerPanel.hpp"
#include "LayoutBrewer/ImagePanel.hpp"
#include "LayoutBrewer/Panel.hpp"

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
#include "TeaPacket/Graphics/Texture/TextureParameters.hpp"
#include "TeaPacket/Graphics/Shader/ShaderVariable.hpp"

#include "TeaPacket/Core/Core.hpp"
#include "TeaPacket/Graphics/UniformBuffer.hpp"
#include "TeaPacket/Graphics/UniformBufferParameters.hpp"

constexpr float vertData[] = {
    0.0f,1.0f,
    1.0f,1.0f,
    0.0f,0.0f,
    1.0f,0.0f
};

unsigned long faceData[] = {
    0, 1, 2,
    1, 3, 2
};

using namespace TeaPacket;
using namespace TeaPacket::Graphics;

int main()
{
    LayoutBrewer::ContainerPanel screenContainer(LayoutBrewer::Rect{
        .anchorPoint = {0,0},
        .positionScale = {0,0},
        .positionOffset = {0,0},
        .sizeScale = {0,0},
        .sizeOffset = {0,0}
    },
    nullptr,
    {1280,720});

    LayoutBrewer::ImagePanel image(LayoutBrewer::Rect{
        .anchorPoint = {.5f,.5f},
        .positionScale = {.5f,.5f},
        .positionOffset = {0,0},
        .sizeScale = {1,1},
        .sizeOffset = {-20,-20}
    },
    &screenContainer);

    LayoutBrewer::PositionedRect screenRect = image.panel.EvaluateScreenPosition();

    

    TeaPacket::Initialize();
    auto dispParams = DisplayParameters{
        .width = static_cast<unsigned short>(screenContainer.GetContentsSize().x()),
        .height = static_cast<unsigned short>(screenContainer.GetContentsSize().y())};
    Display::InitializeDefaultDisplays({dispParams});
    
    
    auto vertInfo = std::vector<ShaderVariableType>(1);
    vertInfo[0].amount = 2;
    vertInfo[0].baseType = ShaderVariableBaseType::Float;
    
    const auto meshParms = MeshParameters{
        .flags = MeshFlags{.useIndices = true},
        .vertexData = BorrowedFixedArray((void*)vertData, sizeof(vertData)),
        .vertexInfo = vertInfo,
        .indices = BorrowedFixedArray(faceData, std::size(faceData))
    };
    auto mesh = Mesh(meshParms);
    
    const auto shaderParms = ShaderParameters{
        .flags = {},
        .vertexShaderCode = Assets::ReadTextFile("test.vert"),
        .fragmentShaderCode = Assets::ReadTextFile("test.frag"),
        .inputAttributes = vertInfo,
    };
    auto shader = Shader(shaderParms);
    
    const auto uniBufferParms = UniformBufferParameters{
        .data = (void*)&screenRect,
        .size = sizeof(screenRect)
    };
    UniformBuffer uniformBuffer(uniBufferParms);
    uniformBuffer.SetActive(0);
    
    
    while (System::ShouldRun())
    {
        System::ProcessSystem();
        Display::BeginRender(0);

        Viewport::ClearColor(0, 0, 0);
        mesh.SetActive();
        shader.SetActive();
        DrawMesh();
        
        Display::FinishRender(0);
        Display::PresentAll();
    }
    TeaPacket::DeInitialize();
}