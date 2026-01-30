
#include "PmergeMe.hpp"


static bool isDigitsOnly(const std::string& text)
{
    if (text.empty())
    {
        return (false);
    }

    for (size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] < '0' || text[i] > '9')
        {
            return (false);
        }
    }
    return (true);
}

static bool parsePositiveInt(const std::string& text, int& outValue)
{
    char* endPtr;
    long  parsedValue;

    if (!isDigitsOnly(text))
        return (false);

    endPtr = 0;
    parsedValue = std::strtol(text.c_str(), &endPtr, 10);
    if (endPtr == 0 || *endPtr != '\0')
        return (false);
    
    if (parsedValue <= 0 || parsedValue > INT_MAX)
        return (false);

    outValue = (int)parsedValue;
    return (true);
    }

int main(int argc, char** argv)
{
    std::vector<int> inputValues;

    if (argc < 2)
    {
        std::cerr << "Error\n";
        return (1);
    }

    inputValues.reserve((size_t)(argc - 1));
    for (int argIndex = 1; argIndex < argc; ++argIndex)
    {
        int value;

        if (!parsePositiveInt(argv[argIndex], value))
        {
            std::cerr << "Error\n";
            return (1);
        }
        inputValues.push_back(value);
    }

    PmergeMe::sortAndMeasure(inputValues);
    return (0);
}
