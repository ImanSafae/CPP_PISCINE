/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:53:58 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/07 01:02:38 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

ClapTrap::ClapTrap( void )
{
	std::cout << "New ClapTrap spawned." << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Goodbye little ClapTrap!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name)
{
	std::cout << "New ClapTrap named " << name << " just spawned." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &src )
{
	std::cout << "Another ClapTrap named " << src.getName() << " just spawned." << std::endl;
	this->_name = src.getName();
	this->setDamage(src.getDamage());
	this->setEnergy(src.getEnergy());
	this->setHitPoints(src.getHitPoints());
}

// ************************************************************************** //
//                           Operator overload                                //
// ************************************************************************** //

ClapTrap	& ClapTrap::operator=( ClapTrap const &src )
{
	this->_damage = src.getDamage();
	this->_energyPoints = src.getEnergy();
	this->_hitPoints = src.getHitPoints();
	this->_name = src.getName();
	return (*this);
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

void		ClapTrap::decreaseEnergy( void )
{
	if (this->_energyPoints > 0)
		this->_energyPoints -= 1;
}

int			ClapTrap::getEnergy( void ) const
{
	return (this->_energyPoints);
}

int			ClapTrap::getHitPoints( void ) const
{
	return (this->_hitPoints);
}

int			ClapTrap::getDamage( void ) const
{
	return (this->_damage);
}

void		ClapTrap::setDamage( unsigned int amount )
{
	this->_damage = amount;
}

void		ClapTrap::setEnergy( unsigned int amount )
{
	this->_energyPoints = amount;
}

void		ClapTrap::setHitPoints( unsigned int amount )
{
	this->_hitPoints = amount;
}

void		ClapTrap::setName( std::string name )
{
	this->_name = name;
}

// ************************************************************************** //
//                                  Actions                                   //
// ************************************************************************** //

void	ClapTrap::attack( const std::string &target )
{
	if (this->_energyPoints)
	{
		if (this->_name == "")
			std::cout << "Nameless ClapTrap";
		else
			std::cout << "ClapTrap " << this->_name;
		std::cout << " attacks " << target << ", causing " << this->_damage << " points of damage!" <<std::endl;
		this->decreaseEnergy();
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_name == "")
		std::cout << "Nameless ClapTrap";
	else
		std::cout << "ClapTrap " << this->_name;
	std::cout << " is taking " << amount << "damage points!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints)
	{
		if (this->_name == "")
			std::cout << "Nameless ClapTrap";
		else
			std::cout << "ClapTrap " << this->_name;
		std::cout << " repairs itself and gains back " << amount << " hit points!" << std::endl;
		this->_hitPoints += amount;
		this->decreaseEnergy();
	}
}
