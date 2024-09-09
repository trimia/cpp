#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {
    _v.reserve(n);
}

Span::Span(Span const &obj) {
    *this = obj;
}

Span::~Span() {
}

Span &Span::operator=(const Span &obj) {
    _n = obj._n;
    _v = obj._v;
    return *this;
}

void Span::addNumber(int n) {
    if (_v.size() >= _n)
        throw std::out_of_range("Array is full");
    _v.push_back(n);
}

void Span::addNumber(int start, int end) {
    if (end < start)
        throw std::invalid_argument("End is smaller than start");
    if (_v.size() + end - start > _n)
        throw std::out_of_range("Array is full");
    for (int i = start; i <= end; ++i)
        _v.push_back(i);
}

int Span::shortestSpan() {
    if (_v.size() <= 1)
        throw std::out_of_range("Array is too small");
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    int min = INT_MAX;
    for (unsigned int i = 1; i < v.size(); ++i) {
        if (v[i] - v[i - 1] < min)
            min = v[i] - v[i - 1];
    }
    return min;
}

int Span::longestSpan() {
    if (_v.size() <= 1)
        throw std::out_of_range("Array is too small");
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    return v[v.size() - 1] - v[0];
}

unsigned int Span::size() const {
    return _n;
}

int &Span::operator[](unsigned int i) {
    if (i >= _n)
        throw std::out_of_range("Index out of range");
    return _v[i];
}


