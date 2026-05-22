#pragma once
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3_d
{
	class GraphicsPipelineState final : public GraphicsResource
	{
	public:
		GraphicsPipelineState(const GraphicsPipelineStateDesc& desc, const GraphicsResourceDesc& gDesc);

	private:
		Microsoft::WRL::ComPtr<ID3D11VertexShader> m_vs{};
		Microsoft::WRL::ComPtr<ID3D11PixelShader> m_ps{};

		friend class DeviceContext;
	};
}

