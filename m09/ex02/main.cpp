
#include "PmergeMe.hpp"


static bool isDigitsOnly(const std::string& text)
{
    if (text.empty())
        return false;

    for (size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] < '0' || text[i] > '9')
            return false;
    }
    return true;
}

static bool parsePositiveInt(const char* text, int& outValue)
{
    if (text == 0)
        return false;

    const std::string s(text);
    if (!isDigitsOnly(s))
        return false;

    errno = 0;
    char* end = 0;
    const long value = std::strtol(text, &end, 10);
    if (errno != 0 || end == 0 || *end != '\0')
        return false;

    if (value <= 0 || value > 2147483647)
        return false;

    outValue = static_cast<int>(value);
    return true;
}

static bool alreadyExists(const std::vector<int>& v, int value)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (v[i] == value)
            return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    std::vector<int> inputValues;

    if (argc < 2)
    {
        std::cerr << "Error\n";
        return 1;
    }

    inputValues.reserve(static_cast<size_t>(argc - 1));

    for (int i = 1; i < argc; ++i)
    {
        int value = 0;

        if (!parsePositiveInt(argv[i], value))
        {
            std::cerr << "Error\n";
            return 1;
        }
        if (alreadyExists(inputValues, value))
        {
            std::cerr << "Error\n";
            return 1;
        }
        inputValues.push_back(value);
    }

    PmergeMe::sortAndMeasure(inputValues);
    return 0;
}
