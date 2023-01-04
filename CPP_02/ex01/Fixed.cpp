/* ************************************************************************** */
/*																			  */
/*						                                :::      ::::::::     */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:15:34 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/04 01:18:31 by itaouil          ###   ########.fr       */
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

Fixed::Fixed( Fixed const &src )
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed( int const number )
{
	std::cout << "Int constructor called." << std::endl;
	// this->_value = (number * pow(2, this->_precision));
	this->_value = number << this->_precision;
}

Fixed::Fixed( float const number )
{
	std::cout << "Float constructor called." << std::endl;
	this->_value = roundf(number * (1 << this->_precision));
}

// ************************************************************************** //
//						   Operator overload								  //
// ************************************************************************** //

std::ostream	&operator<<( std::ostream &output, Fixed const &number )
{
	output << number.toFloat();
	return (output);
}

Fixed &	Fixed::operator=( Fixed const &newValue )
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->_value = newValue.getRawBits();
	return (*this);
}

// ************************************************************************** //
//								 Accessors								      //
// ************************************************************************** //

int		Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int raw )
{
	this->_value = raw;
}

// ************************************************************************** //
//								 Converters								      //
// ************************************************************************** //

float	Fixed::toFloat( void ) const
{
	float	floatVersion;

	// floatVersion = (this->_value) * pow(2, this->_precision * (-1));
	floatVersion = ((float) this->_value) / (1 << (this->_precision));
	return (floatVersion);
}

int		Fixed::toInt( void ) const
{
	int	intVersion;

	// intVersion = (this->_value) * pow(2, this->_precision * (-1));
	intVersion = ((this->_value) >> (this->_precision));
	return (intVersion);
}
