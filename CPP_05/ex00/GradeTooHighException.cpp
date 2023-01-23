/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:16:37 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/23 16:08:09 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) throw () {}

Bureaucrat::GradeTooHighException::GradeTooHighException( std::string message ) throw() : _message(message) {}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return (this->_message.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw () {}