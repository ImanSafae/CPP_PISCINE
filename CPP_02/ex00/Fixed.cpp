/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:29:47 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/04 05:24:27 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Fixed::Fixed( void )
{
	std::cout << "Default constructor called." << std::endl;
	this->setRawBits(0);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed( Fixed const &src )
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
	return ;
}

Fixed &	Fixed::operator=( Fixed const &newValue )
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->_value = newValue.getRawBits();
	return (*this);
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_value);
}

void		Fixed::setRawBits( int raw )
{
	this->_value = raw;
}
