#pragma once
#include "DX3D/Core/Common.h"

namespace dx3_d
{
	namespace GraphicsUtils
	{
		inline const char* getShaderModelTarget(ShaderType type)
		{
			switch (type)
			{
			case ShaderType::VertexShader: return "vs_5_0";
			case ShaderType::PixelShader: return "ps_5_0";
			default: return "";
			}
		}
	}
}
