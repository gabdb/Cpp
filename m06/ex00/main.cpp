
#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
    if (ac != 2 ) {
        std::cout << "Please enter one argument" << std::endl;
        return 1;
    }
    ScalarConverter::convert(static_cast<std::string>(av[1]));

    return 0;
}
