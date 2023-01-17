NAME = Animals
CC = c++
FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
SRCS = 	main.cpp \
		Animals.cpp \
		Brain.cpp
		# WrongAnimals.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
