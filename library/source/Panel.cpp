#include "LayoutBrewer/Panel.hpp"

#include <cassert>
#include <execution>

#include "LayoutBrewer/ContainerPanel.hpp"


using namespace LayoutBrewer;

PositionedRect PanelNode::EvaluateInsideParentSpace() const
{
    assert(parent);
    const Vector2f size = rect.sizeOffset + (rect.sizeScale * parent->GetContentsSize());
    return PositionedRect{
        .topLeft = rect.positionOffset + (rect.positionScale * parent->GetContentsSize()) - (size * rect.anchorPoint),
        .size = size
    };
}

PositionedRect PanelNode::EvaluateInsideParent() const
{
    const auto [topLeft, size] = EvaluateInsideParentSpace();
    return {
        .topLeft = topLeft / parent->GetContentsSize(),
        .size = size / parent->GetContentsSize()
    };
}

PositionedRect PanelNode::EvaluateScreenPosition()
{
    // ReSharper disable once CppDFAConstantConditions
    if (parent == nullptr)
    {
        return PositionedRect{{0,0}, {1,1}};
    }

    // ReSharper disable once CppDFAUnreachableCode
    if (rectCacheInvalid)
    {
        // Recalculate cached rect
        const PositionedRect parentRect = parent->panel.EvaluateScreenPosition();
    
        const PositionedRect inParentRect = EvaluateInsideParent();
        cachedRect = PositionedRect{
            .topLeft = (inParentRect.topLeft * parentRect.size) + parentRect.topLeft,
            .size = (inParentRect.size * parentRect.size) + parentRect.topLeft,
        };
        rectCacheInvalid = false;
    }
    return cachedRect;
    
}

PositionedRect PanelNode::EvaluateScreenCoordinates()
{
    PositionedRect screenRect = EvaluateScreenPosition();
    ContainerPanel* screenPanel = parent;
    // ReSharper disable once CppDFAConstantConditions
    while (screenPanel->panel.parent)
    {
        screenPanel = screenPanel->panel.parent;
    }
    screenRect.topLeft *= screenPanel->GetContentsSize();
    screenRect.size *= screenPanel->GetContentsSize();
    return screenRect;
}
