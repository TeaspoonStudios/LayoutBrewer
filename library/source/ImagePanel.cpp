#include "LayoutBrewer/ContainerPanel.hpp"
#include "LayoutBrewer/ImagePanel.hpp"

#include "LayoutBrewer/ImagePanelParams.hpp"

using namespace LayoutBrewer;

ImagePanel::ImagePanel(const ImagePanelParams& params):
panel(PanelType::Image, params.rect, params.parent),
texture(params.texture)
{
}

ImagePanel::ImagePanel(ImagePanel&& other) noexcept = default;