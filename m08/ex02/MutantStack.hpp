
#pragma once

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public :
		//raccourci: iterator est un alias pr ...
		typedef typename std::stack<T>::container_type::iterator iterator; //container_type == deque par defaut
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}

		iterator begin()
		{
			return this->c.begin(); //c est protected member de std::stack, cest le container interne (wrapped)
		}

		iterator end()
		{
			return this->c.end();
		}

		const_iterator begin() const
		{
			return this->c.begin();
		}

		const_iterator end() const
		{
			return this->c.end();
		}
};

//mutantstack se comporte comme une stack ET comme un container avec des iterators