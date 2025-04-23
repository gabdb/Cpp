#include "utils.hpp"

void	eof_signal(void)
{
	if (std::cin.eof() == 1)
	{
		std::cout << "^D\n\nEOF signal, exiting program !" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void	print_word(std::string str)
{
	if (str.size() < 10)
	{
		for (int i = 0; i < (10 - str.size()); i++)
			std::cout << " ";
		std::cout << str;
	}
	else if (str.size() == 10)
		std::cout << str;
	else
	{
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << '.';
	}
}
