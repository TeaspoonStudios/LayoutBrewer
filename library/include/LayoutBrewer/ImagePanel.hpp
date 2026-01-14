#pragma once

#include "LayoutBrewer/Panel.hpp"
#include "TeaPacket/Graphics/UniformBuffer.hpp"
#include "TeaPacket/Graphics/UniformBufferParameters.hpp"

namespace TeaPacket::Graphics
{
    class Texture;
}

namespace LayoutBrewer
{
    struct ImagePanelParams;
    
    class ImagePanel
    {
    public:
        PanelNode panel = PanelNode(PanelType::Image);
        TeaPacket::Graphics::Texture* texture;
        TeaPacket::Graphics::UniformBuffer uniformBuffer = TeaPacket::Graphics::UniformBuffer(TeaPacket::Graphics::UniformBufferParameters{
            .data = nullptr,
            .size = sizeof(PositionedRect)
        });
        
        explicit ImagePanel(const ImagePanelParams& params);
        ImagePanel(ImagePanel&& other) noexcept;
        ImagePanel(const ImagePanel& other) = default;
    };
}