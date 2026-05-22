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
				DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, errorMsg ? errorMsg : "Shader compilation failed. (Unknown error)");

			if (errorMsg)
			{
				DX3DLog(logger, Logger::LogLevel::Warning, errorMsg);
			}
		}
	}

}

#define DX3DGraphicsLogThrowOnFail(hr, message) \
	{\
		auto res = (hr); \
		if (FAILED(res)) \
			DX3DLogThrowError(message); \
	} 

#define DX3DGraphicsCheckShaderCompile(hr, errorBlob) \
{\
	auto res = (hr); \
	dx3_d::GraphicsLogUtils::checkShaderCompile(getLogger(), res, errorBlob); \
}