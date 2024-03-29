/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:21:12 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/17 17:35:51 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	shiny("shiner");

	std::cout << std::endl;
	shiny.attack("Random bot");

	// std::cout << std::endl;
	// shiny.highFivesGuys();

	// std::cout << std::endl;
	// std::cout << "Damage inflicted by " << shiny.getName() << " : " << shiny.getDamage() << std::endl;

	// std::cout << std::endl;
	// std::cout << "Energy of " << shiny.getName() << " : " << shiny.getEnergy() << std::endl;

	// std::cout << std::endl;
	// std::cout << "Life remaining to  " << shiny.getName() << " : " << shiny.getHitPoints() << std::endl;

	std::cout << std::endl;
	// shiny.beRepaired(10);
	shiny.whoAmI();

	std::cout << std::endl;
}