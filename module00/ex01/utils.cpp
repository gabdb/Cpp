#include "utils.hpp"

void	eof_signal(void)
{
	if (std::cin.eof() == 1)
	{
		std::cout << "^D\n\nEOF signal, exiting program !" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
