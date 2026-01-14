#pragma once

#include <vector>

#include "TeaPacket/Math/Vector2.hpp"

namespace LayoutBrewer
{
    class ImagePanel;
    class ContainerPanel;
    struct Rect;
    struct ImagePanelParams;

    struct ContainerPanelParams
    {
        const Rect& rect;
        const std::vector<ContainerPanelParams>& subcontainers;
        const std::vector<ImagePanelParams>& images;
        Vector2f contentsSize = Vector2f{0,0};
    };
}
