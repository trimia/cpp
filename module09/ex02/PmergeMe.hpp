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
#include <chrono>
#include <valarray>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
class PmergeMe
{
private:
    std::vector<int>        _Vec;
    int                     _VecSize;
    int                     _dequeSize;
    std::deque<int>          _deque;
    std::chrono::duration<double> _vecTime;
    std::chrono::duration<double> _dequeTime;

public:
    PmergeMe(int argc);
    ~PmergeMe();
    PmergeMe &operator=(PmergeMe const &obj);
    void merge_insertion_sort_impl(std::string argv);
    void fillVec(char ** argv,int argc);
    void merge_insertion_sort();

    int get_VecSize() const;
    int get_dequeSize() const;

    template<typename Container>
    void binarySearchInsert(Container &container,typename Container::value_type value);
    template<typename Container>
    void merge(Container &container, int left, int mid, int right);
    template<typename Container>
    void mergeSort(Container &container, int left, int right);
    template<typename Container>
    void fillContainer(Container &container, char **argv, int argc);
    template<typename Container>
    void printContainer(const Container &container, const std::string &name);
    void merge_insertion_sort_impl(int argc, char **argv);
    template<typename Container>
    void printinfo(Container &container, char **before,int size, std::chrono::duration<double> time, std::string type);
};

#endif