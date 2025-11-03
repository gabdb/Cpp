
#include "iter.hpp"


// Read-only function
template <typename T>   void printElement(const T &x)
{
    std::cout << x << std::endl;
}

// Modifying function
template <typename T>   void increment(T& x)
{
    x++;
}

int main()
{
    // --- Test 1: integers ---
    int numbers[] = {1, 2, 3, 4, 5};
    size_t len = 5;
    std::cout << "Original int array:" << std::endl;
    iter(numbers, len, printElement<int>);
    std::cout << std::endl;

    // modifier array (pas const)
    iter(numbers, len, increment<int>);
    std::cout << "After increment:" << std::endl;
    iter(numbers, len, printElement<int>);
    std::cout << std::endl << std::endl;



    // --- Test 2: strings ---
    std::string words[] = {"hi", "there", "friend"};
    len = 3;
    std::cout << "String array:" << std::endl;
    iter(words, len, printElement<std::string>);
    std::cout << std::endl << std::endl;



    // --- Test 3: const array (read-only) ---
    const float values[] = {1.1, 2.2, 3.3};
    len = 3;
    std::cout << "Const float array:" << std::endl;
    iter(values, len, printElement<float>);
    std::cout << std::endl;

    //iter(values, len, increment<float>); // erreur, values est const, increment peut pas prendre const param

    return 0;
}
