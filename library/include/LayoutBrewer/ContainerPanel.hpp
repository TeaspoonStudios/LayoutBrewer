#pragma once

#include "LayoutBrewer/Panel.hpp"

namespace LayoutBrewer
{
    class ImagePanel;
    
    class ContainerPanel
    {
        
        std::vector<ContainerPanel> subcontainers;
        std::vector<ImagePanel> images;
        Vector2f contentsSize;

    public:
        PanelNode panel = PanelNode(PanelType::Container);
        [[nodiscard]] Vector2f GetContentsSize()
        {
            if (contentsSize.x() == 0 && contentsSize.y() == 0)
            {
                contentsSize = panel.EvaluateInsideParentSpace().size;
            }
            return contentsSize;
        }

        
        ContainerPanel() = delete;
        ~ContainerPanel();
        explicit ContainerPanel(const Rect& rect, ContainerPanel* parent = nullptr, Vector2f contentsSize = Vector2f{0,0});
    };
}