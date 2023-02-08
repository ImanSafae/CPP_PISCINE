/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:32:57 by itaouil           #+#    #+#             */
/*   Updated: 2023/02/07 15:32:57 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Intern::Intern( void )
{
	std::cout << "New intern just joined the company." << std::endl;
	this->_status = "Intern";
}

Intern::Intern( Intern const &src )
{
	std::cout << "New intern just joined the company." << std::endl;
	this->_status = src.getStatus();
}

Intern::~Intern( void )
{
	std::cout << "An intern left the company." << std::endl;
}

// ************************************************************************** //
//                              Operator Overload                             //
// ************************************************************************** //

Intern	&Intern::operator=( Intern const &src )
{
	this->_status = src.getStatus();
	return (*this);
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

std::string	Intern::getStatus( void ) const
{
	return (this->_status);
}

// ************************************************************************** //
//                                  Actions                                   //
// ************************************************************************** //

void	tolower_str( std::string &str )
{
	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = tolower(str[i]);
	}
}

Form	*Intern::createShrubberyForm( std::string target )
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::createPresidentialForm( std::string target )
{
	return (new PresidentialPardonForm(target));
}

Form	*Intern::createRobotomyForm( std::string target )
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makeForm( std::string formtype, std::string target )
{
	Form	*newform;
	tolower_str(formtype);

	std::string	forms[3];
	forms[0] = "presidential pardon";
	forms[1] = "robotomy request";
	forms[2] = "shrubbery creation";

	Form*	(Intern::*functionsArray[3])( std::string target );
	functionsArray[0] = &Intern::createPresidentialForm;
	functionsArray[1] = &Intern::createRobotomyForm;
	functionsArray[2] = &Intern::createShrubberyForm;

	int	index = -1;
	for (int i = 0; i < 3; i++)
	{
		if (!formtype.compare(forms[i]))
		{
			index = i;
			break ;
		}
	}
	if (index == -1)
	{
		std::cout << "Unrecognized form name. Intern couldn't create form." << std::endl;
		return (NULL);
	}
	newform = (this->*functionsArray[index])(target);
	return (newform);
}
