#include <DX3D/Core/Base.h>

dx3_d::Base::Base(const BaseDesc& desc): m_logger(desc.logger)
{
	
}

dx3_d::Base::~Base()
{
	
}

dx3_d::Logger& dx3_d::Base::getLogger() noexcept
{
	return m_logger;
}

