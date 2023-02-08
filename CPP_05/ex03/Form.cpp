/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:48:28 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/26 18:27:22 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Form::Form( void ) : _gradeToSign(20), _gradeToExecute(50)
{
	this->_isSigned = false;
	std::cout << "New standard form just popped on your desk." << std::endl;
}

Form::Form( std::string name, unsigned int execGrade, unsigned int signGrade ) : _name(name), _gradeToSign(signGrade), _gradeToExecute(execGrade)
{
	this->_isSigned = false;
	std::cout << "New form just popped on your desk." << std::endl;
	std::cout << *this << std::endl;
	try
	{
		if (execGrade > 150)
			throw Form::GradeTooLowException("Warning! There are no grades below 150!");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

Form::Form( Form const &src ) : _name(src.getName()), _gradeToSign(src.getSignGrade()), _gradeToExecute(src.getExecGrade())
{
	this->_isSigned = false;
	std::cout << "A form got duplicated." << std::endl;
	std::cout << *this << std::endl;
}

Form::~Form( void )
{
	std::cout << "Deleted form." << std::endl;
}

// ************************************************************************** //
//						   Operator overload								  //
// ************************************************************************** //

Form	&Form::operator=( Form const &src )
{
	this->_isSigned = src.getSignedStatus();
	return (*this);
}

std::ostream	&operator<<( std::ostream &o, Form const &output )
{
	std::string	status;

	if (output.getSignedStatus() == true)
		status = "signed.";
	else
		status = "not signed.";
	o << "Form details:" << std::endl << "Name: " << output.getName() << std::endl;
	o << "Required grade to sign: " << output.getSignGrade() << std::endl;
	o << "Required grade to execute: " << output.getExecGrade() << std::endl;
	o << "Status: " << status << std::endl;
	return (o);
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

std::string	Form::getName( void ) const
{
	return (this->_name);
}

bool	Form::getSignedStatus( void ) const
{
	return (this->_isSigned);
}

unsigned int	Form::getExecGrade( void ) const
{
	return (this->_gradeToExecute);
}

unsigned int	Form::getSignGrade( void ) const
{
	return (this->_gradeToSign);
}

// ************************************************************************** //
//                                  Actions                                   //
// ************************************************************************** //

void			Form::beSigned( Bureaucrat &employee )
{
	// try
	// {
		if (employee.getGrade() > this->_gradeToSign)
		{
			std::string s = "Employee's grade is too low to sign this form. Required grade : ";
			std::stringstream	out;
			out << this->_gradeToSign;
			s.append(out.str());
			throw Bureaucrat::GradeTooLowException(s);
		}
		else
			this->_isSigned = true;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Exception caught: " << e.what() << std::endl;
	// }
}

void		Form::execute( const Bureaucrat &executor ) const
{
	if (executor.getGrade() > this->_gradeToExecute)
	{
		std::string s = "Employee's grade is too low to execute this form. Required grade : ";
		std::stringstream	out;
		out << this->_gradeToExecute;
		s.append(out.str());
		throw Bureaucrat::GradeTooLowException(s);
	}
	else if (this->_isSigned == false)
	{
		std::string	s = "Form can't be executed if not signed.";
		throw Form::FormNotSignedException(s);
	}
	else
		this->action();
}
