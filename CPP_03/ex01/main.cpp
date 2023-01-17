/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:21:12 by itaouil           #+#    #+#             */
/*   Updated: 2023/01/17 17:20:56 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	Scav("Scav");
	std::cout << std::endl;

	Scav.attack("You");
	std::cout << std::endl;

	Scav.guardGate();
	std::cout << std::endl;
}
