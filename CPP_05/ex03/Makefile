NAME = Bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
SRCS = 	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		FormNotSignedException.cpp \
		GradeTooHighException.cpp \
		GradeTooLowException.cpp \
		Intern.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
