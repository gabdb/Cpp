
#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>   class Array {

    private:
		unsigned int	_size;
		T*				array;

    public:
		Array() : _size(0), array(NULL) {}

		Array(unsigned int n) : _size(n), array(new T[n]) {}

		Array(const Array& other) : _size(other._size), array(new T[_size])
		{
			for (unsigned int i = 0; i < _size; i++)
			{
				array[i] = other.array[i];
			}
		}
		
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] array; // meme si cest NULL, delete[] NULL -> SAFE
				_size = other._size;
				array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					array[i] = other.array[i];
			}
			return (*this);
		}

		~Array()
		{
			delete[] array;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("index is out of bounds !");
			return array[index];
		}

		// 2e version const necessaire quand operator[] est utilise sur un object instance CONST
		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("index is out of bounds !");
			return array[index];
		}

		unsigned int size(void) const
		{
			return _size;
		}
};