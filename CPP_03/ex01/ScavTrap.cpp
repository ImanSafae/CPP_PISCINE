/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:22:42 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/14 20:27:37 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

ScavTrap::ScavTrap( void )
{
	std::cout << "More specifically, a ScavTrap!" << std::endl;
	this->initStats(SCAVTRAP);
	// this->setHitPoints(100);
	// this->setEnergy(50);
	// this->setDamage(20);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap " << this->_name << " despawning..." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &src )
{
	std::cout << "New copy of ScavTrap";
	if (src.getName() != "")
		std::cout << " " << src.getName();
	std::cout << " is being created..." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergy(src.getEnergy());
	this->setDamage(src.getDamage());
}

ScavTrap::ScavTrap( std::string name )
{
	std::cout << "More specifically, a ScavTrap named "  << name << " !" << std::endl;
	this->setName(name);
	this->initStats(SCAVTRAP);
	// this->setHitPoints(100);
	// this->setEnergy(50);
	// this->setDamage(20);
}

// ************************************************************************** //
//                                  Actions                                   //
// ************************************************************************** //

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap has entered gatekeeper mode." << std::endl;
}

void	ScavTrap::attack( const std::string &target )
{
	std::cout << target << " approached the gate too close and ScavTrap got mad. " << std::endl;
	std::cout << target << " is attacked, taking " << this->_damage << " points of damage..." << std::endl;
}

// ************************************************************************** //
//                           Operator overload                                //
// ************************************************************************** //

ScavTrap	& ScavTrap::operator=( ScavTrap const &src )
{
	this->_damage = src.getDamage();
	this->_energyPoints = src.getEnergy();
	this->_hitPoints = src.getHitPoints();
	this->_name = src.getName();
	return (*this);
}
