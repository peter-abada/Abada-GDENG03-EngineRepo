#include "MainGame.h"

#include "Objects/ControlObject.h"
#include "Objects/Player.h"


MainGame::MainGame(const dx3_d::GameDesc& desc) : dx3_d::Game(desc)
{
}

void MainGame::onCreate()
{
	Game::onCreate();
	auto& world = getWorld();

	auto floor = world.createGameObject<dx3_d::GameObject>();
	floor->createOrGetComponent<dx3_d::CubeComponent>();
	floor->getTransform().setScale({ 6.8f, 0.01f, 6.8f });
	floor->getTransform().setPosition({ 0, 0, 0 });

	auto player = world.createGameObject<Player>();
	player->getTransform().setPosition({ 0, 1, -2 });

	auto controlObj = world.createGameObject<dx3_d::ControlObject>();
	controlObj->getTransform().setPosition({ 0, 1, 0 });

	getInputSystem().setCursorLocked(true);
	getInputSystem().setCursorVisible(false);

}

void MainGame::onUpdate(dx3_d::f32 deltaTime)
{
	Game::onUpdate(deltaTime);
}