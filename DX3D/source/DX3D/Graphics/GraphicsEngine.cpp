#include <DX3D/Graphics/GraphicsEngine.h>
#include "DX3D/Graphics/RenderSystem.h"

dx3_d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	
	m_renderSystem = std::make_shared<RenderSystem>(RenderSystemDesc{m_logger});
}

dx3_d::GraphicsEngine::~GraphicsEngine()
{
	
}

dx3_d::RenderSystem& dx3_d::GraphicsEngine::getRenderSystem() const noexcept
{
	return *m_renderSystem;
}