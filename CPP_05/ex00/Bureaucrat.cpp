/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:59:39 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/22 21:17:29 by itaouil          ###   ########.fr       */
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
			throw std::string("Cannot raise grade above #1.");
		(this->_grade)--;
	}
	catch(const std::string &s)
	{
		std::cerr << s << std::endl;
	}
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}

void	Bureaucrat::decrementGrade( void )
{
	try
	{
		if (this->_grade == 150)
			throw std::string("Cannot lower grade below #150.");
		(this->_grade)++;
	}
	catch(const std::string &s)
	{
		std::cerr << s << std::endl;
	}
	// catch()
	// {
	// 	std::cerr << e.what() << '\n';
	// }
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
