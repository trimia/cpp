#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "iostream"
#include "include.h"
#include "vector"
#include "algorithm"
#include "list"

template <typename T>
bool easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        return false;
    return true;
}

#endif