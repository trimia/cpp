#include "PmergeMe.hpp"
#include "include.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout<<RED << "Usage: ./PmergeMe sequence of int "<<NONE << std::endl;
        return 1;
    }

    std::cout<<argc%2<<std::endl;
    PmergeMe pmergeMe(argc);
    pmergeMe.fillVec(argv,argc);
    std::cout<<pmergeMe.get_VecSize()<<std::endl;
    pmergeMe.mergeInsertion(0,pmergeMe.get_VecSize());
    pmergeMe.printVec(pmergeMe.get_Vec(),"Vec");
    pmergeMe.printVec(pmergeMe.get_result(),"Result");
//
//    PmergeMe pmergeMe(argc);
//    pmergeMe.fillVec(argv,argc);
//    pmergeMe.sort(pmergeMe.get_Vec(),pmergeMe.get_VecSize());
//    pmergeMe.printVec(pmergeMe.get_chain(),"chain");
//    for (int i =0; i<argc; i++)
//    {
//        std::cout<<argv[i]<<std::endl;
//
//    }

    return 0;
}

//std::vector<int> getMajorElements(const std::vector<int>& vec) {
//    if (vec.size() < 2) {
//        return vec;
//    }
//
//    std::vector<int> majorElements;
//    int halfSize = vec.size() / 2;
//
//    for (int i = 0; i < halfSize; ++i) {
//        majorElements.push_back(std::max(vec[2 * i], vec[2 * i + 1]));
//    }
//
//    if (vec.size() % 2 != 0) {
//        majorElements.push_back(vec.back());
//    }
//
//    std::vector<int> result = getMajorElements(majorElements);
//    std::sort(result.begin(), result.end());
//    return result;
//}
//
//int main() {
//    std::vector<int> vec = {3, 5, 9, 7, 4, 8, 6, 2};
//    std::vector<int> result = getMajorElements(vec);
//
//    std::cout << "Major elements in ascending order: ";
//    for (int num : result) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}