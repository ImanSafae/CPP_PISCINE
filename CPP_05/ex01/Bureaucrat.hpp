#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include "Form.hpp"

// #include "GradeTooHighException.hpp"
// #include "GradeTooLowException.hpp"

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

	void			signForm( Form &form );

	class	GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException( void ) throw();
		GradeTooHighException( std::string const message ) throw();
		virtual ~GradeTooHighException( void ) throw();

		virtual const char  *what( void ) const throw();

	private:
		std::string _message;
	};

	class	GradeTooLowException  : public std::exception
	{
	public:
		GradeTooLowException( void ) throw();
		GradeTooLowException( std::string const message ) throw();
		virtual ~GradeTooLowException() throw();

		virtual const char  *what( void ) const throw();

	private:
		std::string _message;
	};

private:
	const std::string	_name;
	unsigned int		_grade;
};

	std::ostream	&operator<<( std::ostream &o, Bureaucrat const &output );