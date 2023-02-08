#pragma once

#include "Form.hpp"
#include <cstdio>
#include <iostream>
#include <fstream>

class	ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm const &src );
	ShrubberyCreationForm( std::string target );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm &operator=( ShrubberyCreationForm const &src );

	virtual void	beSigned( Bureaucrat &employee );

	std::string		getTarget( void ) const;

	virtual void	action( void ) const;
private:
	std::string _target;
};
