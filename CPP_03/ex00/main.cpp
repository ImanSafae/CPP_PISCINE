/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:04:11 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/17 17:11:01 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	unknown;
	ClapTrap	MrGutsy("Mr Gutsy");
	ClapTrap	anotherGutsy(MrGutsy);
	ClapTrap	PrimmSlim("Primm Slim");
	std::cout << std::endl;
	
	MrGutsy.attack(PrimmSlim.getName());
	PrimmSlim.takeDamage(MrGutsy.getDamage());
	std::cout << "ClapTrap " << PrimmSlim.getName() << " now has " << PrimmSlim.getHitPoints() << " hit point(s)." << std::endl;
	
	std::cout << std::endl;
	PrimmSlim.beRepaired(1);
	std::cout << "ClapTrap " << PrimmSlim.getName() << " now has " << PrimmSlim.getHitPoints() << " hit point(s)." << std::endl;
	std::cout << std::endl;
}