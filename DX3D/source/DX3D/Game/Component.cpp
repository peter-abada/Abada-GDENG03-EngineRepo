#include <DX3D/Game/Component.h>
#include <DX3D/Game/World.h>

dx3_d::Component::Component(const ComponentDesc& desc) : Identifiable(desc.base), m_object(desc.object), m_world(desc.world)
{
}

dx3_d::GameObject& dx3_d::Component::getGameObject() noexcept
{
	return m_object;
}