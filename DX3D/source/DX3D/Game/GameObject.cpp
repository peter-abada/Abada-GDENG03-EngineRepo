#include <DX3D/Game/GameObject.h>


dx3_d::GameObject::GameObject(const GameObjectDesc& desc) : Identifiable(desc.base), m_world(desc.world)
{
}

size_t dx3_d::GameObject::getWorldIndex() const noexcept
{
	return m_worldIndex;
}

void dx3_d::GameObject::setWorldIndex(size_t index) noexcept
{
	m_worldIndex = index;
}