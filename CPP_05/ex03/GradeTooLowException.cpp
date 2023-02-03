/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:13:59 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/26 17:38:41 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// ************************************************************************** //
//                              Bureaucrat class                              //
// ************************************************************************** //

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) throw () {}

Bureaucrat::GradeTooLowException::GradeTooLowException( std::string message ) throw() : _message(message) {}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return (this->_message.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw () {}

// ************************************************************************** //
//                                 Form class                                 //
// ************************************************************************** //


Form::GradeTooLowException::GradeTooLowException( void ) throw () {}

Form::GradeTooLowException::GradeTooLowException( std::string message ) throw() : _message(message) {}

const char	*Form::GradeTooLowException::what( void ) const throw()
{
	return (this->_message.c_str());
}

Form::GradeTooLowException::~GradeTooLowException( void ) throw () {}
