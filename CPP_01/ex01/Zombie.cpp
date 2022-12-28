/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:21:39 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/12 01:42:53 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

Zombie::Zombie( void ) // default constructor
{
	std::cout << "New zombie just dropped." << std::endl;
}

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << _name << " spawned." << std::endl;
}

Zombie::~Zombie( void )
{
	if (!_name.compare(""))
		std::cout << "Nameless zombie died." << std::endl;
	else
		std::cout << _name << " died." << std::endl;
}

// ************************************************************************** //
//                                  Accessor                                  //
// ************************************************************************** //

void	Zombie::announce( void )
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}
