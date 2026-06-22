#pragma once
#include "DX3D/Core/Base.h"
#include <d3d11.h>
#include <wrl.h>
#include <DX3D/Core/Common.h>

#include "GraphicsResource.h"

namespace dx3_d
{
	class GraphicsDevice final : public Base, public std::enable_shared_from_this<GraphicsDevice>
	{
	public:
		explicit GraphicsDevice(const GraphicsDeviceDesc& desc);
		virtual ~GraphicsDevice() override;

		RefPtr<SwapChain> createSwapChain(const SwapChainDesc& desc) const;
		RefPtr<DeviceContext> createDeviceContext();
		RefPtr<ShaderBinary> compileShader(const ShaderCompileDesc& desc);
		RefPtr<GraphicsPipelineState> createGraphicsPipelineState(const GraphicsPipelineStateDesc& desc);
		RefPtr<VertexBuffer> createVertexBuffer(const VertexBufferDesc& desc);
		RefPtr<VertexShaderSignature> CreateVertexShaderSignature(const VertexShaderSignatureDesc& desc);
		RefPtr<ConstantBuffer> createConstantBuffer(const ConstantBufferDesc& desc);

		void executeCommandList(DeviceContext& context);

	private:
		GraphicsResourceDesc getGraphicsResourceDesc() const noexcept;

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3dDeviceContext{};
		Microsoft::WRL::ComPtr<IDXGIDevice> m_dxgiDevice{};
		Microsoft::WRL::ComPtr<IDXGIAdapter> m_dxgiAdapter{};
		Microsoft::WRL::ComPtr<IDXGIFactory> m_dxgiFactory{};
	};

}

