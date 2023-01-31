NAME = Bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
SRCS = 	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		GradeTooHighException.cpp \
		GradeTooLowException.cpp \
		ShrubberyCreationForm.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
