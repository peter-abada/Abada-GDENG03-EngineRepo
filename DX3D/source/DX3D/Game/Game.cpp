#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>
#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Core/Logger.h>

#include "DX3D/Game/Display.h"

#include <DX3D/Game/World.h>
#include <DX3D/Game/GameObject.h>
#include <DX3D/Game/WorldRenderer.h>

dx3_d::Game::Game(const GameDesc& desc)
{
	//m_WorldRenderer = std::make_unique<WorldRenderer>(WorldRendererDesc{m_logger});
	//m_display = std::make_unique<Display>(DisplayDesc{ {m_logger, desc.windowSize}, m_WorldRenderer->getGraphicsDevice() });

	m_logger = std::make_unique<Logger>(desc.logLevel);

	DX3DLogInfo("Peter Abada | GDENG03 Window Test");
	DX3DLogInfo("<------------------------------->");

	m_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{ *m_logger });
	m_display = std::make_unique<Display>(DisplayDesc{ {*m_logger,desc.windowSize},*m_graphicsDevice });
	m_world = std::make_unique<World>(WorldDesc{ {*m_logger} });
	m_worldRenderer = std::make_unique<WorldRenderer>(WorldRendererDesc{ {*m_logger},*m_graphicsDevice });

	DX3DLogInfo("Game initialized successfully.");
}

dx3_d::Game::~Game()
{
	DX3DLogInfo("Game shutting down.");
}

dx3_d::World& dx3_d::Game::getWorld() noexcept
{
	return *m_world;
}

dx3_d::Logger& dx3_d::Game::getLogger() noexcept
{
	return *m_logger;
}

void dx3_d::Game::onInternalUpdate()
{
	//m_WorldRenderer->render(m_display->getSwapChain());
	auto currentTime = std::chrono::steady_clock::now();
	std::chrono::duration<f32> delta = currentTime - m_previousTime;
	m_previousTime = currentTime;
	auto deltaTime = delta.count();

	onUpdate(deltaTime);

	m_world->update(deltaTime);

	m_worldRenderer->render(*m_world, m_display->getSwapChain(), deltaTime);
}
