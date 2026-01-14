#pragma once

#include <vector>

#include "TeaPacket/Math/Vector2.hpp"
namespace TeaPacket::Graphics
{
    class Texture;
}

namespace LayoutBrewer
{
    struct Rect;
    class ContainerPanel;

    struct ImagePanelParams
    {
        const Rect& rect;
        TeaPacket::Graphics::Texture* texture;
        ContainerPanel* parent;
    };
}
