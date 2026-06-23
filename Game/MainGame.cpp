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
	object->createOrGetComponent<dx3_d::CubeComponent>();
	m_player = object;

	getInputSystem().setCursorLocked(true);
	getInputSystem().setCursorVisible(false);

}

void MainGame::onUpdate(dx3_d::f32 deltaTime)
{
	Game::onUpdate(deltaTime);

	auto rot = m_player->getTransform().getRotation();
	rot.x += getInputSystem().getMouseDelta().y * 0.01f;
	rot.y -= getInputSystem().getMouseDelta().x * 0.01f;
	m_player->getTransform().setRotation(rot);


	auto pos = m_player->getTransform().getPosition();
	auto forward = 0.0f;
	auto rightward = 0.0f;
	auto speed = 3.0f;
	if (getInputSystem().isKeyDown(dx3_d::KeyCode::W)) forward = 1.0f;
	if (getInputSystem().isKeyDown(dx3_d::KeyCode::S)) forward = -1.0f;
	if (getInputSystem().isKeyDown(dx3_d::KeyCode::D)) rightward = 1.0f;
	if (getInputSystem().isKeyDown(dx3_d::KeyCode::A)) rightward = -1.0f;
	auto direction = dx3_d::Vec3::normalize({ rightward,forward,0 });
	pos = pos + direction * speed * deltaTime;
	m_player->getTransform().setPosition(pos);
}