#pragma once
#include <DX3D/Input/Command.h>

namespace dx3_d
{
	class SpawnCommand : public dx3_d::Command
	{
	public:
		virtual void execute() override;
	};
}