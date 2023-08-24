NAME = DiamondTrap

CXXFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

CC = c++ 

STD = -std=c++98 

SRC =  ClapTrap.cpp Borderlands.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp

INC = ClapTrap.hpp Borderland.hpp ScavTrap.hpp Fragtrap.hpp DiamondTrap.hpp

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
