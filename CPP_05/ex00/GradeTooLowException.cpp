/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:13:59 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/23 01:26:42 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException( std::string message ) throw() : _message(message) {}

const char	*GradeTooLowException::what( void ) const throw()
{
	return (this->_message.c_str());
}
