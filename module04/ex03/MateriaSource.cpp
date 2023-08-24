#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i=0;i<4;i++)
        materia[i]=NULL;
	std::cout << "MateriaSource : Default Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource : Destructor Called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

MateriaSource	&MateriaSource::operator= (const MateriaSource &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
        for (int i = 0; i < 4; i++)
        {
            if (materia[i])
            {
                delete materia[i];
                materia[i] = NULL;
            }
            materia[i] = obj.materia[i]->clone();
        }
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *matery) {
    for(int i = 0; i < 4; i++)
    {
        if(!materia[i])
        {
            materia[i] = matery->clone();
            std::cout << "Materia " + matery->getType() + " has been learned at index: " << i << std::endl;
            if (matery)
                delete matery;
            return;
        }
    }
    if (matery)
        delete matery;
    std::cout << "Full slots" << std::endl;

}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < 4; i++)
        if(materia[i] && materia[i]->getType() == type)
            return (materia[i]);
    return nullptr;
//    return NULL;
}
