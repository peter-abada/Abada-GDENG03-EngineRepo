#pragma once
#include <d3dcommon.h>
#include <intsafe.h>
#include <DX3D/Core/Logger.h>

namespace dx3_d
{

	namespace GraphicsLogUtils
	{
		inline void checkShaderCompile(Logger& logger, HRESULT hr, ID3DBlob* errorBlob)
		{
			auto errorMsg = errorBlob ? static_cast<const char*>(errorBlob->GetBufferPointer()) : nullptr;
			if (FAILED(hr))
				DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, "Shader compilation failed.\nDetails:\n{}",
					errorMsg ? errorMsg : "");

			if (errorMsg)
			{
				DX3DLog(logger, Logger::LogLevel::Warning, "Shader compiled with warnings.\nDetails:\n{}", errorMsg);
			}
		}
	}

}

#define DX3DGraphicsLogThrowOnFail(hr,message,...)\
	{\
		auto res = (hr); \
		if (FAILED(res)) \
			DX3DLogThrowError(message, __VA_ARGS__);\
	} 

#define DX3DGraphicsCheckShaderCompile(hr, errorBlob) \
{\
	auto res = (hr); \
	dx3_d::GraphicsLogUtils::checkShaderCompile(getLogger(), res, errorBlob); \
}