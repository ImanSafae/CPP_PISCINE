NAME = horde
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

SRCS =	zombieHorde.cpp \
		Zombie.cpp \
		main.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) 

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
