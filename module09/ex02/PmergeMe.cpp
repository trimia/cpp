#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc)
{
    _VecSize = argc - 1;
    _Vec.reserve(argc-1);
    _result.reserve(argc - 1);
    if(((_VecSize)/2)%2!=0)
        _chainFinalSize=(_VecSize)/2 +1;
    else _chainFinalSize=(_VecSize)/2;

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
    int vecSize;
    std::string token;
    while (i<argc)
    {
        if(_Vec.size() <(size_t)get_VecSize()) {
            token = argv[i];
            _Vec.push_back(std::stoi(token));
        }
        i++;
    }
    if(((_VecSize)/2)%2!=0)
        vecSize=(_VecSize)/2 +1;
    else vecSize=(_VecSize)/2;
    _firstChain.reserve(vecSize);
    for(int i = 0; i<_VecSize; i++)
    {
        if(i <vecSize)
        {
            _firstChain.push_back(_Vec[i]);
        }else {
            _pend.push_back(_Vec[i]);
        }
    }
//    std::cout << "vec giro: "<<i <<" vec size "<<get_VecSize() << std::endl;
//    printVec(_Vec,"Vec");
//    printVec(_chain,"chain");
//    printVec(_pend,"pend");
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
    vec.clear();
    pend.clear();
    int i=0;
    int vecSize;

    std::cout << "firstSize: "<<firstSize << std::endl;
    if(((firstSize)/2)%2!=0)
        vecSize=(firstSize)/2 +1;
    else vecSize=(firstSize)/2;
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
    printVec(vec,"vec");
    printVec(pend,"pend");
    std::cout << "chain size "<<_chain.size() <<" _chain final  size "<<_chainFinalSize << std::endl;
    if(_chain.size()==(size_t)_chainFinalSize)
    {
        std::cout <<GREEN<< "chain size == chainFinalSize"<<_chainFinalSize << NONE<<std::endl;
        return;
    }
    if (vecSize == 4)
    {

        int temp1,temp2;
        if(vec[0]>vec[1])
            temp1=vec[0];
        else temp1=vec[1];
        if(vec[2]>vec[3])
            temp2=vec[2];
        else temp2=vec[3];
        if(temp1>temp2){
            _chain.push_back(temp1);
            _chain.push_back(temp2);
        }
        else{
            _chain.push_back(temp2);
            _chain.push_back(temp1);
        }
        printVec(_firstChain,"firstChain");
        _firstChain.clear();
        _firstChain.reserve(vecSize-2);
        printVec(_firstChain,"firstChain");
        printVec(vec,"vec");
//        for(int i =0; (size_t)i<_chain.size(); i++)
//        {
            int n=0;
            int flag=0;
            while (n<vecSize) {
                for (int i = 0; (size_t) i < _chain.size(); i++) {
                    if (vec[n] == _chain[i])
                        flag=1;
                }
                if(flag==0)
                {
                    std::cout << "vec[n] " << vec[n] << " _chain[i] " << _chain[i] << std::endl;
                    _firstChain.push_back(vec[n]);
                }
                n++;

//                if (vec[n] != _chain[i])
//                {
//                    std::cout << "vec[n] "<<vec[n] << " _chain[i] "<<_chain[i] << std::endl;
//                    _firstChain.push_back(vec[n]);
//                }
//                n++;
//            }
        }
        printVec(_chain,"chain");
        printVec(_firstChain,"firstChain");
        sort(_firstChain,_firstChain.size());


//        return;
    }
    sort(vec,vecSize);
//    else
//    {
//        std::cout<<YELLOW << "vecsize  = "<<vecSize << NONE<<std::endl;
//        _firstChain.clear();
//        _firstChain.reserve(vecSize-2);
//        for (int i =0; i < vecSize-2; i++)
//        {
//            for(int n =0; (size_t)n<_chain.size(); n++) {
//                if (vec[i] != _chain[n])
//                    _firstChain.push_back(vec[i]);
//            }
//        }

//        sort(_firstChain,_firstChain.size());
//    }

////    printVec(first);
//    if(vecSize==2) {
//        std::cout << "vecsize =3" << std::endl;
//        std::cout << "vec[0] " << vec[0] << " vec[1] " << vec[1] << std::endl;
//        std::cout << "pend[0] " << pend[0] << std::endl;
//        if (pend[0] > vec[0] && pend[0] > vec[1]) {
//            _chain.push_back(pend[0]);
//        } else {
//            if (vec[0] > vec[1]) {
//                _chain.push_back(vec[0]);
//                if(pend[0]>vec[1])
//                    _chain.push_back(pend[0]);
//                else
//                    _chain.push_back(vec[1]);
//            } else {
//                _chain.push_back(vec[1]);
//                if(pend[0]>vec[0])
//                    _chain.push_back(pend[0]);
//                else{
//                    _chain.push_back(vec[0]);
//                    _chain.push_back(pend[0]);
//                }
//            }
//        }
//        return;
//    }else sort(vec,vecSize);
}



void PmergeMe::printVec(std::vector<int> vec, std::string name)
{
    std::cout<<MAGENTA << "printVec :"  <<name<< std::endl;
    for (auto &i : vec)
    {
        std::cout << i << " ";
    }
    std::cout<<NONE << std::endl;
}

int PmergeMe::get_VecSize() const
{
    return _VecSize;
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

