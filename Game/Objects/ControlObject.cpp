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
	if (input.isKeyDown(dx3_d::KeyCode::Up)) rotation.x += sensitivity;
	if (input.isKeyDown(dx3_d::KeyCode::Down)) rotation.x -= sensitivity;
	if (input.isKeyDown(dx3_d::KeyCode::Left)) rotation.y -= sensitivity;
	if (input.isKeyDown(dx3_d::KeyCode::Right)) rotation.y += sensitivity;
	getTransform().setRotation(rotation);

	auto scale = getTransform().getScale();
	auto scaleSens = 0.005f;
	if (input.isKeyDown(dx3_d::KeyCode::O)) scale -= dx3_d::Vec3{ scaleSens, scaleSens, scaleSens };
	if (input.isKeyDown(dx3_d::KeyCode::P)) scale += dx3_d::Vec3{ scaleSens, scaleSens, scaleSens };
	getTransform().setScale(scale);

	auto pos = getTransform().getPosition();
	auto forward = 0.0f;
	auto right = 0.0f;
	auto speed = 2.0f;

	if (input.isKeyDown(dx3_d::KeyCode::I)) forward = 1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::K)) forward = -1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::L)) right = 1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::J)) right = -1.0f;
	auto forwardDir = getTransform().forward() * forward;
	auto rightDir = getTransform().right() * right;
	auto direction = dx3_d::Vec3::normalize(forwardDir + rightDir);
	pos = pos + direction * speed * deltaTime;
	getTransform().setPosition(pos);
}

