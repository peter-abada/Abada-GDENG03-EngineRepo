#pragma once
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Base.h>
#include <DX3D/Math/Vec3.h>
#include <DX3D/Math/Vec4.h>

namespace dx3_d
{
	class GraphicsEngine final: public Base
	{
	public:
		GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;

		GraphicsDevice& getGraphicsDevice() noexcept;

		void render(SwapChain& swapChain, f32 deltaTime);

	private:
		struct Vertex
		{
			Vec3 position;
			Vec4 color;
		};
		struct alignas(16) ConstantData
		{
			f32 scale{};
		};

	private:
		//std::shared_ptr<GraphicsDevice> m_graphicsDevice{};
		//DeviceContextPtr m_deviceContext{};
		//GraphicsPipelineStatePtr m_pipline{};
		//VertexBufferPtr m_vb{};
		RefPtr<GraphicsDevice> m_graphicsDevice{};
		RefPtr<DeviceContext> m_deviceContext{};
		RefPtr<GraphicsPipelineState> m_pipeline{};
		RefPtr<VertexBuffer> m_vb{};
		RefPtr<ConstantBuffer> m_cb{};

		f32 m_sum{};
		f32 m_scale{};
	};

}

