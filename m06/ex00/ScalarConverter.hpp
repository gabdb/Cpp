
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:
        static void convert(std::string str);
};

