#include "MainGame.h"
#include "Objects/MyObject.h"


MainGame::MainGame(const dx3_d::GameDesc& desc) : dx3_d::Game(desc)
{
}

void MainGame::onCreate()
{
	Game::onCreate();
	auto& world = getWorld();

	for (auto x = 0; x < 3;x++)
	{
		for (auto y = 0; y < 3; y++)
		{
			auto object = world.createGameObject<dx3_d::GameObject>();
			object->createOrGetComponent<dx3_d::CubeComponent>();
			object->getTransform().setPosition({ (dx3_d::f32)-1 + x,(dx3_d::f32)-1 + y, 0 });
			m_objects[y * 3 + x] = object;
		}
	}

}

void MainGame::onUpdate(dx3_d::f32 deltaTime)
{
	Game::onUpdate(deltaTime);

	m_rot += deltaTime * 0.707f;
	m_scale = std::abs(std::sin(m_rot));

	for (auto i = 0; i < 9; i++)
	{
		m_objects[i]->getTransform().setRotation({ m_rot * i, m_rot, m_rot * i });
		m_objects[i]->getTransform().setScale({ m_scale,m_scale,m_scale });
	}
}