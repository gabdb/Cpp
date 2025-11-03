
#pragma once

#include <iostream>


template <typename T>   class Array {

    private:
		int	size;
		T*	array;

    public:
		Array() : size(0), array(NULL) {}

		Array(unsigned int n) : size(n); { array = new T[n]; }

		Array(const T& other) : size(other.size), array(new T[size])
		{
			for (int = 0; i < size; i++)
			{
				array[i] = other.array[i];
			}
		}
		//PAS FINI EVIDEMMENT
		Array& operator=(const Array& other);

		~Array();

};