#include "Borderlands.hpp"

int Borderlands::_x = 0;
int Borderlands::_size = 10;

Borderlands::Borderlands() {

    _borderlands = new ClapTrap *[10];
    std::cout << "Borderlands : Default Constructor Called" << std::endl;
}

Borderlands::~Borderlands() {
    delete[] _borderlands;
    std::cout << "Borderlands : Destructor Called" << std::endl;
}

Borderlands::Borderlands(Borderlands const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj)
        *this = obj;
}



void Borderlands::setX(int x) {
    _x += x;
}


void Borderlands::checkResizeArray() {
    int newsize;
    newsize = _size + _size / 2;
    if (_x == _size) {
        ClapTrap **temp = new ClapTrap* [newsize];
        for (int i = 0; i < _size; i++) {
            temp[i] = getBorderlands(i);
        }
        delete[] _borderlands;
        _borderlands = temp;
        delete[] temp;
    }
}

Borderlands &Borderlands::operator=(const Borderlands &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}

void Borderlands::fillArray(ClapTrap *clapTrap) {
    this->_borderlands[_x] = clapTrap;
//    setBorderlands(clapTrap);
    _x += 1;
//    setX(1);
    std::cout<<std::endl<<"XXXXXXXX "<<_x<<std::endl<<std::endl;
}

void Borderlands::setSize(int size) {
    _size = size;
}

//void Borderlands::setBorderlands(ClapTrap *borderlands) {
//    _borderlands = borderlands;
//}

ClapTrap *Borderlands::getBorderlands(int i) {
    return _borderlands[i];
}
