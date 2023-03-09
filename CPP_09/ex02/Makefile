NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -std=c++98 -fsanitize=address -g
SRCS = 		main.cpp \
			PmergeMe.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
