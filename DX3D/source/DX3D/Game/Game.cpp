#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>
#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Core/Logger.h>

#include "DX3D/Game/Display.h"

dx3_d::Game::Game(const GameDesc& desc)
{
	//m_graphicsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{m_logger});
	//m_display = std::make_unique<Display>(DisplayDesc{ {m_logger, desc.windowSize}, m_graphicsEngine->getGraphicsDevice() });

	m_logger = std::make_unique<Logger>(desc.logLevel);

	DX3DLogInfo("Peter Abada | GDENG03 Window Test");
	DX3DLogInfo("<------------------------------->");

	m_graphicsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{ *m_logger });
	m_display = std::make_unique<Display>(DisplayDesc{ { *m_logger, desc.windowSize }, m_graphicsEngine->getGraphicsDevice() });

	DX3DLogInfo("Game initialized successfully.");
}

dx3_d::Game::~Game()
{
	DX3DLogInfo("Game shutting down.");
}

dx3_d::Logger& dx3_d::Game::getLogger() noexcept
{
	return *m_logger;
}

void dx3_d::Game::onInternalUpdate()
{
	//m_graphicsEngine->render(m_display->getSwapChain());
	auto currentTime = std::chrono::steady_clock::now();
	std::chrono::duration<f32> delta = currentTime - m_previousTime;
	m_previousTime = currentTime;
	auto deltaTime = delta.count();

	m_graphicsEngine->render(m_display->getSwapChain(), deltaTime);
}
