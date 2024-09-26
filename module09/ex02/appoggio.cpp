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
void insertion_sort(std::vector<int> array, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        int tmp = array[i];
        int j = i;
        while ((j > l) && (array[j - 1] > tmp))
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = tmp;
    }
}

void merge(std::vector<int> arr, std::vector<int> temp, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while ((i <= m) && (j <= r))
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    for (; j <= r; j++, k++)
        temp[k] = arr[j];

    for (; i <= m; i++, k++)
        temp[k] = arr[i];

    for (i = l; i <= r; i++)
        arr[i] = temp[i];
}

void mergesort(std::vector<int> arr, std::vector<int> temp, int l, int r, int threshold)
{
    if (l < r)
    {
        if ((r - l) <= threshold)
            insertion_sort(arr, l, r);
        else
        {
            int m = (l + r) / 2;
            mergesort(arr, temp, l, m, threshold);
            mergesort(arr, temp, m + 1, r, threshold);
            merge(arr, temp, l, m, r);
        }
    }
}
int main()
{
    std::vector<int> array(100);

    for(int i = 0;i<100;i++)
        array[i] = rand() % 100 +1;
    for(int i = 0;i<100;i++)
        std::cout <<YELLOW<< array[i] <<NONE<< " ";
    std::vector<int> temp;
    temp.reserve(100);
    std::cout << std::endl;
    mergesort(array,temp, 0, 99,10);
    for(int i = 0;i<100;i++)
        std::cout <<CYAN<< temp[i] <<NONE<< " ";

    return 0;
}
#endif