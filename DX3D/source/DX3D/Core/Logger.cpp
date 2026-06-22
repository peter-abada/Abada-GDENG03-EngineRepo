#include <iostream>
#include <DX3D/Core/Logger.h>

dx3_d::Logger::Logger(LogLevel logLevel) : m_logLevel(logLevel)
{
	//std::clog << "Peter Abada | GDENG03 Window Test" << "\n";
	//std::clog << "<------------------------------->" << "\n";
}

dx3_d::Logger::~Logger()
{
	
}

void dx3_d::Logger::_log(LogLevel level, const char* message)
{
	auto logLevelToString = [](LogLevel logLevel)
		{
			switch (logLevel)
			{
			case LogLevel::Info:
				return "INFO";
			case LogLevel::Warning:
				return "WARNING";
			case LogLevel::Error:
				return "ERROR";
			default:
				return "UNKNOWN";
			}
		};

	if (level > m_logLevel) return;
	std::clog << "[DX3D] "  << logLevelToString(level) << "]: " << message << "\n";
}
