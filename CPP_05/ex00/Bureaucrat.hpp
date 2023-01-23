#pragma once

#include <iostream>
#include <exception>

#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat
{

public:
	Bureaucrat( void );
	Bureaucrat( Bureaucrat const &src );
	Bureaucrat( unsigned int grade, std::string name );
	~Bureaucrat( void );

	Bureaucrat 		&operator=( Bureaucrat const &src );

	std::string		getName( void ) const;
	unsigned int	getGrade( void ) const;
	void			setGrade( unsigned int grade );
	void			incrementGrade( void );
	void			decrementGrade( void );

	GradeTooHighException	GradeTooHigh();
	GradeTooLowException	GradeTooLow();

private:
	const std::string	_name;
	unsigned int		_grade;
};

	std::ostream	&operator<<( std::ostream &o, Bureaucrat const &output );