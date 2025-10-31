
#include "Base.hpp"

Base::~Base() {}

Base* generate(void)
{
    std::srand(std::time(NULL));
    int r = std::rand() % 3;

    if (r == 0)
        return (new A);
    else if (r == 1)
        return (new B);
    return (new C);
}

void    identify(Base* p)
{
    // fonctionne pcq dynamic_cast renvoi NULL qd ca foire

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Problem: unknown ptr type" << std::endl;
}

void    identify(Base& p)
{
    // avec des refs& -> dynamic_cast throw un bad_cast quand ca foire

    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch(...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch(...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch(...) {}
}