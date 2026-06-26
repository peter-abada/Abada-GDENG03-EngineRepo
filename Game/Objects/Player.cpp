#include "Player.h"

Player::Player(const dx3_d::GameObjectDesc& desc) : dx3_d::GameObject(desc)
{
}

Player::~Player()
{
}

void Player::onCreate()
{
	createOrGetComponent<dx3_d::CameraComponent>();
}

void Player::onUpdate(dx3_d::f32 deltaTime)
{
	auto& input = getInputSystem();


	auto sensitivity = 0.001f;
	auto rot = getTransform().getRotation();
	rot.x += getInputSystem().getMouseDelta().y * sensitivity;
	rot.y += getInputSystem().getMouseDelta().x * sensitivity;
	if (rot.x > 1.57f) rot.x = 1.57f;
	else if (rot.x < -1.57f) rot.x = -1.57f;
	getTransform().setRotation(rot);


	auto pos = getTransform().getPosition();
	auto forward = 0.0f;
	auto right = 0.0f;
	auto up = 0.0f;
	auto speed = 3.0f;
	if (input.isKeyDown(dx3_d::KeyCode::W)) forward = 1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::S)) forward = -1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::D)) right = 1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::A)) right = -1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::E)) up = 1.0f;
	if (input.isKeyDown(dx3_d::KeyCode::Q)) up = -1.0f;
	auto forwardDir = getTransform().forward() * forward;
	auto rightDir = getTransform().right() * right;
	auto upDir = getTransform().up() * up;
	auto direction = dx3_d::Vec3::normalize(forwardDir + rightDir + upDir);
	pos = pos + direction * speed * deltaTime;
	getTransform().setPosition(pos);
}