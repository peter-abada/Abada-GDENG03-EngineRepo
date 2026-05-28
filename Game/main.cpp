#include <DX3D/All.h>

int main()
{

	try
	{
		dx3_d::Game game({ {1280, 720},dx3_d::Logger::LogLevel::Info });
		game.run();
	}
	catch (const std::runtime_error&)
	{
		return EXIT_FAILURE;
	}
	catch (const std::invalid_argument&)
	{
		return EXIT_FAILURE;
	}
	catch (const std::exception&)
	{
		return EXIT_FAILURE;
	}
	catch (...)
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
//NOTE: This follows the newer tutorials which still use DX11



// this is just the first HO and there's already so many files :')