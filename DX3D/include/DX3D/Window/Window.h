#pragma once
#include <DX3D/Core/Base.h>

namespace dx3_d
{
	class Window : public Base
	{
	public:
		Window();
		virtual ~Window() override;

	private:
		void* m_handle{};
	};
}
