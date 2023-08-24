
#SET
EXE		=	Sed_is_for_losers
SRC		=	main.cpp #Sed.cpp
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
	@echo "Use $(GREEN)leaks -atExit -- ./$(EXE)$(RESET) and $(GREEN)[filename] [string_1] [string_2]$(RESET) to test!"

clean:
	@/bin/rm -f $(OBJ)
	@echo "$(RED)Object files removed!$(RESET)"

fclean: clean
	@/bin/rm -f $(EXE)
	@echo "$(RED)Exe files removed!$(RESET)"
	rm -f file.replace

re: fclean all

.PHONY: all clean fclean re
