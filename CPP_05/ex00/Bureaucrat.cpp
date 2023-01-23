/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:59:39 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/21 20:53:27 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Bureaucrat::Bureaucrat( void )
{
	std::cout << "You just hired a new Bureaucrat." << std::endl;
	this->setGrade(150);
}

Bureaucrat::Bureaucrat( unsigned int grade, std::string name ) : _grade(grade), _name(name)
{
	// throw exception if grade isn't between 1 and 150
	std::cout << "You just hired a new Bureaucrat. Grade: " << grade << std::endl;
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
			throw std::exception();
		else
			(this->_grade)--;
	}
	catch (std::exception)
	{
		
	}
	// throw error if < 1;
}

void	Bureaucrat::decrementGrade( void )
{
	(this->_grade)++;
	// throw error if > 150;
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
}
