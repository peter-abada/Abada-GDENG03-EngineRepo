#include <DX3D/Graphics/GraphicsEngine.h>
#include "DX3D/Graphics/GraphicsDevice.h"
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>

dx3_d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	
	m_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{m_logger});

	auto& device = *m_graphicsDevice;
	m_deviceContext = device.createDeviceContext();

	constexpr char shaderSourceCode[] =
		R"(
void VSMain()
{

}
void PSMain()
{
	
}
)";
	constexpr char shaderSourceName[] = "Basic";
	constexpr auto shaderSourceCodeSize = std::size(shaderSourceCode);

	auto vs = device.compileShader({shaderSourceName, shaderSourceCode, shaderSourceCodeSize, "VSMain", ShaderType::VertexShader});
	auto ps = device.compileShader({ shaderSourceName, shaderSourceCode, shaderSourceCodeSize, "PSMain", ShaderType::PixelShader});

	m_pipline = device.createGraphicsPipelineState({ *vs, *ps });
}

dx3_d::GraphicsEngine::~GraphicsEngine()
{
	
}

dx3_d::GraphicsDevice& dx3_d::GraphicsEngine::getGraphicsDevice() noexcept
{
	return *m_graphicsDevice;
}

void dx3_d::GraphicsEngine::render(SwapChain& swapChain)
{
	auto& context = *m_deviceContext;
	context.clearAndSetBackBuffer(swapChain, { 1, 0, 0, 1 });
	context.setGraphicsPipelineState(*m_pipline);

	auto& device = *m_graphicsDevice;
	device.executeCommandList(context);
	swapChain.present();
}
