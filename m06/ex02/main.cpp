
#include "Base.hpp"

int main()
{
    Base* base = generate();

    std::cout << "Identify using pointers: ";
    identify(base);

    std::cout << "Identify using reference: ";
    identify(*base);

    delete base;
    return 0;
}
