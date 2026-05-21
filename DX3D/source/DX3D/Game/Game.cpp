#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>

dx3_d::Game::Game()
{
	m_display = std::make_unique<Window>();
}

dx3_d::Game::~Game()
{
}


