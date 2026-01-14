#include "LayoutBrewer/ContainerPanel.hpp"

#include "LayoutBrewer/ContainerPanelParams.hpp"
#include "LayoutBrewer/ImagePanelParams.hpp"
#include "LayoutBrewer/ImagePanel.hpp"

using namespace LayoutBrewer;

ContainerPanel::ContainerPanel(const ContainerPanelParams& params) : ContainerPanel(params, nullptr)
{
    
}

ContainerPanel::ContainerPanel(const ContainerPanelParams& params, ContainerPanel* parent):
    contentsSize(params.contentsSize),
    panel(PanelType::Container, params.rect, parent)
{
    for (auto & subcontainerParams : params.subcontainers)
    {
        subcontainers.emplace_back(ContainerPanel(subcontainerParams, this));
    }
    for (auto & subImageParams : params.images)
    {
        ImagePanelParams imageParms = subImageParams;
        imageParms.parent = this;
        images.emplace_back(imageParms);
    }
}

ContainerPanel& ContainerPanel::GetChildContainer(const size_t i)
{ return subcontainers[i]; }

ImagePanel& ContainerPanel::GetChildImage(const size_t i)
{ return images[i]; }

size_t ContainerPanel::GetChildContainerCount() const
{ return subcontainers.size(); }

size_t ContainerPanel::GetChildImageCount() const
{ return images.size(); }

ContainerPanel::~ContainerPanel() = default;
