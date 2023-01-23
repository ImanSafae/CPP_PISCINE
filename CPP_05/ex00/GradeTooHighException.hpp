#pragma once

#include "Bureaucrat.hpp"

class GradeTooHighException : public std::exception
{
public:
	GradeTooHighException( void ) throw();
	GradeTooHighException( std::string const message ) throw();
	virtual ~GradeTooHighException( void ) throw();

	virtual const char  *what( void ) const throw();

private:
	std::string _message;
};
