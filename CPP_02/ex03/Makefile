NAME = Fixed
CC = c++
FLAGS = -Wall -Wextra -Werror

SRCS = 	bsp.cpp Fixed.cpp main.cpp Point.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
