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

		GraphicsDevice& getGraphicsDevice() noexcept;

		void render(SwapChain& swapChain);

	private:
		std::shared_ptr<GraphicsDevice> m_graphicsDevice{};
		DeviceContextPtr m_deviceContext{};
	};

}

