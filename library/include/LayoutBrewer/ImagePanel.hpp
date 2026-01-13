#pragma once

#include "LayoutBrewer/Panel.hpp"

namespace TeaPacket::Graphics
{
    class Texture;
}

namespace LayoutBrewer
{
    
    class ImagePanel
    {
    public:
        PanelNode panel = PanelNode(PanelType::Image);
        TeaPacket::Graphics::Texture* texture;
        
        explicit ImagePanel(const Rect& rect, ContainerPanel* parent = nullptr, TeaPacket::Graphics::Texture* texture = nullptr);
    };
}