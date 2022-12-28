/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:21:45 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/12 19:00:48 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main()
{
	std::cout << "Creating Bob & Patrick..." << std::endl;
	Zombie		Bob;
	Zombie		Patrick = Zombie("Patrick");
	std::cout << std::endl;

	std::cout << "Creating horde of Sandy's..." << std::endl;
	Zombie	*horde = zombieHorde(6, "Sandy");
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		(horde[i]).announce();
	std::cout << std::endl;

	std::cout << "Deleting horde of Sandy's..." << std::endl;
	delete [] horde;
	std::cout << std::endl;

	std::cout << "Exiting..." << std::endl;
}
