#pragma once

#include <iostream>
#include <exception>
#include <stdlib.h>
#include <string>
#include <sstream>

class Bureaucrat;

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

	virtual void	beSigned( Bureaucrat &employee ) = 0;
	void			execute( Bureaucrat const &executor) const;

	virtual void	action( void ) const = 0;
	
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

	class FormNotSignedException : public std::exception
	{
	public:
		FormNotSignedException( void ) throw();
		FormNotSignedException( std::string const message ) throw();
		~FormNotSignedException() throw();

	virtual const char  *what( void ) const throw();

	private:
		std::string	_message;
	};
	
protected:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;
};

std::ostream	&operator<<( std::ostream &o, Form const &output );
