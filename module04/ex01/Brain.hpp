#ifndef _Brain_HPP_
#define _Brain_HPP_

#include <iostream>

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Brain {
public    :
    Brain();

    Brain(Brain const &obj);

    ~Brain();

    Brain &operator=(const Brain &obj);

    int getIndex() const;

    void setIndex(int index);
    void setIdea(std::string idea,int index);
    std::string getIdea(int index);
private    :
    std::string _ideas[100];
    int _index;
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
