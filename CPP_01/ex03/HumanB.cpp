/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:53:33 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/07 15:52:58 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

HumanB::HumanB( std::string name )
{
	this->_name = name;
	this->_my_weapon = nullptr;
	return ;
}

HumanB::~HumanB( void )
{
	return ;
}

// ************************************************************************** //
//                                 Attack                                     //
// ************************************************************************** //

void	HumanB::attack( void )
{
	std::string	weapon;

	weapon = _my_weapon->getType();
	if (!weapon.compare(""))
		std::cout << this->_name << " can't attack without a weapon." <<std::endl;
	else
		std::cout << this->_name << " attacks with their " << weapon << std::endl;
}

// ************************************************************************** //
//                                  Accessors                                 //
// ************************************************************************** //

void	HumanB::setName( std::string name )
{
	this->_name = name;
}

std::string	HumanB::getName( void )
{
	return this->_name;
}

void	HumanB::setWeapon( Weapon &type )
{
	this->_my_weapon = &type;
}

Weapon	HumanB::getWeapon( void )
{
	return *(this->_my_weapon);
}
