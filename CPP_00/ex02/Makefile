NAME = globalbanksters
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

SRCS = 	Account.cpp \
		tests.cpp 

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) 

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
