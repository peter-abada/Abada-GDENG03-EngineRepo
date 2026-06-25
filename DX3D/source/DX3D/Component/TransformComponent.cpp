#include <DX3D/Component/TransformComponent.h>
#include <DX3D/Game/World.h>


dx3_d::TransformComponent::TransformComponent(const ComponentDesc& data) : Component(data)
{
	markAsDirty();
}

void dx3_d::TransformComponent::setPosition(const Vec3& position)
{
	m_position = position;
	markAsDirty();
}

dx3_d::Vec3 dx3_d::TransformComponent::getPosition() const noexcept
{
	return m_position;
}

void dx3_d::TransformComponent::setRotation(const Vec3& rotation)
{
	m_rotation = rotation;
	markAsDirty();
}

dx3_d::Vec3 dx3_d::TransformComponent::getRotation() const noexcept
{
	return m_rotation;
}

void dx3_d::TransformComponent::setScale(const Vec3& scale)
{
	m_scale = scale;
	markAsDirty();
}

dx3_d::Vec3 dx3_d::TransformComponent::getScale() const noexcept
{
	return m_scale;
}


dx3_d::Vec3 dx3_d::TransformComponent::forward()
{
	auto forward = getRigidWorldMatrix().row(2);
	return dx3_d::Vec3::normalize({ forward.x,forward.y,forward.z });
}

dx3_d::Vec3 dx3_d::TransformComponent::right()
{
	auto right = getRigidWorldMatrix().row(0);
	return dx3_d::Vec3::normalize({ right.x,right.y,right.z });
}

dx3_d::Vec3 dx3_d::TransformComponent::up()
{
	auto up = getRigidWorldMatrix().row(1);
	return dx3_d::Vec3::normalize({ up.x,up.y,up.z });
}

dx3_d::Mat4x4 dx3_d::TransformComponent::getAffineWorldMatrix() noexcept
{
	updateWorldMatrix();
	return m_affineWorldMatrix;
}

dx3_d::Mat4x4 dx3_d::TransformComponent::getRigidWorldMatrix() noexcept
{
	updateWorldMatrix();
	return m_rigidWorldMatrix;;
}



void dx3_d::TransformComponent::updateWorldMatrix() noexcept
{
	if (!m_dirty) return;

	m_dirty = false;

	m_rigidWorldMatrix =
		Mat4x4::rotateX(m_rotation.x) *
		Mat4x4::rotateY(m_rotation.y) *
		Mat4x4::rotateZ(m_rotation.z) *
		Mat4x4::translate(m_position);

	m_affineWorldMatrix =
		Mat4x4::scale(m_scale) *
		m_rigidWorldMatrix;
}


void dx3_d::TransformComponent::markAsDirty()
{
	if (m_dirty) return;
	m_dirty = true;
	m_world.addDirtyTransformInternal(*this);
}