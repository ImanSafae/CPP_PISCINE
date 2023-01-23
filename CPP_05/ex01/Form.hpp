#pragma once

#include "Bureaucrat.hpp"

class	Form
{

public:
	Form( void );
	Form( Form const &src );
	Form( std::string name, unsigned int execGrade, unsigned int signGrade );
	~Form( void );

	Form	&operator=( Form const &src );

	std::string		getName( void ) const;
	unsigned int	getExecGrade( void ) const;
	unsigned		getSignGrade( void ) const;
	bool			getSignedStatus( void ) const;

	void			beSigned( Bureaucrat const &employee );
	
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
	bool				_isSigned;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;
};

std::ostream	&operator<<( std::ostream &o, Form const &output );
