NAME = AMateria 

CXXFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = c++ 

STD = -std=c++98 

SRC = AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp main.cpp

INC = AMateria.hpp Cure.hpp Ice.hpp Character.hpp MateriaSource.hpp IMateriaSource.hpp ICharacter.hpp

OBJ = $(SRC:.cpp=.o) 

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(CXXFLAGS) $(STD) $(OBJ) -o $(NAME) 

%.o : %.cpp $(INC)
	$(CC) $(CXXFLAGS) -c $< -o $@ 

clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME) 

re : fclean all 

.PHONY : all clean fclean re
