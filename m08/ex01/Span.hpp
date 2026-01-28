
#pragma once

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <cstdlib>
#include <ctime>


class Span
{
	private :
		std::vector<int> vect;
		unsigned int maxSize;
		Span();
	public :
		Span(unsigned int N);
		Span(const Span& ref);
		Span& operator=(const Span &ref);
		~Span();

		void addNumber(int number);

		template <typename It>
		void addNumber(It begin, It end)
		{
			if (static_cast<unsigned int>(std::distance(begin, end)) + this->vect.size() > this->maxSize)
				throw std::runtime_error("Error : Not enough space in the vector ! ");
			this->vect.insert(this->vect.end(), begin, end);
		}

		int shortestSpan();
		int longestSpan();

};

