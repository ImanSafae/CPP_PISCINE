/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:21:12 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/17 17:21:56 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap	Frag("Frag");

	std::cout << std::endl;
	Frag.attack("You");

	std::cout << std::endl;
	Frag.highFivesGuys();

	std::cout << std::endl;
}