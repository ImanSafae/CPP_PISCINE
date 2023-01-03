/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:29:47 by itaouil           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/30 19:01:23 by itaouil          ###   ########.fr       */
=======
/*   Updated: 2022/12/31 23:49:32 by itaouil          ###   ########.fr       */
>>>>>>> d34c7e0e1fc3e952265af8250d673c299b085063
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

<<<<<<< HEAD
int			Fixed::getRawBits( void ) const
=======
// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

int		Fixed::getRawBits( void ) const
>>>>>>> d34c7e0e1fc3e952265af8250d673c299b085063
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_value);
}

void		Fixed::setRawBits( int raw )
{
	this->_value = raw;
}
