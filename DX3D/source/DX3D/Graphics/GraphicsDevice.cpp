#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/ShaderBinary.h>
#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/VertexBuffer.h>
#include <DX3D/Graphics/VertexShaderSignature.h>

dx3_d::GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc& desc) : Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	DX3DGraphicsLogThrowOnFail(D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0,
		D3D11_SDK_VERSION, &m_d3dDevice, &featureLevel, &m_d3dDeviceContext),
		"Direct3D11 Init failed.")

		DX3DGraphicsLogThrowOnFail(m_d3dDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)), "QueryInterface for IDXGIDevice failed.")

		DX3DGraphicsLogThrowOnFail(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter)), "Get parent failed to retrieve IDXGIAdapter.")

		DX3DGraphicsLogThrowOnFail(m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory)), "Get parent failed to retrieve IDXGIFactory.")

	
}

dx3_d::GraphicsDevice::~GraphicsDevice()
{
}

dx3_d::SwapChainPtr dx3_d::GraphicsDevice::createSwapChain(const SwapChainDesc& desc) const
{
	return std::make_shared<SwapChain>(desc, getGraphicsResourceDesc());
}

dx3_d::DeviceContextPtr dx3_d::GraphicsDevice::createDeviceContext()
{
	return std::make_shared<DeviceContext>(getGraphicsResourceDesc());
}

dx3_d::ShaderBinaryPtr dx3_d::GraphicsDevice::compileShader(const ShaderCompileDesc& desc)
{
	return std::make_shared<ShaderBinary>(desc, getGraphicsResourceDesc());
}

dx3_d::GraphicsPipelineStatePtr dx3_d::GraphicsDevice::createGraphicsPipelineState(const GraphicsPipelineStateDesc& desc)
{
	return std::make_shared<GraphicsPipelineState>(desc, getGraphicsResourceDesc());
}

dx3_d::VertexBufferPtr dx3_d::GraphicsDevice::createVertexBuffer(const VertexBufferDesc& desc)
{
	return std::make_shared<VertexBuffer>(desc, getGraphicsResourceDesc());
}

dx3_d::VertexShaderSignaturePtr dx3_d::GraphicsDevice::CreateVertexShaderSignature(
	const VertexShaderSignatureDesc& desc)
{
	return std::make_shared<VertexShaderSignature>(desc, getGraphicsResourceDesc());
}

void dx3_d::GraphicsDevice::executeCommandList(DeviceContext& context)
{
	Microsoft::WRL::ComPtr<ID3D11CommandList> list{};
	DX3DGraphicsLogThrowOnFail (context.m_context->FinishCommandList(false, &list), "FinishCommandList failed.");

	m_d3dDeviceContext->ExecuteCommandList(list.Get(), false);
}

dx3_d::GraphicsResourceDesc dx3_d::GraphicsDevice::getGraphicsResourceDesc() const noexcept
{
	return {{m_logger}, shared_from_this(), *m_d3dDevice.Get(), *m_dxgiFactory.Get()};
}
