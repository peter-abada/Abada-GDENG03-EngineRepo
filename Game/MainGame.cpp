#include "MainGame.h"
#include "Objects/MyObject.h"


MainGame::MainGame(const dx3_d::GameDesc& desc) : dx3_d::Game(desc)
{
}

void MainGame::onCreate()
{
	Game::onCreate();
	auto& world = getWorld();

	auto object = world.createGameObject<dx3_d::GameObject>();
	auto myObject = world.createGameObject<MyObject>();
}

void MainGame::onUpdate(dx3_d::f32 deltaTime)
{
	Game::onUpdate(deltaTime);
}