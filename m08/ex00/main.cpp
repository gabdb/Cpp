
#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vect;
    for (int i = 0; i < 10; i++) {
        vect.push_back(i * i);
        std::cout << "vect[" << i << "]" << ": " << vect[i] << std::endl;
    }
    std::cout << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vect, 9);
        std::cout << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error : " << e.what() << std::endl;
    }

    std::cout << "\n" << std::endl;
    std::deque<int> deq;
    for (int i = 0; i < 10; i++)
    {
        deq.push_back(i * 5);
        std::cout << "deque[" << i << "]" << ": " << deq[i] << std::endl;
    }

    const std::deque<int> &ref_deq = deq; //version read-only de 'list'
    std::cout << std::endl;
    try {
        std::deque<int>::const_iterator it = easyfind(ref_deq, 5);
        std::cout << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error : " << e.what() << std::endl;
    }

    return 0;
}