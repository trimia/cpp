#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc)
{
    _VecSize = argc - 1;
    _dequeSize = argc - 1;
    _Vec.reserve(argc-1);

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
        i++;
    }
}

// Function to perform binary search insertion
template <typename Container>
void PmergeMe::binarySearchInsert(Container& container, typename Container::value_type value) {
    auto start = container.begin();
    auto end = container.end();
    while (start < end) {
        auto mid = start + std::distance(start, end) / 2;
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

    for (const auto& value : rightArr) {
        binarySearchInsert(leftArr, value);
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
    for (const auto& element : container) {
        std::cout <<element << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::printinfo(Container &container,char ** before,int size,std::chrono::duration<double> time,std::string type)
{
    std::cout << "Before: ";
    for(int i = 1; i < size; i++)
        std::cout<<before[i]<<" ";
    std::cout<<std::endl;
    printContainer(container,"After: ");
    std::cout << "Time: to process a range of "<<size<<" elements with "<<type<<" " << time.count()*1000000 << " micro seconds" << std::endl;
    std::cout << std::endl;
}

void PmergeMe::merge_insertion_sort_impl(int argc, char **argv)
{
    fillContainer(_Vec, argv, argc);
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(_Vec, 0, get_VecSize() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    _vecTime = end - start;
    printinfo(_Vec,argv,argc,_vecTime,"vector");

    fillContainer(_deque, argv, argc);
    start = std::chrono::high_resolution_clock::now();
    mergeSort(_deque, 0,  get_dequeSize()- 1);
    end = std::chrono::high_resolution_clock::now();
    _dequeTime = end - start;
    printinfo(_deque,argv,argc,_dequeTime,"forward list");
}

int PmergeMe::get_VecSize() const
{
    return _VecSize;
}

int PmergeMe::get_dequeSize() const
{
    return _dequeSize;
}


