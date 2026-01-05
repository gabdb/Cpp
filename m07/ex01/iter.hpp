
#pragma once

#include <iostream>

template <typename T>   void iter(T* array, const unsigned int len, void (*fptr)(T& element))
{
    if (!array || !fptr)
        return;
    for (unsigned int i = 0; i < len; i++)
    {
        fptr(array[i]);
    }
}

// le compiler choisit quelle version il prend en fonction de si array est const ou pas
template <typename T>   void iter(const T* array, const unsigned int len, void (*fptr)(const T& element))
{
    if (!array || !fptr)
        return;
    for (unsigned int i = 0; i < len; i++)
    {
        fptr(array[i]);
    }
}