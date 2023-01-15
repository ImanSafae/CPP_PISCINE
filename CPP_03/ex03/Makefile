NAME = DiamondTrap
CC = c++
FLAGS = -Wall -Wextra -Werror -Wshadow

SRCS = ClapTrap.cpp DiamondTrap.cpp FragTrap.cpp main.cpp ScavTrap.cpp
all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
