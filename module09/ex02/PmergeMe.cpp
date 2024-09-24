#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc)
{
    _Vec.reserve(argc-1);
    _pend.reserve(argc / 2);
    _chain.reserve(_alphVecSize);
    _result.reserve(argc - 1);
    std::cout << "PmergeMe constructor " << std::endl;
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe destructor " << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &obj)
{
    if (this != &obj)
    {
        _Vec = obj._Vec;
        _chain = obj._chain;
        _pend = obj._pend;
        _result = obj._result;
    }
    return *this;
}

void PmergeMe::fillVec(char ** argv,int argc)
{
    int i = 1;
    std::string token;
    while (i<argc)
    {
        if(_Vec.size() <(size_t)get_VecSize()) {
            token = argv[i];
            _Vec.push_back(std::stoi(token));
        }
        i++;
    }
    std::cout << "_Vec" << std::endl;
    printVec(_Vec);
}

//void PmergeMe::merge(std::vector<int> A, int p, int q, int len)
//{
//    int n1 = q - p + 1;
//    int n2 = len - q;
//    std::vector<int> L;
//    std::vector<int> R;
//    for (int i = 0; i < n1; i++)
//    {
//        L.push_back(A[p + i]);
//    }
//    for (int j = 0; j < n2; j++)
//    {
//        R.push_back(A[q + j + 1]);
//    }
//    int i = 0;
//    int j = 0;
//    int k = p;
//    while (i < n1 && j < n2)
//    {
//        if (L[i] <= R[j])
//        {
//            A[k] = L[i];
//            i++;
//        }
//        else
//        {
//            A[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//    while (i < n1)
//    {
//        A[k] = L[i];
//        i++;
//        k++;
//    }
//    while (j < n2)
//    {
//        A[k] = R[j];
//        j++;
//        k++;
//    }
//    printVec(A);
//}

void PmergeMe::sort(std::vector<int>first, int firstSize)
{
    std::vector<int> vec;
    std::vector<int> pend;
    int i=0;
    int vecSize;
    if(((firstSize-1)/2)%2!=0)
        vecSize=(firstSize - 1)/2 +1;
    else vecSize=(firstSize - 1)/2;
    vec.reserve(vecSize);
    while (i<firstSize)
    {
        if(i <vecSize)
        {
            vec.push_back(first[i]);
        }else {
            pend.push_back(first[i]);
        }
        i++;
    }
    printVec(vec);
    if(vecSize==3) {
        std::cout << "vecsize =3" << std::endl;
        if (pend[0] > vec[0] && pend[0] > vec[1]) {
            _chain.push_back(pend[0]);
        } else {
            if (vec[0] > vec[1]) {
                _chain.push_back(vec[0]);
                _chain.push_back(vec[1]);
            } else {
                _chain.push_back(vec[1]);
                _chain.push_back(vec[0]);
            }
        }

    }else sort(vec,vecSize);
}



void PmergeMe::printVec(std::vector<int> vec)
{
    std::cout << "printVec" << std::endl;
    for (auto &i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int PmergeMe::get_VecSize() const
{
    return _alphVecSize;
}

std::vector<int> PmergeMe::get_Vec() const
{
    return _Vec;
}

void PmergeMe::set_Vec(const std::vector<int> &alphVec)
{
    _Vec = alphVec;
}

std::vector<int> PmergeMe::get_chain() const
{
    return _chain;
}

void PmergeMe::set_chain(const std::vector<int> &chain)
{
    _chain = chain;
}

std::vector<int> PmergeMe::get_pend() const
{
    return _pend;
}

void PmergeMe::set_pend(const std::vector<int> &pend)
{
    _pend = pend;
}

std::vector<int> PmergeMe::get_result() const
{
    return _result;
}

void PmergeMe::set_result(const std::vector<int> &result)
{
    _result = result;
}


//void PmergeMe::merge_insertion_sort_impl(std::string argv)
//{
//    std::vector<int> vec;
//    fillVec(argv,argc);
//    merge_insertion_sort();
//    printVec(_result);
//}

