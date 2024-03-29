/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:16:37 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/26 17:38:30 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// ************************************************************************** //
//                              Bureaucrat class                              //
// ************************************************************************** //

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) throw () {}

Bureaucrat::GradeTooHighException::GradeTooHighException( std::string message ) throw() : _message(message) {}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return (this->_message.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw () {}

// ************************************************************************** //
//                                 Form class                                 //
// ************************************************************************** //

Form::GradeTooHighException::GradeTooHighException( void ) throw () {}

Form::GradeTooHighException::GradeTooHighException( std::string message ) throw() : _message(message) {}

const char	*Form::GradeTooHighException::what( void ) const throw()
{
	return (this->_message.c_str());
}

Form::GradeTooHighException::~GradeTooHighException( void ) throw () {}
