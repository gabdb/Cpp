
#include "ScalarConverter.hpp"

bool    is_single_char(std::string& str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
        return true;
    else
        return false;
}

void	print_char(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast <double>(c) << ".0" << std::endl;
}

void    ScalarConverter::convert(std::string str)
{
	if (is_single_char(str))
		print_char(str[0]);
}

int main(int ac, char **av)
{
	ScalarConverter::convert(av[1]);

	return (0);
}