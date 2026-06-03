#pragma once

#include <dwrite.h>
#include <d2d1.h>

namespace dx3_d
{
	class TextWriter
	{
	public:
		TextWriter();

		void createDeviceIndependentResources(); //Creates devices not tied to a device; Initiates the factory and text format
		void createDeviceResources(); //Initiates render target and brush for rendering text
		void drawText(); //Defines the area to draw text

	private:
		IDWriteFactory* m_dwriteFactory{}; //Factory
		IDWriteTextFormat* m_textFormat{}; //Text format properties

		const char* m_text{}; //String to render
		UINT m_textLength{}; //String length

		ID2D1Factory* m_D2DFactory_; //D2D factory
		ID2D1HwndRenderTarget* m_pRT_; //Drawing instructions 
		ID2D1SolidColorBrush* m_pBlackBrush_; //Paints with a solid color
	};
}

