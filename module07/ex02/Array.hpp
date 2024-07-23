#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(Array const &obj);
    ~Array();
    Array &operator=(const Array &obj);
    unsigned int size() const;
    T &operator[](unsigned int i);

private:
    T *array;
    unsigned int n; // This was missing in the class definition but used in the implementation.
};

#include "Array.tpp"

#endif // _ARRAY_HPP_