struct Data {
    int value;
};

#include <stdint.h>

class Serializer {
public:
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }
};

#include <iostream>
#include "include.h"

//int main() {
//    Data myData;
//    myData.value = 42; // Assign a value to demonstrate it's non-empty
//
//    uintptr_t serializedData = Serializer::serialize(&myData);
//    Data* deserializedData = Serializer::deserialize(serializedData);
//
//    if (&myData == deserializedData) {
//        std::cout << "Success: The original and deserialized pointers are equal." << std::endl;
//        std::cout << "Data value: " << deserializedData->value << std::endl;
//    } else {
//        std::cout << "Error: The pointers do not match." << std::endl;
//    }
//
//    return 0;
//}


int main()
{
    std::cout << std::endl;
    std::cout << GREEN << "**** Constructor ****" << NONE << std::endl << std::endl;
    Data*		data = new Data;
    data->value = 42;
    uintptr_t	uint = Serializer::serialize(data);
    Data		*data2 = Serializer::deserialize(uint);

    std::cout << std::endl << CYAN << "**** Info ****  " << NONE << std::endl << std::endl;
    std::cout << data << std::endl;
    std::cout << uint << std::endl;
    std::cout << data2 << std::endl;

    std::cout << std::endl << CYAN << "**** Testing ****  " << NONE << std::endl << std::endl;
    std::cout << Serializer::serialize(data) << std::endl;
    std::cout << Serializer::deserialize(uint) << std::endl;
    std::cout << Serializer::serialize(data2) << std::endl;
    std::cout << std::endl << RED << "**** Decostructor ****  " << NONE << std::endl << std::endl;
    delete data;
    std::cout << std::endl;
    return 0;
}