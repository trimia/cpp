#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include "include.h"
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <list>
#include <iterator>
#include <type_traits>
#include <vector>
class PmergeMe
{
private:
    std::vector<int> _Vec;
    std::vector<int> _chain;
    std::vector<int> _pend;
    std::vector<int> _result;
    int _alphVecSize;


public:
    PmergeMe(int argc);
    ~PmergeMe();
    PmergeMe &operator=(PmergeMe const &obj);
    void merge_insertion_sort_impl(std::string argv);
    void printVec(std::vector<int> vec);
    void fillVec(char ** argv,int argc);
    void merge_insertion_sort();
    void sort(std::vector<int> A, int p, int len);
    void merge(std::vector<int> A, int p, int q, int len);


    int get_VecSize() const;
    std::vector<int> get_Vec() const;
    void set_Vec(const std::vector<int> &alphVec);
    std::vector<int> get_chain() const;
    void set_chain(const std::vector<int> &chain);
    std::vector<int> get_pend() const;
    void set_pend(const std::vector<int> &pend);
    std::vector<int> get_result() const;
    void set_result(const std::vector<int> &result);


    void sort(std::vector<int> first, int firstSize);
};

#endif