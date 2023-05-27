NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -std=c++98
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
