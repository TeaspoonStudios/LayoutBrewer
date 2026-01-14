#pragma once

#include "LayoutBrewer/Rect.hpp"
#include "LayoutBrewer/PositionedRect.hpp"
#include <vector>

#include "TeaPacket/Graphics/Graphics.hpp"

namespace TeaPacket::Graphics
{
    class Texture;
}

namespace LayoutBrewer
{
    class ContainerPanel;
    
    enum class PanelType : uint8_t
    {
        None = 0,
        Container,
        Image
    };
    
    class PanelNode
    {
    private:
        Rect rect;
        ContainerPanel* parent = nullptr;
        PositionedRect cachedRect;
        PanelType type;
        bool rectCacheInvalid = true;

    public:
        explicit PanelNode(
            const PanelType type,
            const Rect& rect = Rect{},
            ContainerPanel* parent = nullptr):
            rect(rect),
            parent(parent),
            type(type)
        {}

        [[nodiscard]] PositionedRect EvaluateInsideParentSpace() const;
        [[nodiscard]] PositionedRect EvaluateInsideParent() const;
        [[nodiscard]] PositionedRect EvaluateScreenPosition();
        [[nodiscard]] PositionedRect EvaluateScreenCoordinates();
        
    };
}
