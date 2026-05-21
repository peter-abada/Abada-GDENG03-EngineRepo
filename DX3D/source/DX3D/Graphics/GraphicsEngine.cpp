#include <DX3D/Graphics/GraphicsEngine.h>
#include "DX3D/Graphics/RenderSystem.h"

dx3_d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	m_renderSystem = std::make_unique<RenderSystem>(RenderSystemDesc{m_logger});
}

dx3_d::GraphicsEngine::~GraphicsEngine()
{
	
}
