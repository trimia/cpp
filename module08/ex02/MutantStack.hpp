#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <iomanip>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(MutantStack const &obj) : std::stack<T>(obj) {}
    ~MutantStack() {}
    MutantStack &operator=(const MutantStack &obj)
    {
        std::stack<T>::operator=(obj);
        return *this;
    }

    typedef typename std::deque<T>::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

};


#endif