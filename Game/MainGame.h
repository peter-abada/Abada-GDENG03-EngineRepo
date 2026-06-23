#pragma once
#include <DX3D/All.h>
#include <vector>

class MainGame : public dx3_d::Game
{
public:
	explicit MainGame(const dx3_d::GameDesc& desc);
protected:
	virtual void onCreate();
	virtual void onUpdate(dx3_d::f32 deltaTime);

private:
	void createObject();

private:
	dx3_d::GameObject* m_player{};
	std::vector<dx3_d::GameObject*> m_objects{};
	dx3_d::f32 m_rot{}, m_scale{};
};