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
	if (!myObject) return;

	auto transform = myObject->getComponent<dx3_d::TransformComponent>();
	if (!transform) return;

	transform->setPosition({ 10, 10, 10 });
	transform->setRotation({ 1.57f, 0.707f, 1.57f });

}

void MainGame::onUpdate(dx3_d::f32 deltaTime)
{
	Game::onUpdate(deltaTime);
}