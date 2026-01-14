#include "LayoutBrewer/Render.hpp"

#include "LayoutBrewer/ContainerPanel.hpp"
#include "LayoutBrewer/ImagePanel.hpp"
#include "TeaPacket/Assets/ReadAsset.hpp"

#include "TeaPacket/Graphics/Graphics.hpp"
#include "TeaPacket/Graphics/UniformBuffer.hpp"
#include "TeaPacket/Graphics/Mesh/Mesh.hpp"
#include "TeaPacket/Graphics/Mesh/MeshParameters.hpp"
#include "TeaPacket/Graphics/Shader/Shader.hpp"
#include "TeaPacket/Graphics/Shader/ShaderParameters.hpp"
#include "TeaPacket/Graphics/Texture/Texture.hpp"

using namespace LayoutBrewer;
using namespace TeaPacket;
using namespace TeaPacket::Graphics;

constexpr static float vertData[] = {
    0.0f, 1.0f, 0.0f, 1.0f, 
    1.0f, 1.0f, 1.0f, 1.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 1.0f, 0.0f
};

static unsigned long faceData[] = {
    0, 1, 2,
    1, 3, 2
};

const static std::vector vertInfo = {
    ShaderVariableType(ShaderVariableBaseType::Float, 2),
    ShaderVariableType(ShaderVariableBaseType::Float, 2)
};

static Mesh& LayoutBrewerMesh()
{
    const auto meshParms = MeshParameters{
        .flags = MeshFlags{.useIndices = true},
        .vertexData = BorrowedFixedArray((void*)vertData, sizeof(vertData)),
        .vertexInfo = vertInfo,
        .indices = BorrowedFixedArray(faceData, std::size(faceData))
    };
    static auto mesh = Mesh(meshParms);
    return mesh;
}

static Shader& LayoutBrewerShader()
{
    const auto shaderParms = ShaderParameters{
        .flags = {},
        .vertexShaderCode = Assets::ReadTextFile("test.vert"),
        .fragmentShaderCode = Assets::ReadTextFile("test.frag"),
        .inputAttributes = vertInfo,
    };
    static auto shader = Shader(shaderParms);
    return shader;
}

void Render::SetupRender()
{
    LayoutBrewerMesh().SetActive();
    LayoutBrewerShader().SetActive();
}


void Render::Render(ContainerPanel& panel)
{
    const size_t imgCount = panel.GetChildImageCount();
    for (size_t i = 0; i < imgCount; ++i)
    {
        ImagePanel& img = panel.GetChildImage(i);
        PositionedRect rect = img.panel.EvaluateScreenPosition();
        img.uniformBuffer.SendData(&rect);
        img.uniformBuffer.SetActive(0);
        img.texture->SetActive(1);
        DrawMesh();
    }
    const size_t subCount = panel.GetChildContainerCount();
    for (size_t i = 0; i < subCount; ++i)
    {
        Render(panel.GetChildContainer(i));
    }
}
