#ifndef _MateriaSource_HPP_
#define _MateriaSource_HPP_

#include <iostream>
#include "IMateriaSource.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class MateriaSource : public IMateriaSource{
public    :
    MateriaSource();

    MateriaSource(MateriaSource const &obj);

    ~MateriaSource();

    MateriaSource &operator=(const MateriaSource &obj);

    void learnMateria(AMateria *matery) ;

    AMateria *createMateria(const std::string &type) ;

private    :
    AMateria *materia[4];
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
