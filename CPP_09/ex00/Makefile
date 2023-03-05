NAME = btc
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
SRCS = 		main.cpp \
			BitcoinExchange.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
