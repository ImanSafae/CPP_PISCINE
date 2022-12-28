NAME = violence
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS =	main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp 

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) 

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
