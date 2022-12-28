/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:45:28 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/07 15:54:38 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

int	main()
{
	{
		Weapon	club = Weapon("crude spiked club");
		// Weapon	club("crude spiked club");

		HumanA	bob("bob", club);
		// HumanA	bob = HumanA("bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon	club = Weapon("crude spiked club");

		HumanB jim("jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}