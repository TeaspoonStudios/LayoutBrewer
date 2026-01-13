#pragma once

#include "TeaPacket/Math/Vector2.hpp"
#include <iostream>

namespace LayoutBrewer{
    struct PositionedRect
    {
        Vector2f topLeft{};
        Vector2f size{};
    };
};
inline std::ostream& operator << (std::ostream &os, const LayoutBrewer::PositionedRect &s) {
    return (os
    << "posi: (" << s.topLeft.x() << "," << s.topLeft.y() << ") "
    << "size: (" << s.size.x() << "," << s.size.y() << ") "
    << std::endl);
}