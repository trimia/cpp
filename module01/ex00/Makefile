
#SET
EXE		=	BraiiiiiiinnnzzzZ
SRC		=	Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJ		=	$(SRC:.cpp=.o)
CC		=	c++
FLAGS	= 	-Wall -Wextra -Werror -std=c++98

#COLORS
RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
RED 			= 	\033[38;5;160m

#RULES
all: $(EXE)

%.o: %.cpp
	@echo "Compiling... $(GREEN)$<$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

$(EXE): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(EXE)
	@echo "$(GREEN)Program ready!$(RESET)\n"
	@echo "Use $(GREEN)leaks -atExit -- ./$(EXE)$(RESET) to test!"

clean:
	@/bin/rm -f $(OBJ)
	@echo "$(RED)Object files removed!$(RESET)"

fclean: clean
	@/bin/rm -f $(EXE)
	@echo "$(RED)Exe files removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re