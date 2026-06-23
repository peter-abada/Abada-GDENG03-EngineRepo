#include <DX3D/Game/GameObject.h>
#include<DX3D/Game/Component.h>
#include<DX3D/Component/TransformComponent.h>
#include<DX3D/Game/World.h>


dx3_d::GameObject::GameObject(const GameObjectDesc& desc) : Identifiable(desc.base), m_world(desc.world)
{
	m_transform = createOrGetComponent<TransformComponent>();
}

dx3_d::TransformComponent& dx3_d::GameObject::getTransform() noexcept
{
	return *m_transform;
}

dx3_d::Component* dx3_d::GameObject::createComponentInternal(UniquePtr<Component>& component)
{
	if (!component) return {};
	auto typeId = component->getTypeId();
	auto ptr = component.get();
	if (m_components.find(typeId) != m_components.end()) return {};
	m_components.emplace(typeId, std::move(component));
	m_world.addComponentInternal(*ptr);
	return ptr;

}

dx3_d::Component* dx3_d::GameObject::getComponentInternal(size_t id)
{
	auto it = m_components.find(id);
	if (it == m_components.end()) return {};
	return it->second.get();
}