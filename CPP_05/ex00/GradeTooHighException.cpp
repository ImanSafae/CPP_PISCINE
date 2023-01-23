/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:16:37 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/23 01:26:53 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException( std::string message ) throw() : _message(message) {}

const char	*GradeTooHighException::what( void ) const throw()
{
	return (this->_message.c_str());
}
