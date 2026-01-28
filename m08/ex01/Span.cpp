
#include "Span.hpp"

Span::Span(const unsigned int N) : maxSize(N) {}

Span::Span(const Span& other) : vect(other.vect), maxSize(other.maxSize) {}

Span&	Span::operator=(const Span& ref)
{
	if (this != &ref)
	{
		this->vect = ref.vect;
		this->maxSize = ref.maxSize;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(const int number)
{
	if (this->vect.size() >= this->maxSize)
		throw std::runtime_error("Error : maxSize has been reached ! ");
	this->vect.push_back(number);
}

// void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
// {   
// 	if (std::distance(begin, end) + this->vect.size() > this->maxSize)
// 		throw std::runtime_error("Error : Not enough space in the vector ! ");
// 	this->vect.insert(this->vect.end(), begin, end);
// }

int	Span::shortestSpan()
{
	if (this->vect.size() < 2)
		throw std::runtime_error("Error : container size too small");

	std::vector<int> tmp = this->vect;
	std::sort(tmp.begin(), tmp.end());

	int distance = std::numeric_limits<int>::max();
	for (size_t i = 1; i < tmp.size(); i++)
	{
		int currentDist = tmp[i] - tmp[i - 1];
		if (currentDist < distance)
			distance = currentDist;
	}
	return distance;
}

int	Span::longestSpan()
{
	if (this->vect.size() < 2)
		throw std::runtime_error("Error : container size too small");

	int max = *std::max_element(vect.begin(), vect.end());
	int min = *std::min_element(vect.begin(), vect.end());

	return (max - min);
}

// void Span::printVect()
// {
// 	std::vector<int>::iterator it = vect.begin();
// 	for (int i = 0; it != vect.end(); ++it, ++i)
// 	{
// 		std::cout << "Index " << i << ": " << *it << std::endl;
// 	}
// }