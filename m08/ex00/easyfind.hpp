
#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>


template <typename T> //T sera un type de container
typename T::iterator	easyfind(T& container, int nb)
{
	std::cout << "(Using regular easyfind): ";
	typename T::iterator result = std::find(container.begin(), container.end(), nb);

    if (result == container.end())
        throw std::runtime_error("Value not found !");
    return result;
}


//const overload pr gerer les inputs const
template <typename T>
typename T::const_iterator	easyfind(const T& container, int nb)
{
	std::cout << "(Using 'const' version of easyfind): ";
	typename T::const_iterator result = std::find(container.begin(), container.end(), nb);

	if (result == container.end())
		throw std::runtime_error("Value not found !");
	return result;
}
