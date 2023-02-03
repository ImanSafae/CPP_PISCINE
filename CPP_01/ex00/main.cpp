/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:06:41 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/04 19:54:19 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main()
{
	Zombie *bob = newZombie("Bob");
	bob->announce();

	randomChump("Patrick");
	delete bob;
}
