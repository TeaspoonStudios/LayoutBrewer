#include "LayoutBrewer/ContainerPanel.hpp"
#include "LayoutBrewer/ImagePanel.hpp"

using namespace LayoutBrewer;

ImagePanel::ImagePanel(const Rect& rect, ContainerPanel* parent,  TeaPacket::Graphics::Texture* texture):
panel(PanelType::Image, rect, parent),
texture(texture)
{
    
}
