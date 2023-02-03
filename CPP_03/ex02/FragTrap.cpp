/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:20:08 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/17 17:25:08 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

FragTrap::FragTrap( void )
{
	std::cout << "Congratulations! Your ClapTrap is a FragTrap." << std::endl;
	this->initStats(FRAGTRAP);
}

FragTrap::FragTrap( std::string name )
{
	std::cout << "Category: FragTrap. Name: " << name << "." << std::endl;
	this->setName(name);
	this->initStats(FRAGTRAP);
}

FragTrap::FragTrap( FragTrap const &src )
{
	std::cout << "Your FragTrap " << src.getName() << " now has a twin!" << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergy(src.getEnergy());
	this->setDamage(src.getDamage());
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap's job here is done." << std::endl;
}

// ************************************************************************** //
//                                   Utils                                    //
// ************************************************************************** //

void	str_lower(std::string &str)
{
	unsigned int i = 0;
	while (i < str.size())
	{
		if (str[i] <= 90 && str[i] >= 65)
			str[i] = (char)tolower(str[i]);
		i++;
	}
}

// ************************************************************************** //
//                                  Actions                                   //
// ************************************************************************** //

void	FragTrap::highFivesGuys( void )
{
	std::string answer;

	std::cout << "FragTrap asks: < Will you high five me ? uwu 👉👈 >" << std::endl;
	std::cin >> answer;
	str_lower(answer);

	if (!answer.compare("yes"))
		std::cout << "A [^_^] face appeared on the FragTrap's screen. It's very happy to high five you. [yes/no]" << std::endl;
	else if (!answer.compare("no"))
		std::cout << "A [╥_╥] face appeared on the FragTrap's screen. You made it sad!" << std::endl;
	else
		std::cout << "A [゜-゜] face appeared on the FragTrap's screen. I don't think it understood what you said." << std::endl;
}

// ************************************************************************** //
//                           Operator overload                                //
// ************************************************************************** //

FragTrap	& FragTrap::operator=( FragTrap const &src )
{
	this->_damage = src.getDamage();
	this->_energyPoints = src.getEnergy();
	this->_hitPoints = src.getHitPoints();
	this->_name = src.getName();
	return (*this);
}
