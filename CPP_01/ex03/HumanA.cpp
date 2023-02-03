/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:53:50 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/07 15:37:03 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

HumanA::HumanA( std::string name, Weapon &type ) : _my_weapon(type)
{
	// this->_my_weapon = type;
	// setWeapon(type);
	setName(name);
	return ;
}

HumanA::~HumanA( void )
{
	return ;
}

// ************************************************************************** //
//                                 Attack                                     //
// ************************************************************************** //

void	HumanA::attack( void )
{
	std::string	weapon;

	weapon = _my_weapon.getType();
	std::cout << this->_name << " attacks with their " << weapon << std::endl;
}


// ************************************************************************** //
//                                  Accessors                                 //
// ************************************************************************** //

void	HumanA::setName( std::string name )
{
	this->_name = name;
}

std::string	HumanA::getName( void )
{
	return this->_name;
}

void	HumanA::setWeapon( Weapon type )
{
	this->_my_weapon = type;
}

Weapon	HumanA::getWeapon( void )
{
	return this->_my_weapon;
}
