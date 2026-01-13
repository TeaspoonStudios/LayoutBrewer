#include "LayoutBrewer/ContainerPanel.hpp"
#include "LayoutBrewer/ImagePanel.hpp"

using namespace LayoutBrewer;

ContainerPanel::ContainerPanel(const Rect& rect, ContainerPanel* parent, const Vector2f contentsSize):
    panel(PanelType::Container, rect, parent),
    subcontainers(),
    images(),
    contentsSize(contentsSize)
{
    
}

ContainerPanel::~ContainerPanel() = default;
