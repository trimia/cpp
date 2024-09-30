#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc)
{
    _VecSize = argc - 1;
    _dequeSize = argc - 1;
    _Vec.reserve(argc-1);

}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &obj)
{
    if (this != &obj)
    {
        _Vec = obj._Vec;
        _VecSize = obj._VecSize;

    }
    return *this;
}

int toInt(std::string str)
{
    int number=0;
    char *p=NULL;
    number=(int)std::strtol(str.c_str(), &p, 10);
    if(*p!='\0')
        throw std::invalid_argument("toInt: invalid number");
    return number;
}

template <typename Container>
void PmergeMe::fillContainer(Container& container, char** argv, int argc)
{
    int i = 1;
    std::string token;

    while (i < argc && container.size() < (size_t)(argc - 1)) {
        token = argv[i];
        container.push_back(toInt(token));
        if(toInt(token)<0)
            throw std::invalid_argument("only positive numbers are allowed");
        i++;
    }
}

// Function to perform binary search insertion
template <typename Container>
void PmergeMe::binarySearchInsert(Container& container, typename Container::value_type value) {
    typename Container::iterator start = container.begin();
    typename Container::iterator end = container.end();
    while (start < end) {
        typename Container::iterator mid = start + std::distance(start, end) / 2;
        if (*mid < value) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    container.insert(start, value);
}

// Function to merge two halves using binary search insertion
template <typename Container>
void PmergeMe::merge(Container& container, int left, int mid, int right) {

    Container leftArr(container.begin() + left, container.begin() + mid + 1);
    Container rightArr(container.begin() + mid + 1, container.begin() + right + 1);

    for (typename Container::const_iterator it = rightArr.begin(); it != rightArr.end(); ++it) {
        binarySearchInsert(leftArr, *it);
    }

    // Copy the sorted elements back to the original container
    std::copy(leftArr.begin(), leftArr.end(), container.begin() + left);
}

// Function to implement merge sort with binary search insertion
template <typename Container>
void PmergeMe::mergeSort(Container& container, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the first half
        mergeSort(container, left, mid);

        // Recursively sort the second half
        mergeSort(container, mid + 1, right);

        // Merge the two halves using binary search insertion
        merge(container, left, mid, right);
    }
}

template <typename Container>
void PmergeMe::printContainer(const Container& container, const std::string& name) {
    std::cout << name<<": ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::printinfo(Container &container,char ** before,int size,double time,std::string type)
{
    std::cout << "Before: ";
    for(int i = 1; i < size; i++)
        std::cout<<before[i]<<" ";
    std::cout<<std::endl;
    printContainer(container,"After: ");
    std::cout << "Time: to process a range of "<<size<<" elements with "<<type<<" " << time<<" microseconds" << std::endl;
    std::cout << std::endl;
}

void PmergeMe::merge_insertion_sort_impl(int argc, char **argv)
{
    fillContainer(_Vec, argv, argc);
    clock_t startVec = clock();
    mergeSort(_Vec, 0, get_VecSize() - 1);
    clock_t endVec = clock();
    _vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;    printinfo(_Vec,argv,argc,_vecTime,"vector");

    fillContainer(_deque, argv, argc);
    clock_t startDeque = clock();
    mergeSort(_deque, 0,  get_dequeSize()- 1);
    clock_t endDeque = clock();
    _dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;    printinfo(_deque,argv,argc,_dequeTime,"deque");
}

int PmergeMe::get_VecSize() const
{
    return _VecSize;
}

int PmergeMe::get_dequeSize() const
{
    return _dequeSize;
}


