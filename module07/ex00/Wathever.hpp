#ifndef WATHEVER_HPP
#define WATHEVER_HPP

template <class myType>
void swap (myType &a, myType &b) {
    myType c = a;
    a = b;
    b = c;
}
template <class myType>
myType min (myType a, myType b) {
    return (a<b?a:b);
}
template <class myType>
myType max (myType a, myType b) {
    return (a>b?a:b);
}

#endif