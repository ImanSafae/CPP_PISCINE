/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:14:05 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/03 01:41:36 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Point::Point( void ) : _x(0), _y(0)
{
    std::cout << "Default constructor called." << std::endl;
}

Point::~Point( void )
{
    std::cout << "Destructor called." << std::endl;
}

Point::Point( float const x, float const y ) : _x(x), _y(y)
{
    std::cout << "Float constructor called." << std::endl;
}

Point::Point( Point const &src )
{
    std::cout << "Copy constructor called." << std::endl;
    *this = src;
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

Fixed   Point::getX( void ) const
{
    return (this->_x);
}

Fixed   Point::getY( void ) const
{
    return (this->_y);
}

// ************************************************************************** //
//                             Operator overloads                             //
// ************************************************************************** //

Point   &Point::operator=( Point const &to_assign )
{
    *this = to_assign;
    return (*this);
}
