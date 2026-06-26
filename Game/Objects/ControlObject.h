#pragma once
#include <DX3D/All.h>

namespace dx3_d
{
	class ControlObject : public dx3_d::GameObject
	{
		dx3d_typeid(ControlObject)

	public:
		explicit ControlObject(const dx3_d::GameObjectDesc& desc);
		virtual ~ControlObject() override;

	protected:
		virtual void onCreate() override;
		virtual void onUpdate(dx3_d::f32 deltaTime) override;
	};
}

