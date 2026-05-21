#pragma once
#include <DX3D/Core/Core.h>
#include "DX3D/Core/Base.h"

namespace dx3_d
{
	class GraphicsEngine final: public Base
	{
	public:
		GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;

		RenderSystem& getRenderSystem() const noexcept;

	private:
		std::shared_ptr<RenderSystem> m_renderSystem{};
	};

}

