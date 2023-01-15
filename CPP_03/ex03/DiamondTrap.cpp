/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:31:36 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/15 21:31:59 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

DiamondTrap::DiamondTrap( void )
{
    std::cout << "Wow ! You found a shiny! This ClapTrap is also DiamondTrap!" << std::endl;
	this->setHitPoints();
	this->setDamage();
	this->setEnergy();
}

DiamondTrap::DiamondTrap( std::string name )
{
	std::cout << "Wow! This ClapTrap is also a DiamondTrap! His Diamond Name is " << name << "." << std::endl;
    this->_name = name;
    ClapTrap::setName(name + "_clap_name");
	this->setHitPoints();
	this->setDamage();
	this->setEnergy();
}

DiamondTrap::DiamondTrap( DiamondTrap const &src )
{
	std::cout << "A new DiamondTrap is being cloned from another." << std::endl;
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergy();
	this->_damage = src.getDamage();
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "The DiamondTrap is leaving to shine somewhere else." << std::endl;
}

// ************************************************************************** //
//                                   Actions                                  //
// ************************************************************************** //

void    DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap introduces itself: < My name is " << this->getName();
	std::cout << " , but my ClapTrap name is " << this->ClapTrap::getName() << ".>" << std::endl;
}

// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

void	DiamondTrap::setDamage( void )
{
	this->_damage = this->FragTrap::getDamage();
}

void	DiamondTrap::setEnergy( void )
{
	this->_energyPoints = this->FragTrap::getEnergy();
}

void	DiamondTrap::setHitPoints( void )
{
	this->_hitPoints = this->FragTrap::getHitPoints();
}

// ************************************************************************** //
//                           Operator overload                                //
// ************************************************************************** //

DiamondTrap	& DiamondTrap::operator=( DiamondTrap const &src )
{
	this->_damage = src.getDamage();
	this->_energyPoints = src.getEnergy();
	this->_hitPoints = src.getHitPoints();
	this->_name = src.getName();
	return (*this);
}
