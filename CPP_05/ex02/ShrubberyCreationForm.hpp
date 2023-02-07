#pragma once

#include "Form.hpp"

class   ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm const &src );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm &operator=( ShrubberyCreationForm const &src );

	virtual void	beSigned( Bureaucrat &employee );
private:
};