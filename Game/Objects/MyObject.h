#pragma once
#include <DX3D/All.h>


#pragma once
#include <DX3D/All.h>


class MyObject : public dx3_d::GameObject
{
	dx3d_typeid(MyObject)
public:
	explicit MyObject(const dx3_d::GameObjectDesc& desc);
	virtual ~MyObject() override;
protected:
	virtual void onCreate();
	virtual void onUpdate(dx3_d::f32 deltaTime);
};