#ifndef SPAN_HPP
#define SPAN_HPP

#include "iostream"
#include "vector"
#include "algorithm"
#include <climits>

class Span {
public:
    Span(unsigned int n);
    Span(Span const &obj);
    ~Span();
    Span &operator=(const Span &obj);
    void addNumber(int n);
    void addNumber(int start, int end);
    int shortestSpan();
    int longestSpan();
    unsigned int size() const;
    int &operator[](unsigned int i);
private:
    unsigned int _n;
    std::vector<int> _v;


};
#endif