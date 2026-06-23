#pragma once

namespace dx3_d
{
	class Command
	{
	public:
		virtual ~Command();
		virtual void execute() = 0;
	};
}