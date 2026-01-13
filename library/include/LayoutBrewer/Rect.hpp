#pragma once

#include "TeaPacket/Math/Vector2.hpp"

namespace LayoutBrewer{
    struct Rect
    {
        Vector2f anchorPoint{0,0};

        Vector2f positionScale{0,0};
        Vector2f positionOffset{0,0};

        Vector2f sizeScale{0,0};
        Vector2f sizeOffset{0,0};
    };
};