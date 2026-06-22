#pragma once
#include "DX3D/Window/Window.h"

namespace dx3_d
{
	class Display final : public Window
	{
	public:
		explicit Display(const DisplayDesc& desc);

		SwapChain& getSwapChain() noexcept;

	private:
		RefPtr<SwapChain> m_swapChain{};
	};
}

