NAME = ScavTrap
CC = c++
FLAGS = -Wall -Wextra -Werror

SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp
all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
