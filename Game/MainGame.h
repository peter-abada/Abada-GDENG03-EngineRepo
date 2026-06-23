#pragma once
#include <DX3D/All.h>


class MainGame : public dx3_d::Game
{
public:
	explicit MainGame(const dx3_d::GameDesc& desc);
protected:
	virtual void onCreate();
	virtual void onUpdate(dx3_d::f32 deltaTime);

private:
	dx3_d::GameObject* m_player{};
	dx3_d::f32 m_rot{}, m_scale{};
};