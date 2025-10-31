
#include "ScalarConverter.hpp"

void	print_bad_input(void)
{
	std::cout << "char: " << "Impossible input" << std::endl;
	std::cout << "int: " << "Impossible input" << std::endl;
	std::cout << "float: " << "Impossible input" << std::endl;
	std::cout << "double: " << "Impossible input" << std::endl;
}

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

bool	is_int(std::string& str)
{
	char	*end; //var necessaire pr strtol (string to long)
	long	value;

	value = std::strtol(str.c_str(), &end, 10);
	if (*end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		return true;
	else
		return false;
}

void	print_int(std::string& str)
{
	int	x = static_cast<int>(atoi(str.c_str()));

	if (!std::isprint(static_cast<char>(x)))
		std::cout << "char non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(x) << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
	std::cout << "double: " << static_cast <double>(x) << ".0" << std::endl;
}

bool	is_float(std::string& str)
{
	if (str.find("f") == (str.find(".") + 2))
		return true;
	else
		return false;
}

void	print_float(std::string& str)
{
	char  *end;
	float value = std::strtof(str.c_str(), &end);

	if (*end != 'f' || *(end + 1) != '\0')
	{
		print_bad_input();
		return ;
	}

	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;

	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
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