
#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <stack>

static void printSeparator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    /* =======================
       TEST WITH MutantStack
       ======================= */
    printSeparator("MutantStack");

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << "\n" <<std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it; //juste prouver que les iterateurs fonctionnent
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // verifie que MutantStack reste compatible avec std::stack
    std::stack<int> s(mstack);

    /* =======================
       SAME TEST WITH std::list
       ======================= */
    printSeparator("std::list");

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();

    std::cout << lst.size() << "\n" << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;

    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}
