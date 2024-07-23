template<typename T>
Array<T>::Array() : array(NULL), n(0) {
    std::cout << "Array : Default Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), n(n) {
    std::cout << "Array : Parameter Constructor Called" << std::endl;
}
template<typename T>
Array<T>::~Array() {
    std::cout << "Array : Destructor Called" << std::endl;
    delete[] this->array;
}

template<typename T>
Array<T>::Array(const Array &obj) : array(NULL), n(obj.n) {
    std::cout << "Copy Constructor Called" << std::endl;
    this->array = new T[obj.n];
    for (unsigned int i = 0; i < obj.n; ++i) {
        this->array[i] = obj.array[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        delete[] this->array;
        this->n = obj.n;
        this->array = new T[obj.n];
        for (unsigned int i = 0; i < obj.n; ++i) {
            this->array[i] = obj.array[i];
        }
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= this->n)
        throw std::out_of_range("Index out of range");
    return this->array[i];
}

template<typename T>
unsigned int Array<T>::size() const {
    return n;
}