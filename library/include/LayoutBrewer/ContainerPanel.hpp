#pragma once

#include "LayoutBrewer/Panel.hpp"

namespace LayoutBrewer
{
    struct ContainerPanelParams;
}

namespace LayoutBrewer
{
    class ImagePanel;
    
    class ContainerPanel
    {
        
        std::vector<ContainerPanel> subcontainers;
        std::vector<ImagePanel> images;
        Vector2f contentsSize;

        explicit ContainerPanel(const ContainerPanelParams& params, ContainerPanel* parent);

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

        [[nodiscard]] ContainerPanel& GetChildContainer(const size_t i);
        [[nodiscard]] ImagePanel& GetChildImage(const size_t i);
        [[nodiscard]] size_t GetChildContainerCount() const;
        [[nodiscard]] size_t GetChildImageCount() const;


        ContainerPanel() = delete;
        ~ContainerPanel();
        explicit ContainerPanel(const ContainerPanelParams& params);
    };
}
