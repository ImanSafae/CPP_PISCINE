#pragma once

#include "Bureaucrat.hpp"

class GradeTooLowException : public std::exception
{
public:
	GradeTooLowException( void ) throw();
	GradeTooLowException( std::string const message ) throw();
	virtual ~GradeTooLowException() throw();

	virtual const char  *what( void ) const throw();

private:
	std::string _message;
};
