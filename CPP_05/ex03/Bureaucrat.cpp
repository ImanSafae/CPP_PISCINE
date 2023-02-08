/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:59:39 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/26 18:34:25 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Bureaucrat::Bureaucrat( void )
{
	std::cout << "You just hired a new Bureaucrat." << std::endl;
	this->setGrade(150);
}

Bureaucrat::Bureaucrat( unsigned int grade, std::string name ) : _name(name)
{
	// throw exception if grade isn't between 1 and 150
	std::cout << "You just hired a new Bureaucrat named " << name << ".";
	try
	{
		this->_grade = grade;
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException("Grade cannot be higher than 1.");
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException("Grade cannot be lower than 150.");
		std::cout << " Grade: " << grade << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << "Exception caught: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const &src )
{
	this->setGrade(src.getGrade());
	std::cout << "Another Bureaucrat of grade " << src.getGrade() << " just joined your ranks." << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "A Bureaucrat left the company." << std::endl;
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade( unsigned int grade )
{
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade( void )
{
	try
	{
		if (this->_grade == 1)
			throw Bureaucrat::GradeTooHighException("Cannot raise grade above #1.");
		(this->_grade)--;
		std::cout << "Bureaucrat has been promoted to grade " << this->getGrade() << "." << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade( void )
{
	try
	{
		if (this->_grade == 150)
			throw Bureaucrat::GradeTooLowException("Cannot lower grade below #150.");
		(this->_grade)++;
		std::cout << "Bureaucrat has been downgraded to grade " << this->getGrade() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

void			Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << this->_name << " signed form " << form.getName() << "." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << this->_name << " couldn't sign form " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void			Bureaucrat::executeForm( Form const &form )
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << this->_name << " executed " << form.getName() << "." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << this->_name << " couldn't sign form " << form.getName() << " : " << e.what() << std::endl;
	}
}

// ************************************************************************** //
//						   Operator overload								  //
// ************************************************************************** //

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &src )
{
	this->_grade = src.getGrade();
	return (*this);
}

std::ostream	&operator<<( std::ostream &o, Bureaucrat const &employee )
{
	o << employee.getName() << ", bureaucrat grade " << employee.getGrade() << "." << std::endl;
	return (o);
}
