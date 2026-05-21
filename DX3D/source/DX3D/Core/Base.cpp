#include <DX3D/Core/Base.h>
using namespace dx3_d;

dx3_d::Base::Base(const BaseDesc& desc): m_logger(desc.logger)
{
	
}

dx3_d::Base::~Base()
{
	
}

Logger& dx3_d::Base::getLogger() const noexcept
{
	return m_logger;
}