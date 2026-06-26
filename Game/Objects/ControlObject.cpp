#include "ControlObject.h"

dx3_d::ControlObject::ControlObject(const dx3_d::GameObjectDesc& desc) : dx3_d::GameObject(desc)
{
}

dx3_d::ControlObject::~ControlObject()
{
}

void dx3_d::ControlObject::onCreate()
{
	createOrGetComponent<CubeComponent>();
}

void dx3_d::ControlObject::onUpdate(dx3_d::f32 deltaTime)
{
	auto& input = getInputSystem();

	auto sensitivity = 0.05f;
	auto rotation = getTransform().getRotation();
	if (input.isKeyDown(dx3_d::KeyCode::I)) rotation.x += sensitivity;
	if (input.isKeyDown(dx3_d::KeyCode::K)) rotation.x -= sensitivity;
	if (input.isKeyDown(dx3_d::KeyCode::J)) rotation.y -= sensitivity;
	if (input.isKeyDown(dx3_d::KeyCode::L)) rotation.y += sensitivity;
	if (input.isKeyDown(dx3_d::KeyCode::U)) rotation.z += sensitivity;
	if (input.isKeyDown(dx3_d::KeyCode::O)) rotation.z -= sensitivity;
	
	getTransform().setRotation(rotation);

	auto scale = getTransform().getScale();
	auto scaleSens = 0.005f;
	if (input.isKeyDown(dx3_d::KeyCode::Y)) scale -= dx3_d::Vec3{ scaleSens, scaleSens, scaleSens };
	if (input.isKeyDown(dx3_d::KeyCode::P)) scale += dx3_d::Vec3{ scaleSens, scaleSens, scaleSens };
	if (input.isKeyDown(dx3_d::KeyCode::Num1)) scale += dx3_d::Vec3{ scaleSens, 0, 0 };
	if (input.isKeyDown(dx3_d::KeyCode::Num2)) scale -= dx3_d::Vec3{ scaleSens, 0, 0 };
	if (input.isKeyDown(dx3_d::KeyCode::Num3)) scale += dx3_d::Vec3{ 0, scaleSens, 0};
	if (input.isKeyDown(dx3_d::KeyCode::Num4)) scale -= dx3_d::Vec3{ 0, scaleSens, 0 };
	if (input.isKeyDown(dx3_d::KeyCode::Num5)) scale += dx3_d::Vec3{ 0, 0, scaleSens};
	if (input.isKeyDown(dx3_d::KeyCode::Num6)) scale -= dx3_d::Vec3{ 0, 0, scaleSens };
	getTransform().setScale(scale);

	auto pos = getTransform().getPosition();
	auto forward = 0.0f;
	auto right = 0.0f;
	auto up = 0.0f;
	auto speed = 2.0f;

	if (input.isKeyDown(dx3_d::KeyCode::Up)) forward = 1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::Down)) forward = -1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::Right)) right = 1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::Left)) right = -1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::M)) up = 1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::N)) up = -1.0f;
	auto forwardDir = getTransform().forward() * forward;
	auto rightDir = getTransform().right() * right;
	auto upDir = getTransform().up() * up;
	auto direction = dx3_d::Vec3::normalize(forwardDir + rightDir + upDir);
	pos = pos + direction * speed * deltaTime;
	getTransform().setPosition(pos);
}

