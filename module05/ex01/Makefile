NAME = Bureaucrat

CXXFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = c++ 

STD = -std=c++98 

SRC = Bureaucrat.cpp Form.cpp main.cpp

INC = Bureaucrat.hpp Form.hpp

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
