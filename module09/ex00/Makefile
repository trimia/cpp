NAME =btc

CXXFLAGS = -Wall -Wextra -Werror

CC = c++ 

STD = -std=c++98

SRC = main.cpp BitcoinExchange.cpp

INC = BitcoinExchange.hpp

OBJ = $(SRC:.cpp=.o) 

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(CXXFLAGS) $(STD) $(OBJ) -o $(NAME) 

%.o : %.cpp $(INC)
	$(CC) $(CXXFLAGS) $(STD) -c $< -o $@

clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME) 

re : fclean all 

.PHONY : all clean fclean re
